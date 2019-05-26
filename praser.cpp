#include "praser.h"

Praser::Praser(ParseTree *root)
{
    this->root = root;
    init();
}
void Praser::init()
{
    block first_block;
    blockStack.push_back(first_block);
    op_math_map.insert("MUL_ASSIGN", "*");
    op_math_map.insert("DIV_ASSIGN", "/");
    op_math_map.insert("MOD_ASSIGN", "%");
    op_math_map.insert("ADD_ASSIGN", "+");
    op_math_map.insert("SUB_ASSIGN", "-");
    op_math_map.insert("LEFT_ASSIGN", "<<");
    op_math_map.insert("RIGHT_ASSIGN", ">>");
    op_math_map.insert("AND_ASSIGN", "&");
    op_math_map.insert("OR_ASSIGN", "|");
    op_math_map.insert("XOR_ASSIGN", "^");
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

    if (node->next_sibling->name == ",")
    {
        praser_parameter_declaration(node->next_sibling->next_sibling, funcName, definite);
    }
}

void Praser::praser_parameter_declaration(ParseTree *node, string funcName, bool definite)
{
    ParseTree* declaration_specifier = node->child;//
    ParseTree* declarator = node->child->next_sibling;//
    
}

varNode Praser::praser_assignment_expression(ParseTree *assign_exp)
{
    varNode node1, node2, node3;
    if (assign_exp->child->name == "conditional_expression")
    {
        return praser_conditional_expression(assign_exp->child);
    }
    //Truely is assignment expression
    else if (assign_exp->child->name == "unary_expression")
    {
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
    return node1;
}
varNode Praser::praser_conditional_expression(ParseTree *conditional_exp)
{
    if (conditional_exp->child->name == "logical_or_expression")
    {
        return praser_logical_or_expression(conditional_exp->child);
    }
}
varNode Praser::praser_logical_or_expression(ParseTree *logical_or_exp)
{
    varNode node1, node2;
    if (logical_or_exp->child->name == "logical_and_expression")
    {
        return praser_logical_or_expression(logical_or_exp->child);
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
    }
    return node1;
}
varNode Praser::praser_exclusive_or_expression(ParseTree *exclusive_or_exp)
{
}
varNode Praser::praser_and_expression(ParseTree *and_exp)
{
}
varNode Praser::praser_equality_expression(ParseTree *equal_exp)
{
}
varNode Praser::praser_relational_expression(ParseTree *relational_exp)
{
}
varNode Praser::praser_shift_expression(ParseTree *shift_exp)
{
}
varNode Praser::praser_additive_expression(ParseTree *)
{
}
varNode Praser::praser_multiplicative_expression(ParseTree *)
{
}
varNode Praser::praser_unary_expression(ParseTree *)
{
}
varNode Praser::praser_postfix_expression(ParseTree *)
{
}

void Praser::praser_argument_expression_list(ParseTree *argument_exp, string func_name)
{
    ParseTree *argument_list = argument_exp->child;
    funcNode func = func_map[func_name];
    int count = 0;
    while (argument_list->name == "argument_expression_list")
    {
        varNode arg = praser_assignment_expression(argument_list->next_sibling->next_sibling);
        argument_list = argument_list->child;
        codePrinter.addCode(codePrinter.createCodeforArgument(arg));
        count++;
        if (func.param_list[func.param_list.size() - count].type != arg.type)
        {
            error(argument_list->line, "Wrong type arguments to function " + func_name);
        }
    }
    varNode arg = praser_assignment_expression(argument_list->next_sibling->next_sibling);
    codePrinter.addCode(codePrinter.createCodeforArgument(arg));
    count++;
    if (func.param_list[func.param_list.size() - count].type != arg.type)
    {
        error(argument_list->line, "Wrong type arguments to function " + func_name);
    }
    if (count != func.param_list.size())
    {
        error(argument_list->line, "The number of arguments doesn't equal to the function parameters number in " + func_name + ".");
    }
}

bool Praser::lookup_var_in_current_block(string name)
{
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
void Praser::error(int line_number, string err_message)
{
    cout << "Error line:" << line_number << endl;
    cout << err_message << endl;
    exit(1);
}