#include "praser.h"
#include <algorithm>
Praser::Praser(ParseTree *root)
{
    this->root = root;
    init();
    cout << "begin praser root" << endl;
    praserParseTree(root);
    cout << "end praser root" << endl;
    codePrinter.printCode();
}
void Praser::init()
{
    block first_block;
    blockStack.push_back(first_block);
    string st = "";
    op_math_map.insert({"MUL_ASSIGN", "*"});
    op_math_map.insert({"DIV_ASSIGN", "/"});
    op_math_map.insert({"MOD_ASSIGN", "%"});
    op_math_map.insert({"ADD_ASSIGN", "+"});
    op_math_map.insert({"SUB_ASSIGN", "-"});
    op_math_map.insert({"LEFT_ASSIGN", "<<"});
    op_math_map.insert({"RIGHT_ASSIGN", ">>"});
    op_math_map.insert({"AND_ASSIGN", "&"});
    op_math_map.insert({"OR_ASSIGN", "|"});
    op_math_map.insert({"XOR_ASSIGN", "^"});
    op_math_map.insert({"GE_OP", ">="});
    op_math_map.insert({"LE_OP", "<="});
    op_math_map.insert({"<", "<"});
    op_math_map.insert({">", ">"});
    op_math_map.insert({"LEFT_OP", "<<"});
    op_math_map.insert({"RIGHT_OP", ">>"});
    op_math_map.insert({"INC_OP", "++"});
    op_math_map.insert({"DEC_OP", "--"});
}
void Praser::praserParseTree(ParseTree *temp_node)
{
    if (temp_node == NULL || temp_node->line < 0)
        return;
    cout << temp_node->name << endl;
    if (temp_node->name == "declaration")
    {
        temp_node = praser_declaration(temp_node);
    }
    else if (temp_node->name == "function_definition")
    {
        temp_node = praser_function_definition(temp_node);
    }
    else if (temp_node->name == "statement")
    {
        temp_node = praser_statement(temp_node);
    }

    if (temp_node != NULL)
    {
        cout << "praser temp_node child" << endl;
        praserParseTree(temp_node->child);
        ParseTree *temp = temp_node->next_sibling;
        while (temp != NULL)
        {
            cout << "praser temp_node sibling" << endl;
            praserParseTree(temp);
            temp = temp->next_sibling;
        }
        //praserParseTree(temp_node->next_sibling);
    }
}
void Praser::praser_parameter_list(ParseTree *node, string funcName, bool definite)
{
    if (node->child->name == "parameter_list")
    {
        praser_parameter_list(node->child, funcName, definite);
    }
    else if (node->child->name == "parameter_declaration")
    {
        praser_parameter_declaration(node->child, funcName, definite);
    }

    if (node->next_sibling != NULL && node->next_sibling->name == ",")
    {
        praser_parameter_declaration(node->next_sibling->next_sibling, funcName, definite);
    }
}

void Praser::praser_parameter_declaration(ParseTree *node, string funcName, bool definite)
{
    ParseTree *declaration_specifier = node->child;    //
    ParseTree *declarator = node->child->next_sibling; //declarator(abstruct_declarator not support)
    ParseTree *type_specifer_or_quality = declaration_specifier->child;
    ParseTree *direct_declarator = NULL;
    string typeName;
    string varName;
    bool isConst = false;
    bool isAddress = false;
    cout << type_specifer_or_quality->name<<endl;
    if (type_specifer_or_quality->name == "type_specifier")
    {
        typeName = type_specifer_or_quality->child->content;
        cout << typeName<<endl;
        if (typeName == "void")
        {
            cout << "Error line:" << type_specifer_or_quality->line << ",void can't definite parameter" << endl;
        }
    }
    else if (type_specifer_or_quality->name == "type_quality")
    {
        string quality = type_specifer_or_quality->name;
        if (quality == "const")
        {
            isConst = true;
        }
        else
        {
            cout << "Error line:" << type_specifer_or_quality->line << ".No such quality" << endl;
        }
        ParseTree *declaration_specifier_new = type_specifer_or_quality->next_sibling;
        if (declaration_specifier_new == NULL)
        {
            cout << "Error line:" << type_specifer_or_quality->line << ",need type define" << endl;
        }
        typeName = declaration_specifier_new->child->name;
    }
    //pointer
    if (declarator->child->name == "pointer")
    {
        direct_declarator = declarator->child->next_sibling;
        isAddress = true;
    }
    else
    {
        direct_declarator = declarator->child;
    }
    //just identifier
    if (direct_declarator->child->name == "IDENTIFIER")
    {
        varName = direct_declarator->child->content;
    }
    //such a[]
    else
    {
        if (direct_declarator->child->next_sibling->name == "[" && direct_declarator->child->next_sibling->next_sibling->name == "]")
        {
            isAddress = true;
        }
        else
        {
            cout << "Error line:" << type_specifer_or_quality->line << ",invalid parameter";
        }
        varName = direct_declarator->child->child->content;
    }

    varNode newnode;
    newnode.name = varName;
    newnode.type = typeName;
    newnode.useAddress = isAddress;
    newnode.isConst = isConst;

    if (definite)
    {
        newnode.count = codePrinter.var_count++;
        blockStack.back()._func.param_list.push_back(newnode);
    }

    func_map[funcName].param_list.push_back(newnode);
    blockStack.back()._var_map.insert({varName, newnode});

    if (definite)
    {
        codePrinter.addCode(codePrinter.createCodeforParameter(newnode));
    }
}

ParseTree *Praser::praser_declaration(ParseTree *node)
{
    ParseTree *declaration_specifiers = node->child;
    if (declaration_specifiers->next_sibling->name == ";")
    {
        return node->next_sibling;
    }
    string vartype = declaration_specifiers->child->child->content;

    if (vartype == "void")
    {
        error(node->line, "void type can't assign to variable"); //报错
    }
    ParseTree *init = declaration_specifiers->next_sibling; //init_declarator_list
    praser_init_declarator_list(vartype, init);
    return node->next_sibling;
}

void Praser::praser_init_declarator_list(string vartype, ParseTree *node)
{
    if (node->child->name == "init_declarator_list")
    {
        praser_init_declarator_list(vartype, node->child);
    }
    else if (node->child->name == "init_declarator")
    {
        praser_init_declarator(vartype, node->child);
    }

    if (node->next_sibling->name == ",")
    {
        praser_init_declarator(vartype, node->next_sibling->next_sibling);
    }
}

