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
}
varNode Praser::praser_assignment_expression(ParseTree* assign_exp)
{

}
varNode Praser::praser_logical_or_expression(ParseTree* logical_or_exp)
{

}
varNode Praser::praser_logical_and_expression(ParseTree* logical_and_exp)
{

}	
varNode Praser::praser_inclusive_or_expression(ParseTree*)
{

}
varNode Praser::praser_exclusive_or_expression(ParseTree*)
{

}
varNode Praser::praser_and_expression(ParseTree*)
{

}
varNode Praser::praser_equality_expression(ParseTree*)
{

}
varNode Praser::praser_relational_expression(ParseTree*)
{

}
varNode Praser::praser_shift_expression(ParseTree*)
{

}
varNode Praser::praser_additive_expression(ParseTree*)
{

}
varNode Praser::praser_multiplicative_expression(ParseTree*)
{

}
varNode Praser::praser_unary_expression(ParseTree*)
{

}
varNode Praser::praser_postfix_expression(ParseTree*)
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
}

bool Praser::lookup_var_in_current_block(string name)
{

}

void Praser::error(int line_number, string err_message)
{
    cout<<"Error line:"<<line_number<<endl;
    cout<<err_message<<endl;
    exit(1);
}