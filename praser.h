#ifndef _PRASER_H_
#define _PRASER_H

#include "block.h"
#include "parse_tree.h"
#include "code_printer.h"
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

class Praser{
    private:
        ParseTree* root;
        map<string, funcNode>func_map;
        map<string, string>op_math_map;
        vector<block> blockStack;
        CodePrinter codePrinter;
        
        void init();
                                                                                //jzy
        void praser_parameter_list(ParseTree*,string,bool);			//获取函数形参列表
	    void praser_parameter_declaration(ParseTree*, string,bool);	//获取函数单个形参
        void praser_expression_statement(ParseTree*);
	    varNode praser_expression(ParseTree*);      
                                                              //lcx
        void praser_argument_expression_list(ParseTree*, string);
                                            //jzy
        void praser_jump_statement(ParseTree*);
	    void praser_compound_statement(ParseTree*);
	    void praser_selection_statement(ParseTree*);
	    void praser_iteration_statement(ParseTree*);
                                                         //arithmatic expressions:lcx       
        varNode praser_assignment_expression(ParseTree*);		
        varNode praser_conditional_expression(ParseTree*);	
	    varNode praser_logical_or_expression(ParseTree*);			
	    varNode praser_logical_and_expression(ParseTree*);	
	    varNode praser_inclusive_or_expression(ParseTree*);
	    varNode praser_exclusive_or_expression(ParseTree*);
	    varNode praser_and_expression(ParseTree*);
	    varNode praser_equality_expression(ParseTree*);
	    varNode praser_relational_expression(ParseTree*);
	    varNode praser_shift_expression(ParseTree*);
	    varNode praser_additive_expression(ParseTree*);
	    varNode praser_multiplicative_expression(ParseTree*);
        varNode praser_cast_expression(ParseTree*);
	    varNode praser_unary_expression(ParseTree*);
	    varNode praser_postfix_expression(ParseTree*);

        
        bool lookup_var_in_current_block(string);
        varNode createTempVar(string, string);
        void error(int, string);
        
    public:
        Praser(ParseTree*);
        ~Praser();
};

#endif