/*declarator: 
    pointer direct_declarator {
        $$ = new ParseTree("declarator", 2, $1, $2);
    }
	| direct_declarator {
        $$ = new ParseTree("declarator", 1, $1);
    }
	;
*/
void Praser::praser_init_declarator(string vartype, ParseTree *node)
{
    ParseTree *declarator = node->child;

    if (declarator->next_sibling == NULL)
    {
        ParseTree *direct_declarator = NULL;
        //if is pointer
        if (declarator->child->name == "pointer")
        {
            error(node->line, "do not support pointer");
        }
        else
        {
            direct_declarator = declarator->child;
            //id
            if (direct_declarator->child->name == "IDENTIFIER")
            {

                ParseTree *id = direct_declarator->child;
                string var = id->content;
                if (!lookup_var_in_current_block(var))
                {

                    varNode newvar;
                    newvar.name = var;
                    newvar.type = vartype;
                    newvar.count = codePrinter.var_count++;
                    blockStack.back()._var_map.insert({var, newvar});
                }
                else
                {
                    error(node->line, "Variable multiple declaration.");
                }
            }
            else
            {
                //func
                if (direct_declarator->child->next_sibling->name == "(")
                {
                    string funcName = direct_declarator->child->child->content;
                    string funcType = vartype;
                    //cout <<"Xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
                    if (blockStack.size() > 1)
                    {
                        error(direct_declarator->line, "Function declaration must at global environment.");
                    }
                    ParseTree *parameter_list = direct_declarator->child->next_sibling->next_sibling;
                    //cout << "xxxxxxxxxxxxxxxxxxxxxxx:" + parameter_list->name << endl;
                    funcNode newFunc;
                    newFunc.is_defined = false;
                    newFunc.name = funcName;
                    newFunc.return_type = funcType;
                    func_map.insert({funcName, newFunc});

                    praser_parameter_list(parameter_list, funcName, false);
                }
                //arry
                else if (direct_declarator->child->next_sibling->name == "[")
                {
                    string arrayName = direct_declarator->child->child->content;
                    string arrayType = vartype;
                    ParseTree *assign_exp = direct_declarator->child->next_sibling->next_sibling;
                    varNode rnode = praser_assignment_expression(assign_exp);

                    if (rnode.type != "int")
                    {
                        error(declarator->line, "Array size must be int.");
                    }

                    varNode tnode;
                    if (arrayType == "int" || arrayType == "float")
                    {
                        string tempname = "temp" + to_string(codePrinter.temp_var_count);
                        ++codePrinter.temp_var_count;
                        tnode = createTempVar(tempname, "int");

                        blockStack.back()._var_map.insert({tempname, tnode});

                        varNode tempVar3;
                        string tempName3 = "temp" + to_string(codePrinter.temp_var_count);
                        ++codePrinter.temp_var_count;
                        tempVar3.name = tempName3;
                        tempVar3.type = "int";
                        blockStack.back()._var_map.insert({tempName3, tempVar3});

                        codePrinter.addCode(tempName3 + " := #4");

                        codePrinter.addCode(tnode.name + " := " + tempName3 + " * " + rnode.name);
                    }
                    else if (arrayType == "double")
                    {
                        string tempname = "temp" + to_string(codePrinter.temp_var_count);
                        ++codePrinter.temp_var_count;
                        tnode = createTempVar(tempname, "int");

                        blockStack.back()._var_map.insert({tempname, tnode});

                        varNode tempVar3;
                        string tempName3 = "temp" + to_string(codePrinter.temp_var_count);
                        ++codePrinter.temp_var_count;
                        tempVar3.name = tempName3;
                        tempVar3.type = "int";
                        blockStack.back()._var_map.insert({tempName3, tempVar3});

                        codePrinter.addCode(tempName3 + " := #8");

                        codePrinter.addCode(tnode.name + " := " + tempName3 + " * " + rnode.name);
                    }
                    else if (arrayType == "bool")
                    {
                        tnode = rnode;
                    }
                    else
                    {
                        error(declarator->line, "Array initialize error for type.");
                    }

                    arrayNode anode;
                    anode.name = arrayName;
                    anode.type = arrayType;
                    anode.count = codePrinter.array_count++;
                    codePrinter.addCode("DEC " + codePrinter.getarrayNodeName(anode) + " " + tnode.name);

                    blockStack.back()._array_map.insert({arrayName, anode});
                }
            }
        }
    }
    else if (declarator->next_sibling->name == "=")
    {
        ParseTree *direct_declarator = NULL;
        //if is pointer
        if (declarator->child->name == "pointer")
        {
            error(node->line, "do not support pointer");
        }
        else
        {
            varNode newvar;
            direct_declarator = declarator->child;
            if (direct_declarator->child->name == "IDENTIFIER")
            {
                ParseTree *id = direct_declarator->child;
                string var = id->content;

                if (!lookup_var_in_current_block(var))
                {
                    newvar.name = var;
                    newvar.type = vartype;
                    newvar.count = codePrinter.var_count;
                    codePrinter.var_count++;
                    blockStack.back()._var_map.insert({var, newvar});
                }
                else
                {
                    error(declarator->child->line, "Variable multiple declaration.");
                }
            }

            ParseTree *initializer = declarator->next_sibling->next_sibling;

            if (initializer == NULL)
            {
                error(declarator->line, "Lack the initializer for variable.");
            }
            else
            {
                if (initializer->child->name == "assignment_expression")
                {
                    varNode rnode = praser_assignment_expression(initializer->child);
                    codePrinter.addCode(codePrinter.createCodeforAssign(newvar, rnode));
                    string rtype = rnode.type;
                    if (rtype != vartype)
                    {
                        error(initializer->child->line, "Wrong type to variable " + declarator->child->content + ": " +
                                                            rtype + " to " + vartype);
                    }
                }
            }
        }
    }
    else
    {
        error(node->line, "Wrong value to variable");
    }
}

