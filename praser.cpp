#include "praser.h"

Praser::Praser(ParseTree* root)
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
    op_math_map.insert("GE_OP", ">=");
    op_math_map.insert("LE_OP", "<=");
    op_math_map.insert("<", "<");
    op_math_map.insert(">", ">");
    op_math_map.insert("LEFT_OP", "<<");
    op_math_map.insert("RIGHT_OP", ">>");
    op_math_map.insert("INC_OP", "++");
    op_math_map.insert("DEC_OP", "--");
}
varNode Praser::praser_assignment_expression(ParseTree* assign_exp)
{
    varNode node1, node2, node3;
    if(assign_exp->child->name == "conditional_expression")
    {
        return praser_conditional_expression(assign_exp->child); 
    }
    //Truely is assignment expression
    else if(assign_exp->child->name == "unary_expression")
    {
		ParseTree* unary_exp = assign_exp->child;
		string op = assign_exp->child->next_sibling->child->name;
		ParseTree* next_assign_exp = assign_exp->child->next_sibling->next_sibling;
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

			blockStack.back()._var_map.insert({ tempname,node3 });
            string op_math = op_math_map[op];
            if(op_math == "*" || op_math == "/" || op_math == "+" || op_math == "-")
            {
                if (node1.type != node2.type) 
                {
					error(assign_exp->child->line, "Different type for two variables.");
				}
            }
            else if(op_math == "&" || op_math == "|" || op_math == "^" || op_math == "<<" || op_math == ">>" || op_math == "%")
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
varNode Praser::praser_conditional_expression(ParseTree* conditional_exp)
{
    if(conditional_exp->child->name == "logical_or_expression")
    {
        return praser_logical_or_expression(conditional_exp->child); 
    }
}
varNode Praser::praser_logical_or_expression(ParseTree* logical_or_exp)
{
    varNode node1, node2;
    if(logical_or_exp->child->name == "logical_and_expression")
    {
        return praser_logical_or_expression(logical_or_exp->child); 
    }
    else if(logical_or_exp->child->name == "logical_or_expression")
    {
        varNode node1 = praser_logical_or_expression(logical_or_exp->child);
		varNode node2 = praser_logical_and_expression(logical_or_exp->child->next_sibling->next_sibling);
        if(node1.type != "bool" || node2.type != "bool")
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
varNode Praser::praser_logical_and_expression(ParseTree* logical_and_exp)
{
    varNode node1, node2;
    if(logical_and_exp->child->name == "inclusive_or_expression")
    {
        return praser_inclusive_or_expression(logical_and_exp->child); 
    }
    else if(logical_and_exp->child->name == "logical_and_expression")
    {
        varNode node1 = praser_logical_and_expression(logical_and_exp->child);
		varNode node2 = praser_inclusive_or_expression(logical_and_exp->child->next_sibling->next_sibling);
        if(node1.type != "bool" || node2.type != "bool")
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
varNode Praser::praser_inclusive_or_expression(ParseTree* inclusive_or_exp)
{
    varNode node1, node2;
    if(inclusive_or_exp->child->name == "exclusive_or_expression")
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
varNode Praser::praser_exclusive_or_expression(ParseTree* exclusive_or_exp)
{
    varNode node1, node2;
    if(exclusive_or_exp->child->name == "and_expression")
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
varNode Praser::praser_and_expression(ParseTree* and_exp)
{
    varNode node1, node2;
    if(and_exp->child->name == "equality_expression")
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
varNode Praser::praser_equality_expression(ParseTree* equal_exp)
{
    varNode node1, node2;
    if(equal_exp->child->name == "relational_expression")
    {
        return praser_equality_expression(equal_exp->child); 
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
		blockStack.back()._var_map.insert({ tempname,newnode});
		codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

		newnode.boolValue = codePrinter.getNodeName(node1) + " " + op + " " + codePrinter.getNodeName(node2);

		return newnode;
    }
    return node1;
}
varNode Praser::praser_relational_expression(ParseTree* relational_exp)
{
    varNode node1, node2;
    if(relational_exp->child->name == "shift_expression")
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
		blockStack.back()._var_map.insert({ tempname,newnode});
		codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

		newnode.boolValue = codePrinter.getNodeName(node1) + " " + op + " " + codePrinter.getNodeName(node2);

		return newnode;
    }
    return node1;
}
varNode Praser::praser_shift_expression(ParseTree* shift_exp)
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
		blockStack.back()._var_map.insert({ tempname,newnode});
		codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

		return newnode;
    }
    return node1;
}
varNode Praser::praser_additive_expression(ParseTree* add_exp)
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
		blockStack.back()._var_map.insert({ tempname,newnode});
		codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

		return newnode;
    }
    return node1;
}
varNode Praser::praser_multiplicative_expression(ParseTree* multiply_exp)
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
		blockStack.back()._var_map.insert({ tempname,newnode});
		codePrinter.addCode(codePrinter.createCodeforVar(tempname, op, node1, node2));

		return newnode;
    }
    return node1;
}
 varNode Praser::praser_cast_expression(ParseTree* cast_exp)
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
varNode Praser::praser_unary_expression(ParseTree* unary_exp)
{
    varNode returnNode;
    if (unary_exp->child->name == "postfix_expression") 
    {
		return praser_postfix_expression(unary_exp ->child);
	}
    else if (unary_exp->child->name == "INC_OP" || unary_exp->left->name == "DEC_OP") 
    {
        string op = op_math_map[unary_exp->child->name];
		returnNode = praser_unary_expression(unary_exp->child->next_sibling);
		if (rnode.type != "int")
        {
	        error(unary_exp->left->right->line, op + " operation can only use for int type.");
        }
		

		string tempname = "temp" + to_string(codePrinter.temp_var_count);
		codePrinter.temp_var_count++;

		varNode newnode = createTempVar(tempname, returnNode.type);
		blockStack.back()._var_map.insert({tempname, newnode});
		codePrinter.addCode(tempname + " := #1");


		//变量储存的是地址
		if (rnode.useAddress) {
			innerCode.addCode("*" + rnode.name + " := *" + rnode.name +  + tempname);
		}
		else {
			innerCode.addCode(innerCode.getNodeName(rnode) + " := " + innerCode.getNodeName(rnode) + " + "  + tempname);
		}

		return rnode;

	}
	else if (unary_exp->child->name == "unary_operator") {
		string op = unary_exp->child->left->name;
		varNode rnode = praser_unary_expression(unary_exp->left->right);
		if (op == "+") {

			if (rnode.type != "int" && rnode.type != "double")
				error(unary_exp->left->left->line, "operator '+' can only used to int or double");
			return rnode;
		}
		else if (op == "-") {

			if (rnode.type != "int" && rnode.type != "double")
				error(unary_exp->left->left->line, "operator '-' can only used to int or double");

			string tempzeroname = "temp" + inttostr(innerCode.tempNum);
			++innerCode.tempNum;
			varNode newzeronode = createTempVar(tempzeroname, rnode.type);
			blockStack.back().varMap.insert({ tempzeroname,newzeronode });
			innerCode.addCode(tempzeroname + " := #0");

			string tempname = "temp" + inttostr(innerCode.tempNum);
			++innerCode.tempNum;
			varNode newnode = createTempVar(tempname, rnode.type);
			blockStack.back().varMap.insert({ tempname,newnode });


			if (rnode.useAddress) {
				innerCode.addCode(tempname + " := " + tempzeroname + " - *" + rnode.name);
			}
			else {
				innerCode.addCode(tempname + " := " + tempzeroname + " - " + innerCode.getNodeName(rnode));
			}
			return newnode;
		}
		else if (op == "~") {

		}
		else if (op == "!") {

		}
	}
    else if(unary_exp->child->name == "SIZEOF")
    {

    }
}
varNode Praser::praser_postfix_expression(ParseTree* postfix_exp)
{

}

void Praser::praser_argument_expression_list(ParseTree* argument_exp, string func_name)
{
    ParseTree* argument_list = argument_exp->child;
    funcNode func = func_map[func_name];
    int count = 0;
    while(argument_list->name == "argument_expression_list")
    {
        varNode arg = praser_assignment_expression(argument_list->next_sibling->next_sibling);
        argument_list = argument_list->child;
        codePrinter.addCode(codePrinter.createCodeforArgument(arg));
        count++;
        if (func.param_list[func.param_list.size() - count].type != arg.type) {
			error(argument_list->line, "Wrong type arguments to function " + func_name);
		}
    }
    varNode arg = praser_assignment_expression(argument_list->next_sibling->next_sibling);
    codePrinter.addCode(codePrinter.createCodeforArgument(arg));
    count++;
    if (func.param_list[func.param_list.size() - count].type != arg.type) {
		error(argument_list->line, "Wrong type arguments to function " + func_name);
	}
    if (count != func.param_list.size()) {
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
    cout<<"Error line:"<<line_number<<endl;
    cout<<err_message<<endl;
    exit(1);
}