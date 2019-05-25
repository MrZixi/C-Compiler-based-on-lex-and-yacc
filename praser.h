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
        vector<block> blockStack;
        CodePrinter codePrinter;
        
        void init();
                                                         //arithmatic expressions       
        varNode praser_assignment_expression(ParseTree*);			
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
	    varNode praser_unary_expression(ParseTree*);
	    varNode praser_postfix_expression(ParseTree*);

        void praser_argument_expression_list(ParseTree*, string);
        bool lookup_var_in_current_block(string);

        void error(int, string);
        
    public:
        Praser(ParseTree*);
        ~Praser();
};

#endif