ParseTree *Praser::praser_function_definition(ParseTree *function_def)
{
    ParseTree *type_specifier = function_def->child;
    ParseTree *declarator;
    ParseTree *compound_statement;

    declarator = function_def->child->next_sibling;
    compound_statement = function_def->child->next_sibling;

    string funcType = type_specifier->child->content;
    string funcName = declarator->child->child->content;

    bool isdeclared = false;
    funcNode declarFunc;
    if (func_map.find(funcName) != func_map.end())
    {
        //repeated definition
        if (func_map[funcName].is_defined)
        {
            error(declarator->child->child->line, "Function " + funcName + " is duplicated definition.");
        }
        //函数事先声明过但是没有定义
        else
        {
            isdeclared = true;
            //先删除掉函数池中的函数的声明
            declarFunc = func_map[funcName];
            func_map.erase(func_map.find(funcName));
        }
    }

    //进入新的block
    block funBlock;
    funBlock.isFunc = true;
    funBlock._func.name = funcName;
    funBlock._func.return_type = funcType;
    funBlock._func.is_defined = true;
    //将函数记录在块内并添加到函数池
    blockStack.push_back(funBlock);
    func_map.insert({funcName, funBlock._func});

    codePrinter.addCode("FUNCTION " + funcName + " :");

    //获取函数形参列表
    if (declarator->child->child->name == "direct_declarator")
    {
        if (declarator->child->child->next_sibling->next_sibling->name == ")")
        {
        }
        else if (declarator->child->child->next_sibling->next_sibling->child->name == "parameter_list")
        {
            praser_parameter_list(declarator->child->child->next_sibling->next_sibling->child, funcName, true);
        }
    }

    //此时函数池中的func已经添加了参数列表
    funcNode func = func_map[funcName];
    //如果函数事先声明过，则比较函数的参数列表和返回类型
    if (isdeclared)
    {
        if (func.return_type != declarFunc.return_type)
        {
            error(type_specifier->child->line, "Function return type doesn't equal to the function declared before.");
        }
        cout << funBlock._func.param_list.size() << endl;
        if (func.param_list.size() != declarFunc.param_list.size())
        {
            error(declarator->child->next_sibling->next_sibling->line, "The number of function parameters doesn't equal to the function declared before.");
        }
        for (int i = 0; i < funBlock._func.param_list.size(); i++)
        {
            if (func.param_list[i].type != declarFunc.param_list[i].type)
                error(declarator->child->next_sibling->next_sibling->line, "The parameter " + funBlock._func.param_list[i].name + "'s type doesn't equal to the function declared before.");
        }
    }
    //更新Block中func的参数列表
    funBlock._func = func;
    //分析函数的正文
    praser_compound_statement(compound_statement);

    //函数结束后，弹出相应的block
    blockStack.pop_back();

    return function_def->next_sibling;
}
ParseTree *Praser::praser_statement(ParseTree *statment)
{
    if (statment->child->name == "labeled_statement")
    {
    }
    if (statment->child->name == "compound_statement")
    {
        praser_compound_statement(statment->child);
    }
    if (statment->child->name == "expression_statement")
    {
        praser_expression_statement(statment->child);
    }
    if (statment->child->name == "selection_statement")
    {
        praser_selection_statement(statment->child);
    }
    if (statment->child->name == "iteration_statement")
    {
        praser_iteration_statement(statment->child);
    }
    if (statment->child->name == "jump_statement")
    {
        praser_jump_statement(statment->child);
    }

    return statment->next_sibling;
}
void Praser::praser_expression_statement(ParseTree *node)
{
    if (node->child->name == "expression")
    {
        praser_expression(node->child);
    }
}

varNode Praser::praser_expression(ParseTree *node)
{
    if (node->child->name == "expression")
    {
        return praser_expression(node->child);
    }
    else if (node->child->name == "assignment_expression")
    {
        return praser_assignment_expression(node->child);
    }
    if (node->next_sibling->name == ",")
    {
        return praser_assignment_expression(node->next_sibling->next_sibling);
    }
}

void Praser::praser_jump_statement(ParseTree *node)
{
    if (node->child->name == "goto")
    {
    }
    else if (node->child->name == "continue")
    {
    }
    else if (node->child->name == "break")
    {
        int num = getBreakBlockNumber();
        if (num < 0)
        {
            cout << "Error line:" << node->line << ".Not support break";
        }
        codePrinter.addCode("GOTO" + blockStack[num].gotoLabel);
    }
    else if (node->child->name == "return")
    {
        string funcType = getFuncRType();
        if (node->child->next_sibling->name == "expression")
        { //return expression
            varNode rnode = praser_expression(node->child->next_sibling);
            codePrinter.addCode(codePrinter.createCodeforReturn(rnode));
            if (rnode.type != funcType)
            {
                error(node->child->next_sibling->line, "return type doesn't equal to function return type.");
            }
        }
        else if (node->child->next_sibling->name == ";")
        { //return ;
            codePrinter.addCode("RETURN");
            if (funcType != "void")
            {
                error(node->child->next_sibling->line, "You should return " + blockStack.back()._func.return_type);
            }
        }
    }
}
void Praser::praser_compound_statement(ParseTree *node)
{
    praserParseTree(node);
}

//if,else
void Praser::praser_selection_statement(ParseTree *node)
{
    if (node->child->name == "if")
    {
        if (node->child->next_sibling->next_sibling->next_sibling->next_sibling->next_sibling == NULL)
        {
            block newblock;
            blockStack.push_back(newblock);

            ParseTree *expression = node->child->next_sibling->next_sibling;
            varNode exp_rnode = praser_expression(expression);
            ParseTree *statement = node->child->next_sibling->next_sibling->next_sibling->next_sibling;

            string label1 = codePrinter.getLabelName();
            string label2 = codePrinter.getLabelName();

            if (exp_rnode.type == "bool")
            {
                codePrinter.addCode("IF " + exp_rnode.boolValue + " GOTO " + label1);
            }
            else
            {
                string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
                ++codePrinter.temp_var_count;
                varNode newznode = createTempVar(tempzeroname, "int");
                codePrinter.addCode(tempzeroname + " := #0");

                codePrinter.addCode("IF " + codePrinter.getNodeName(exp_rnode) + " != " + tempzeroname + " GOTO " + label1);
            }

            codePrinter.addCode("GOTO " + label2);
            codePrinter.addCode("LABEL " + label1 + " :");

            praser_statement(statement);

            codePrinter.addCode("LABEL " + label2 + " :");

            blockStack.pop_back();
        }
        else if (node->child->next_sibling->next_sibling->next_sibling->next_sibling->next_sibling->name == "else")
        {
            //new block
            block newblock1;
            blockStack.push_back(newblock1);

            ParseTree *expression = node->child->next_sibling->next_sibling;
            varNode exp_rnode = praser_expression(expression);
            ParseTree *statement1 = node->child->next_sibling->next_sibling->next_sibling->next_sibling;
            ParseTree *statement2 = node->child->next_sibling->next_sibling->next_sibling->next_sibling->next_sibling->next_sibling;

            string label1 = codePrinter.getLabelName();
            string label2 = codePrinter.getLabelName();
            string label3 = codePrinter.getLabelName();

            if (exp_rnode.type == "bool")
            {
                codePrinter.addCode("IF " + exp_rnode.boolValue + " GOTO " + label1);
            }
            else
            {
                string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
                ++codePrinter.temp_var_count;
                varNode newznode = createTempVar(tempzeroname, "int");
                codePrinter.addCode(tempzeroname + " := #0");

                codePrinter.addCode("IF " + codePrinter.getNodeName(exp_rnode) + " != " + tempzeroname + " GOTO " + label1);
            }

            codePrinter.addCode("GOTO " + label2);
            codePrinter.addCode("LABEL " + label1 + " :");

            praser_statement(statement1);

            codePrinter.addCode("GOTO " + label3);
            //pop block
            blockStack.pop_back();

            //else
            codePrinter.addCode("LABEL " + label2 + " :");

            block newblock2;
            blockStack.push_back(newblock2);

            praser_statement(statement2);

            codePrinter.addCode("LABEL " + label3 + " :");

            //pop block
            blockStack.pop_back();
        }
    }
    else if (node->child->name == "switch")
    {
        error(node->line, "Do not support switch");
    }
}
void Praser::praser_iteration_statement(ParseTree *node)
{
    if (node->child->name == "while")
    {
        block newblock;
        newblock.breakable = true;
        blockStack.push_back(newblock);

        ParseTree *expression = node->child->next_sibling->next_sibling;
        ParseTree *statement = node->child->next_sibling->next_sibling->next_sibling->next_sibling;

        string label1 = codePrinter.getLabelName();
        string label2 = codePrinter.getLabelName();
        string label3 = codePrinter.getLabelName();

        blockStack.back().gotoLabel = label3;

        codePrinter.addCode("LABEL " + label1 + " :");

        varNode var = praser_expression(expression);

        if (var.type == "bool")
        {
            codePrinter.addCode("IF " + var.boolValue + " GOTO " + label2);
        }
        else
        {
            string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
            ++codePrinter.temp_var_count;
            varNode newznode = createTempVar(tempzeroname, "int");
            codePrinter.addCode(tempzeroname + " := #0");

            codePrinter.addCode("IF " + codePrinter.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
        }
        codePrinter.addCode("GOTO " + label3);
        codePrinter.addCode("LABEL " + label2 + " :");

        praser_statement(statement);

        codePrinter.addCode("GOTO " + label1);
        codePrinter.addCode("LABEL " + label3 + " :");

        //pop block
        blockStack.pop_back();
    }
    else if (node->child->name == "do")
    {
        block newblock;
        newblock.breakable = true;
        blockStack.push_back(newblock);

        ParseTree *statement = node->child->next_sibling;
        ParseTree *expression = node->child->next_sibling->next_sibling->next_sibling->next_sibling;

        string label1 = codePrinter.getLabelName();
        string label2 = codePrinter.getLabelName();

        blockStack.back().gotoLabel = label2;

        codePrinter.addCode("LABEL " + label1 + " :");

        praser_statement(statement);
        varNode var = praser_expression(expression);

        if (var.type == "bool")
        {
            codePrinter.addCode("IF " + var.boolValue + " GOTO " + label1);
        }
        else
        {
            string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
            ++codePrinter.temp_var_count;
            varNode newzonde = createTempVar(tempzeroname, "int");
            codePrinter.addCode(tempzeroname + " := #0");

            codePrinter.addCode("IF " + codePrinter.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
        }
        codePrinter.addCode("GOTO " + label1);

        blockStack.pop_back();
    }
    else if (node->child->name == "for")
    {
        if (node->child->next_sibling->next_sibling->name == "expression_statement")
        {
            if (node->child->next_sibling->next_sibling->next_sibling->next_sibling->name == ")")
            {
                block newblock;
                newblock.breakable = true;
                blockStack.push_back(newblock);

                ParseTree *exp_state1 = node->child->next_sibling->next_sibling;
                ParseTree *exp_state2 = exp_state1->next_sibling;
                ParseTree *statement = exp_state2->next_sibling->next_sibling;

                string label1 = codePrinter.getLabelName();
                string label2 = codePrinter.getLabelName();
                string label3 = codePrinter.getLabelName();

                blockStack.back().gotoLabel = label3;

                if (exp_state1->child->name == "expression")
                {
                    praser_expression(exp_state1->child);
                }
                codePrinter.addCode("LABEL " + label1 + " :");

                varNode var;
                if (exp_state2->child->name == "expression")
                {
                    var = praser_expression(exp_state2->child);
                    if (var.type == "bool")
                    {
                        codePrinter.addCode("IF " + var.boolValue + " GOTO " + label2);
                    }
                    else
                    {
                        string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
                        ++codePrinter.temp_var_count;
                        varNode newznode = createTempVar(tempzeroname, "int");
                        codePrinter.addCode(tempzeroname + " := #0");

                        codePrinter.addCode("IF " + codePrinter.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
                    }
                }
                else
                {
                    codePrinter.addCode("GOTO " + label2);
                }

                codePrinter.addCode("GOTO " + label3);
                codePrinter.addCode("LABEL " + label2 + ":");

                praser_statement(statement);

                codePrinter.addCode("GOTO " + label1);
                codePrinter.addCode("LABEL " + label3 + ":");

                blockStack.pop_back();
            }
            else if (node->child->next_sibling->next_sibling->next_sibling->next_sibling->name == "expression")
            {
                block newblock;
                newblock.breakable = true;
                blockStack.push_back(newblock);

                ParseTree *exp_state1 = node->child->next_sibling->next_sibling;
                ParseTree *exp_state2 = exp_state1->next_sibling;
                ParseTree *exp = exp_state2->next_sibling;
                ParseTree *statement = exp->next_sibling->next_sibling;

                string label1 = codePrinter.getLabelName();
                string label2 = codePrinter.getLabelName();
                string label3 = codePrinter.getLabelName();

                blockStack.back().gotoLabel = label3;

                if (exp_state1->child->name == "expression")
                {
                    praser_statement(exp_state1->child);
                }
                codePrinter.addCode("LABEL " + label1 + ":");

                varNode var;
                if (exp_state2->child->name == "expression")
                {
                    var = praser_expression(exp_state2->child);
                    if (var.type == "bool")
                    {
                        codePrinter.addCode("IF " + var.boolValue + " GOTO " + label2);
                    }
                    else
                    {
                        string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
                        ++codePrinter.temp_var_count;
                        varNode newznode = createTempVar(tempzeroname, "int");
                        codePrinter.addCode(tempzeroname + " := #0");

                        codePrinter.addCode("IF " + codePrinter.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
                    }
                }
                else
                {
                    codePrinter.addCode("GOTO " + label2);
                }

                codePrinter.addCode("GOTO " + label3);
                codePrinter.addCode("LABEL " + label2 + " :");

                praser_statement(statement);

                praser_expression(exp);

                codePrinter.addCode("GOTO " + label1);
                codePrinter.addCode("LABEL " + label3 + " :");

                blockStack.pop_back();
            }
        }
        if (node->child->next_sibling->next_sibling->name == "declaration")
        {
            if (node->child->next_sibling->next_sibling->next_sibling->next_sibling->name == ")")
            {
                block newblock;
                newblock.breakable = true;
                blockStack.push_back(newblock);

                ParseTree *declaration = node->child->next_sibling->next_sibling;
                ParseTree *expression_statement = declaration->next_sibling;
                ParseTree *statement = expression_statement->next_sibling->next_sibling;

                string label1 = codePrinter.getLabelName();
                string label2 = codePrinter.getLabelName();
                string label3 = codePrinter.getLabelName();

                blockStack.back().gotoLabel = label3;

                praser_declaration(declaration);
                codePrinter.addCode("LABEL " + label1 + " :");

                varNode var;
                if (expression_statement->child->name == "expression")
                {

                    var = praser_expression(expression_statement->child);

                    if (var.type == "bool")
                    {
                        codePrinter.addCode("IF " + var.boolValue + " GOTO " + label2);
                    }
                    else
                    {
                        string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
                        ++codePrinter.temp_var_count;
                        varNode newznode = createTempVar(tempzeroname, "int");
                        codePrinter.addCode(tempzeroname + " := #0");

                        codePrinter.addCode("IF " + codePrinter.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
                    }
                }
                else
                {
                    codePrinter.addCode("GOTO " + label2);
                }
                codePrinter.addCode("GOTO " + label3);
                codePrinter.addCode("LABEL " + label2 + " :");

                praser_statement(statement);

                codePrinter.addCode("GOTO " + label1);
                codePrinter.addCode("LABEL " + label3 + " :");

                blockStack.pop_back();
            }
            else if (node->child->next_sibling->next_sibling->next_sibling->next_sibling->name == "expression")
            {
                block newblock;
                newblock.breakable = true;
                blockStack.push_back(newblock);

                ParseTree *declaration = node->child->next_sibling->next_sibling;
                ParseTree *expression_statement = declaration->next_sibling;
                ParseTree *expression = expression_statement->next_sibling;
                ParseTree *statement = expression->next_sibling->next_sibling;

                string label1 = codePrinter.getLabelName();
                string label2 = codePrinter.getLabelName();
                string label3 = codePrinter.getLabelName();

                blockStack.back().gotoLabel = label3;

                praser_declaration(declaration);
                codePrinter.addCode("LABEL " + label1 + " :");

                varNode var;
                if (expression_statement->child->name == "expression")
                {
                    var = praser_expression(expression_statement->child);

                    if (var.type == "bool")
                    {
                        codePrinter.addCode("IF " + var.boolValue + " GOTO " + label2);
                    }
                    else
                    {
                        string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
                        ++codePrinter.temp_var_count;
                        varNode newznode = createTempVar(tempzeroname, "int");
                        codePrinter.addCode(tempzeroname + " := #0");

                        codePrinter.addCode("IF " + codePrinter.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
                    }
                }
                else
                {
                    codePrinter.addCode("GOTO " + label2);
                }
                codePrinter.addCode("GOTO " + label3);
                codePrinter.addCode("LABEL " + label2 + " :");

                praser_statement(statement);

                praser_expression(expression);

                codePrinter.addCode("GOTO " + label1);
                codePrinter.addCode("LABEL " + label3 + " :");

                blockStack.pop_back();
            }
        }
    }
}

varNode Praser::praser_assignment_expression(ParseTree *assign_exp)
{
    varNode node1, node2, node3;
    cout << "here1"<<endl;
    cout<<assign_exp->name<<endl;
    if (assign_exp->child->name == "conditional_expression")
    {
        cout << "here2"<<endl;
        return praser_conditional_expression(assign_exp->child);
    }
    //Truely is assignment expression
    else if (assign_exp->child->name == "unary_expression")
    {
        cout << "here3"<<endl;
        ParseTree *unary_exp = assign_exp->child;
        string op = assign_exp->child->next_sibling->child->name;
        ParseTree *next_assign_exp = assign_exp->child->next_sibling->next_sibling;
        node1 = praser_unary_expression(unary_exp);
        node2 = praser_assignment_expression(next_assign_exp);
        if (op == "=")
        {
            node3 = node2;
        }
        else
        {
            string tempname = "temp" + to_string(codePrinter.temp_var_count);
            codePrinter.temp_var_count++;
            node3 = createTempVar(tempname, node1.type);

            blockStack.back()._var_map.insert({tempname, node3});
            string op_math = op_math_map[op];
            if (op_math == "*" || op_math == "/" || op_math == "+" || op_math == "-")
            {
                if (node1.type != node2.type)
                {
                    error(assign_exp->child->line, "Different type for two variables.");
                }
            }
            else if (op_math == "&" || op_math == "|" || op_math == "^" || op_math == "<<" || op_math == ">>" || op_math == "%")
            {
                if ((node1.type != "int" && node1.type != "long" && node1.type != "long long") || (node2.type != "int" && node2.type != "long" && node2.type != "long long"))
                {
                    error(assign_exp->child->line, "The two variables must be integer.");
                }
            }
            codePrinter.addCode(codePrinter.createCodeforVar(tempname, op_math, node1, node2));
        }

        codePrinter.addCode(codePrinter.createCodeforAssign(node1, node3));
        return node1;
    }
    cout << "here4"<<endl;
    return node1;
}
varNode Praser::praser_conditional_expression(ParseTree *conditional_exp)
{
    varNode node1, node2, node3;
    if (conditional_exp->child->next_sibling == NULL)
    {
        //cout <<"dead1"<<endl;
        return praser_logical_or_expression(conditional_exp->child);
    }
    else
    {
        //cout <<"dead2"<<endl;
        node1 = praser_logical_or_expression(conditional_exp->child);
        node2 = praser_expression(conditional_exp->child->next_sibling->next_sibling);
        node3 = praser_conditional_expression(conditional_exp->child->next_sibling->next_sibling->next_sibling->next_sibling);
    }
}
varNode Praser::praser_logical_or_expression(ParseTree *logical_or_exp)
{
    varNode node1, node2;
    if (logical_or_exp->child->name == "logical_and_expression")
    {
        return praser_logical_and_expression(logical_or_exp->child);
    }
    else if (logical_or_exp->child->name == "logical_or_expression")
    {
        varNode node1 = praser_logical_or_expression(logical_or_exp->child);
        varNode node2 = praser_logical_and_expression(logical_or_exp->child->next_sibling->next_sibling);
        if (node1.type != "bool" || node2.type != "bool")
        {
            error(logical_or_exp->child->next_sibling->line, "Logical Or operation should only be used to bool-type variable.");
        }

        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        varNode newnode = createTempVar(tempname, node1.type);

        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, "||", node1, node2));

        newnode.boolValue = codePrinter.getNodeName(node1) + " || " + codePrinter.getNodeName(node2);

        return newnode;
    }
    return node1;
}
varNode Praser::praser_logical_and_expression(ParseTree *logical_and_exp)
{
    varNode node1, node2;
    if (logical_and_exp->child->name == "inclusive_or_expression")
    {
        return praser_inclusive_or_expression(logical_and_exp->child);
    }
    else if (logical_and_exp->child->name == "logical_and_expression")
    {
        varNode node1 = praser_logical_and_expression(logical_and_exp->child);
        varNode node2 = praser_inclusive_or_expression(logical_and_exp->child->next_sibling->next_sibling);
        if (node1.type != "bool" || node2.type != "bool")
        {
            error(logical_and_exp->child->next_sibling->line, "Logical Or operation should only be used to bool-type variable.");
        }

        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        varNode newnode = createTempVar(tempname, node1.type);

        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, "&&", node1, node2));

        newnode.boolValue = codePrinter.getNodeName(node1) + " && " + codePrinter.getNodeName(node2);

        return newnode;
    }
    return node1;
}
varNode Praser::praser_inclusive_or_expression(ParseTree *inclusive_or_exp)
{
    varNode node1, node2;
    if (inclusive_or_exp->child->name == "exclusive_or_expression")
    {
        return praser_exclusive_or_expression(inclusive_or_exp->child);
    }
    else
    {
        node1 = praser_inclusive_or_expression(inclusive_or_exp->child);
        node2 = praser_exclusive_or_expression(inclusive_or_exp->child->next_sibling->next_sibling);
        if ((node1.type != "int" && node1.type != "long" && node1.type != "long long") || (node2.type != "int" && node2.type != "long" && node2.type != "long long"))
        {
            error(inclusive_or_exp->child->line, "Inclusive Or operation should only be used to integer.");
        }
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        varNode newnode = createTempVar(tempname, node1.type);

        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, "|", node1, node2));

        return newnode;
    }
    return node1;
}
varNode Praser::praser_exclusive_or_expression(ParseTree *exclusive_or_exp)
{
    varNode node1, node2;
    if (exclusive_or_exp->child->name == "and_expression")
    {
        return praser_and_expression(exclusive_or_exp->child);
    }
    else
    {
        node1 = praser_exclusive_or_expression(exclusive_or_exp->child);
        node2 = praser_and_expression(exclusive_or_exp->child->next_sibling->next_sibling);
        if ((node1.type != "int" && node1.type != "long" && node1.type != "long long") || (node2.type != "int" && node2.type != "long" && node2.type != "long long"))
        {
            error(exclusive_or_exp->child->line, "Exclusive Or operation should only be used to integer.");
        }
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        varNode newnode = createTempVar(tempname, node1.type);

        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, "^", node1, node2));
        return newnode;
    }
    return node1;
}
varNode Praser::praser_and_expression(ParseTree *and_exp)
{
    varNode node1, node2;
    if (and_exp->child->name == "equality_expression")
    {
        return praser_equality_expression(and_exp->child);
    }
    else
    {
        node1 = praser_and_expression(and_exp->child);
        node2 = praser_equality_expression(and_exp->child->next_sibling->next_sibling);
        if ((node1.type != "int" && node1.type != "long" && node1.type != "long long") || (node2.type != "int" && node2.type != "long" && node2.type != "long long"))
        {
            error(and_exp->child->line, "And operation should only be used to integer.");
        }
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        varNode newnode = createTempVar(tempname, node1.type);

        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, "&", node1, node2));

        return newnode;
    }
    return node1;
}
varNode Praser::praser_equality_expression(ParseTree *equal_exp)
{
    varNode node1, node2;
    if (equal_exp->child->name == "relational_expression")
    {
        return praser_relational_expression(equal_exp->child);
    }
    else
    {
        node1 = praser_equality_expression(equal_exp->child);
        node2 = praser_relational_expression(equal_exp->child->next_sibling->next_sibling);
        string op = equal_exp->child->next_sibling->name;
        if (node1.type != node2.type)
        {
            error(equal_exp->child->next_sibling->line, "Different type for two variables.");
        }
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;

        varNode newnode = createTempVar(tempname, "bool");
        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

        newnode.boolValue = codePrinter.getNodeName(node1) + " " + op + " " + codePrinter.getNodeName(node2);

        return newnode;
    }
    return node1;
}
varNode Praser::praser_relational_expression(ParseTree *relational_exp)
{
    varNode node1, node2;
    if (relational_exp->child->name == "shift_expression")
    {
        return praser_shift_expression(relational_exp->child);
    }
    else
    {
        node1 = praser_relational_expression(relational_exp->child);
        node2 = praser_shift_expression(relational_exp->child->next_sibling->next_sibling);
        string op = op_math_map[relational_exp->child->next_sibling->name];

        if (node1.type != node2.type)
        {
            error(relational_exp->child->next_sibling->line, "Different type for two variables.");
        }
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;

        varNode newnode = createTempVar(tempname, "bool");
        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

        newnode.boolValue = codePrinter.getNodeName(node1) + " " + op + " " + codePrinter.getNodeName(node2);

        return newnode;
    }
    return node1;
}
varNode Praser::praser_shift_expression(ParseTree *shift_exp)
{
    varNode node1, node2;
    if (shift_exp->child->name == "additive_expression")
    {
        return praser_additive_expression(shift_exp->child);
    }
    else
    {
        node1 = praser_shift_expression(shift_exp->child);
        node2 = praser_additive_expression(shift_exp->child->next_sibling->next_sibling);
        string op = op_math_map[shift_exp->child->next_sibling->name];

        if ((node1.type != "int" && node1.type != "long" && node1.type != "long long") || (node2.type != "int" && node2.type != "long" && node2.type != "long long"))
        {
            error(shift_exp->child->line, "Shift operation should only be used to integer.");
        }
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;

        varNode newnode = createTempVar(tempname, node1.type);
        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

        return newnode;
    }
    return node1;
}
varNode Praser::praser_additive_expression(ParseTree *add_exp)
{
    varNode node1, node2;
    if (add_exp->child->name == "multiplicative_expression")
    {
        return praser_multiplicative_expression(add_exp->child);
    }
    else
    {
        node1 = praser_additive_expression(add_exp->child);
        node2 = praser_multiplicative_expression(add_exp->child->next_sibling->next_sibling);
        string op = add_exp->child->next_sibling->name;

        if ((node1.type != "int" && node1.type != "long" && node1.type != "long long") || (node2.type != "int" && node2.type != "long" && node2.type != "long long"))
        {
            error(add_exp->child->line, "Add operation should only be used to integer.");
        }
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;

        varNode newnode = createTempVar(tempname, node1.type);
        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

        return newnode;
    }
    return node1;
}
varNode Praser::praser_multiplicative_expression(ParseTree *multiply_exp)
{
    varNode node1, node2;
    if (multiply_exp->child->name == "cast_expression")
    {
        return praser_cast_expression(multiply_exp->child);
    }
    else
    {
        node1 = praser_multiplicative_expression(multiply_exp->child);
        node2 = praser_cast_expression(multiply_exp->child->next_sibling->next_sibling);
        string op = multiply_exp->child->next_sibling->name;

        if ((node1.type != "int" && node1.type != "long" && node1.type != "long long") || (node2.type != "int" && node2.type != "long" && node2.type != "long long"))
        {
            error(multiply_exp->child->line, "Mutiply operation should only be used to integer.");
        }
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;

        varNode newnode = createTempVar(tempname, node1.type);
        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

        return newnode;
    }
    return node1;
}
varNode Praser::praser_cast_expression(ParseTree *cast_exp)
{
    varNode node1;
    if (cast_exp->child->name == "unary_expression")
    {
        return praser_unary_expression(cast_exp->child);
    }
    else
    {
        node1 = praser_cast_expression(cast_exp->child->next_sibling->next_sibling->next_sibling);
        //TODO type cast check
        node1.type = cast_exp->child->next_sibling->name;

        return node1;
    }
    return node1;
}
varNode Praser::praser_unary_expression(ParseTree *unary_exp)
{
    varNode returnNode;
    if (unary_exp->child->name == "postfix_expression")
    {
        return praser_postfix_expression(unary_exp->child);
    }
    else if (unary_exp->child->name == "INC_OP" || unary_exp->child->name == "DEC_OP")
    {
        string op = op_math_map[unary_exp->child->name];
        returnNode = praser_unary_expression(unary_exp->child->next_sibling);
        if (returnNode.type != "int" && returnNode.type != "long" && returnNode.type != "long long")
        {
            error(unary_exp->child->next_sibling->line, op + " operation can only use for integer type.");
        }

        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;

        varNode newnode = createTempVar(tempname, returnNode.type);
        blockStack.back()._var_map.insert({tempname, newnode});
        codePrinter.addCode(tempname + " := #1");

        //变量储存的是地址
        if (returnNode.useAddress)
        {
            codePrinter.addCode("*" + returnNode.name + " := *" + returnNode.name + " " + op[0] + " " + tempname);
        }
        else
        {
            codePrinter.addCode(codePrinter.getNodeName(returnNode) + " := " + codePrinter.getNodeName(returnNode) + " " + op[0] + " " + tempname);
        }

        return returnNode;
    }
    else if (unary_exp->child->name == "unary_operator")
    {
        string op = unary_exp->child->child->name;
        returnNode = praser_unary_expression(unary_exp->child->next_sibling);
        if (op == "+")
        {

            if (returnNode.type != "int" && returnNode.type != "double")
                error(unary_exp->child->child->line, "operator '+' can only used to int or double");
            return returnNode;
        }
        else if (op == "-")
        {

            if (returnNode.type != "int" && returnNode.type != "long" && returnNode.type != "long long" && returnNode.type != "float" && returnNode.type != "double")
                error(unary_exp->child->child->line, "operator '-' can only used to integer or double");

            string tempzeroname = "temp" + to_string(codePrinter.temp_var_count);
            codePrinter.temp_var_count++;
            varNode newzeronode = createTempVar(tempzeroname, returnNode.type);
            blockStack.back()._var_map.insert({tempzeroname, newzeronode});
            codePrinter.addCode(tempzeroname + " := #0");

            string tempname = "temp" + to_string(codePrinter.temp_var_count);
            codePrinter.temp_var_count++;

            varNode newnode = createTempVar(tempname, returnNode.type);
            blockStack.back()._var_map.insert({tempname, newnode});

            if (returnNode.type != "int" && returnNode.type != "long" && returnNode.type != "long long" && returnNode.type != "float" && returnNode.type != "double")
                error(unary_exp->child->child->line, "operator '-' can only used to int or double");

            if (returnNode.useAddress)
            {
                codePrinter.addCode(tempname + " := " + tempzeroname + " - *" + returnNode.name);
            }
            else
            {
                codePrinter.addCode(tempname + " := " + tempzeroname + " - " + codePrinter.getNodeName(returnNode));
            }
            return newnode;
        }
        else if (op == "~")
        {
            //TODO
        }
        else if (op == "!")
        {
            //TODO
        }
    }
    else if (unary_exp->child->name == "SIZEOF")
    {
        //TODO
    }
}
varNode Praser::praser_postfix_expression(ParseTree *postfix_exp)
{
    varNode node1;
    if (postfix_exp->child->name == "primary_expression")
    {
        return praser_primary_expression(postfix_exp->child);
    }

    if (postfix_exp->child->next_sibling->name == "[")
    {
        //array index
        string arrayName = postfix_exp->child->child->child->content;
        ParseTree *expression = postfix_exp->child->next_sibling->next_sibling;
        varNode index_node = praser_expression(expression);
        arrayNode array_node = getArrayNode(arrayName);

        if (array_node.count < 0)
            error(postfix_exp->child->next_sibling->line, "Undifined array: " + arrayName);

        varNode tempVar;
        string tempName = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        tempVar.name = tempName;
        tempVar.type = array_node.type;
        tempVar.useAddress = true;
        blockStack.back()._var_map.insert({tempName, tempVar});

        if (array_node.type == "int" || array_node.type == "double")
        {
            varNode tempVar2, tempVar3;
            ;

            string tempName2 = "temp" + to_string(codePrinter.temp_var_count);
            codePrinter.temp_var_count++;
            tempVar2.name = tempName2;
            tempVar2.type = "int";
            blockStack.back()._var_map.insert({tempName2, tempVar2});

            string tempName3 = "temp" + to_string(codePrinter.temp_var_count);
            codePrinter.temp_var_count++;
            tempVar3.name = tempName3;
            tempVar3.type = "int";
            blockStack.back()._var_map.insert({tempName3, tempVar3});
            if (array_node.type == "int")
            {
                codePrinter.addCode(tempName3 + " := #4");
            }
            else if (array_node.type == "double")
            {
                codePrinter.addCode(tempName3 + " := #8");
            }
            codePrinter.addCode(tempName2 + " := " + codePrinter.getNodeName(index_node) + " * " + tempName3);
            codePrinter.addCode(tempName + " := &" + codePrinter.getarrayNodeName(array_node) + " + " + codePrinter.getNodeName(tempVar2));
            return tempVar;
        }

        codePrinter.addCode(tempName + " := &" + codePrinter.getarrayNodeName(array_node) + " + " + codePrinter.getNodeName(index_node));
        return tempVar;
    }
    else if (postfix_exp->child->next_sibling->name == "(")
    {
        //function call
        string funcName = postfix_exp->child->child->child->content;
        varNode newNode;

        if (func_map.find(funcName) == func_map.end())
        {
            error(postfix_exp->child->child->child->line, "Undefined function " + funcName);
        }

        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!?????????????" << endl;
        if (postfix_exp->child->next_sibling->next_sibling->name == "argument_expression_list")
        {
            //function call with params
            praser_argument_expression_list(postfix_exp->child->next_sibling->next_sibling, funcName);
        }

        funcNode func = func_map[funcName];

        if (func.return_type == "void")
        {
            codePrinter.addCode("CALL " + funcName);
        }
        else
        {
            string tempname = "temp" + to_string(codePrinter.temp_var_count);
            codePrinter.temp_var_count++;

            newNode = createTempVar(tempname, func_map[funcName].return_type);
            codePrinter.addCode(tempname + " := CALL " + funcName);
        }

        return newNode;
    }
    else if (postfix_exp->child->next_sibling->name == ".")
    {
    }
    else if (postfix_exp->child->next_sibling->name == "PTR_OP")
    {
    }
    else if (postfix_exp->child->next_sibling->name == "INC_OP" || postfix_exp->child->next_sibling->name == "DEC_OP")
    {
        string op = op_math_map[postfix_exp->child->next_sibling->name];
        if (node1.type != "int")
            error(postfix_exp->child->next_sibling->line, op + " operation can only use for int type.");

        string tempname1 = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        varNode newnode1 = createTempVar(tempname1, "int");
        blockStack.back()._var_map.insert({tempname1, newnode1});

        string tempname2 = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        varNode newnode2 = createTempVar(tempname2, "int");
        blockStack.back()._var_map.insert({tempname2, newnode2});

        codePrinter.addCode(tempname2 + " := #1");

        //变量储存的是地址
        if (node1.useAddress)
        {
            codePrinter.addCode(tempname1 + " := *" + node1.name);
            codePrinter.addCode("*" + node1.name + " := *" + node1.name + " + " + tempname2);
        }
        else
        {
            codePrinter.addCode(tempname1 += " := " + codePrinter.getNodeName(node1));
            codePrinter.addCode(codePrinter.getNodeName(node1) + " := " + codePrinter.getNodeName(node1) + " " + op[0] + " " + tempname2);
        }

        return newnode1;
    }
    return node1;
}
varNode Praser::praser_primary_expression(ParseTree *primary_exp)
{
    varNode returnNode;
    if (primary_exp->child->name == "IDENTIFIER")
    {
        string content = primary_exp->child->content;
        returnNode = lookupNode(content);
        if (returnNode.count < 0)
        {
            error(primary_exp->child->line, "Undefined variable " + content);
        }
        return returnNode;
    }
    else if (primary_exp->child->name == "TRUE" || primary_exp->child->name == "FALSE")
    {
        string content = primary_exp->child->content;
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        varNode newNode = createTempVar(tempname, "bool");
        blockStack.back()._var_map.insert({tempname, newNode});
        if (primary_exp->child->name == "TRUE")
            codePrinter.addCode(tempname + " := #1");
        else
        {
            codePrinter.addCode(tempname + " := #0");
        }
        return newNode;
    }
    else if (primary_exp->child->name == "CONSTANT_INT" || primary_exp->child->name == "CONSTANT_FLOAT" || primary_exp->child->name == "CONSTANT_CHAR")
    {
        string content = primary_exp->child->content;
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;
        string temptype = primary_exp->child->name.substr(9);
        transform(temptype.begin(), temptype.end(), temptype.begin(), ::tolower);
        varNode newNode = createTempVar(tempname, temptype);
        blockStack.back()._var_map.insert({tempname, newNode});
        codePrinter.addCode(tempname + " := #" + content);
        return newNode;
    }
    else if (primary_exp->child->name == "STRING_LITERAL")
    {
        string content = primary_exp->child->content;
        string tempname = "temp" + to_string(codePrinter.temp_var_count);
        codePrinter.temp_var_count++;

        varNode newNode = createTempVar(tempname, "char");
        newNode.useAddress = true;
        blockStack.back()._var_map.insert({tempname, newNode});
        codePrinter.addCode(tempname + " := #" + content);
        return newNode;
    }
    else if (primary_exp->child->name == "(")
    {
        return praser_expression(primary_exp->child->next_sibling);
    }
}
void Praser::praser_argument_expression_list(ParseTree *argument_exp, string func_name)
{
    ParseTree *temp = argument_exp->child;
    funcNode func = func_map[func_name];
    int count = 0;

    while (temp->name == "argument_expression_list" && temp->next_sibling != NULL)
    {
        cout <<"1231232132" <<endl;
        cout<<temp->name<<endl;
        cout<<temp->next_sibling->name<<endl;
        varNode arg = praser_assignment_expression(temp->next_sibling->next_sibling);
        codePrinter.addCode(codePrinter.createCodeforArgument(arg));
        count++;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << temp->name << endl;
        if (func.param_list[func.param_list.size() - count].type != arg.type)
        {
            error(temp->line, "Wrong type arguments to function " + func_name);
        }
        temp = temp->child;
    }
    varNode arg = praser_assignment_expression(temp);
    codePrinter.addCode(codePrinter.createCodeforArgument(arg));
    count++;
    if (func.param_list[func.param_list.size() - count].type != arg.type)
    {
        error(argument_exp->line, "Wrong type arguments to function " + func_name);
    }
    if (count != func.param_list.size())
    {
        error(argument_exp->line, "The number of arguments doesn't equal to the function parameters number in " + func_name + ".");
    }
}
varNode Praser::lookupNode(string nodename)
{
    varNode returnNode;
    for (int i = blockStack.size() - 1; i >= 0; i--)
    {
        if (blockStack[i]._var_map.find(nodename) != blockStack[i]._var_map.end())
        {
            return blockStack[i]._var_map[nodename];
        }
    }
    returnNode.count = -1;
    return returnNode;
}
bool Praser::lookup_var_in_current_block(string name)
{
    return blockStack.back()._var_map.find(name) != blockStack.back()._var_map.end();
}
varNode Praser::createTempVar(string tempname, string temptype)
{
    varNode tempNode;
    tempNode.name = tempname;
    tempNode.type = temptype;
    tempNode.count = -1;
    tempNode.global_or_local = false;
    tempNode.useAddress = false;
    return tempNode;
}

string Praser::getFuncRType()
{
    int N = blockStack.size();
    for (int i = N - 1; i >= 0; i--)
    {
        if (blockStack[i].isFunc)
            return blockStack[i]._func.return_type;
    }
    return "";
}

int Praser::getBreakBlockNumber()
{
    int N = blockStack.size();
    for (int i = N - 1; i >= 0; i--)
    {
        if (blockStack[i].breakable)
            return i;
    }
    return -1;
}

arrayNode Praser::getArrayNode(string nodename)
{
    arrayNode returnNode;
    for (int i = blockStack.size() - 1; i >= 0; i--)
    {
        if (blockStack[i]._array_map.find(nodename) != blockStack[i]._array_map.end())
        {
            return blockStack[i]._array_map[nodename];
        }
    }
    returnNode.count = -1;
    return returnNode;
}
void Praser::error(int line_number, string err_message)
{
    cout << "Error line:" << line_number << endl;
    cout << err_message << endl;
    exit(1);
}