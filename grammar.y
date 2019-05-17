%{
#include <cstdlib>
#include <cstdio>
#include <string>
#include "parse_tree.h"

using namespace std;

extern char *yytext;
extern int column;
extern FILE * yyin;
extern FILE * yyout;
extern int yylineno;

class ParseTree *root;

int yylex(void);
void yyerror(const char*); 
%}

%union{
	class ParseTree *pt;
}

%token <pt> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_FLOAT
%token <pt> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <pt> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <pt> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token <pt> XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token <pt> TYPEDEF EXTERN STATIC AUTO REGISTER
%token <pt> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token <pt> STRUCT UNION ENUM ELLIPSIS

%token <pt> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN


%%

Program:translation_unit {
    root = new ParseTree("Program", 1, $1);
};

primary_expression: 
    IDENTIFIER {
        $$ = new ParseTree("primary_expression", 1, $1);
    }
	| CONSTANT_INT{
        $$ = new ParseTree("primary_expression", 1, $1);
    }
    | CONSTANT_FLOAT {
        $$ = new ParseTree("primary_expression", 1 ,$1);
    }
	| STRING_LITERAL {
        $$ = new ParseTree("primary_expression", 1, $1);
    }
	| '(' expression ')' {
        $$ = new ParseTree("primary_expression", 3,  $1, $2, $3);
    }
	;

postfix_expression: 
    primary_expression {
        $$ = new ParseTree("postfix_expression", 1, $1);
    }
	| postfix_expression '[' expression ']' {
        $$ = new ParseTree("postfix_expression", 4, $1, $2, $3, $4);
    }
	| postfix_expression '(' ')' {
        $$ = new ParseTree("postfix_expression", 3, $1, $2, $3); 
    }
	| postfix_expression '(' argument_expression_list ')' {
        $$ = new ParseTree("postfix_expression", 4, $1, $2, $3, $4);
    }
	| postfix_expression '.' IDENTIFIER {
        $$ = new ParseTree("postfix_expression", 3, $1, $2, $3); 
    }
	| postfix_expression PTR_OP IDENTIFIER {
        $$ = new ParseTree("postfix_expression", 4, $1, $2, $3, $4);
    }
	| postfix_expression INC_OP {
        $$ = new ParseTree("postfix_expression", 2, $1, $2);
    }
	| postfix_expression DEC_OP {
        $$ = new ParseTree("postfix_expression", 2, $1, $2);
    }
	;

argument_expression_list: 
    assignment_expression {
        $$ = new ParseTree("argument_experssion_list", 1, $1);
    }
	| argument_expression_list ',' assignment_expression {
        $$ = new ParseTree("argument_expression_list", 3, $1, $2 ,$3);
    }
	;

unary_expression: 
    postfix_expression {
        $$ = new ParseTree("unary_expression", 1, $1);
    }
	| INC_OP unary_expression {
        $$ = new ParseTree("unary_expression", 2, $1, $2);
    }
	| DEC_OP unary_expression {
        $$ = new ParseTree("unary_expression", 2, $1, $2);
    }
	| unary_operator cast_expression {
        $$ = new ParseTree("unary_expression", 2, $1, $2);
    }
	| SIZEOF unary_expression {
        $$ = new ParseTree("unary_expression", 2, $1, $2);
    }
	| SIZEOF '(' type_name ')' {
        $$ = new ParseTree("unary_expression", 4, $1, $2, $3, $4);
    }
    ;

unary_operator:
    '&' {
        $$ = new ParseTree("unary_operator", 1, $1);
    }
	| '*' {
        $$ = new ParseTree("unary_operator", 1, $1);
    }
	| '+' {
        $$ = new ParseTree("unary_operator", 1, $1);
    }
	| '-' {
        $$ = new ParseTree("unary_operator", 1, $1);
    }
	| '~' {
        $$ = new ParseTree("unary_operator", 1, $1);
    }
	| '!' {
        $$ = new ParseTree("unary_operator", 1, $1);
    }
	;

cast_expression: 
    unary_expression {
        $$ = new ParseTree("cast_expression", 1 ,$1);
    }
	| '(' type_name ')' cast_expression {
        $$ = new ParseTree("cast_expression", 4, $1, $2, $3, $4);
    }
	;

multiplicative_expression: 
    cast_expression {
        $$ = new ParseTree("multiplicative_expression", 1 ,$1);
    }
	| multiplicative_expression '*' cast_expression {
        $$ = new ParseTree("multiplicative_expression", 4, $1, $2, $3, $4);
    }
	| multiplicative_expression '/' cast_expression {
        $$ = new ParseTree("multiplicative_expression", 4, $1, $2, $3, $4);
    }
	| multiplicative_expression '%' cast_expression {
        $$ = new ParseTree("multiplicative_expression", 4, $1, $2, $3, $4);
    }
	;

additive_expression: 
    multiplicative_expression {
        $$ = new ParseTree("additive_expression", 1, $1);
    }
	| additive_expression '+' multiplicative_expression {
        $$ = new ParseTree("additive_expression", 3, $1, $2, $3);
    }
	| additive_expression '-' multiplicative_expression {
        $$ = new ParseTree("additive_expression", 3, $1, $2, $3);
    }
    ;

shift_expression: 
    additive_expression {
        $$ = new ParseTree("shift_expression", 1, $1);
    }
	| shift_expression LEFT_OP additive_expression {
        $$ = new ParseTree("shift_expression", 3, $1, $2, $3);
    }
	| shift_expression RIGHT_OP additive_expression {
        $$ = new ParseTree("shift_expression", 3, $1, $2, $3);
    }
    ;

relational_expression: 
    shift_expression {
        $$ = new ParseTree("relational_expression", 1, $1);
    }
	| relational_expression '<' shift_expression {
        $$ = new ParseTree("relational_expression", 3, $1, $2, $3);
    }
	| relational_expression '>' shift_expression {
        $$ = new ParseTree("relational_expression", 3, $1, $2, $3);
    }
	| relational_expression LE_OP shift_expression {
        $$ = new ParseTree("relational_expression", 3, $1, $2, $3);
    }
	| relational_expression GE_OP shift_expression {
        $$ = new ParseTree("relational_expression", 3, $1, $2, $3);
    }
	;

equality_expression: 
    relational_expression {
        $$ = new ParseTree("equality_expression", 1, $1);
    }
	| equality_expression EQ_OP relational_expression {
        $$ = new ParseTree("equality_expression", 3, $1, $2, $3);
    }
	| equality_expression NE_OP relational_expression {
        $$ = new ParseTree("equality_expression", 1, $1, $2, $3);
    }
	;

and_expression: 
    equality_expression {
        $$ = new ParseTree("and_expression", 1, $1);
    }
	| and_expression '&' equality_expression {
        $$ = new ParseTree("and_expression", 3, $1, $2, $3);
    }
    ;

exclusive_or_expression: 
    and_expression {
        $$ = new ParseTree("exclusive_or_expression", 1, $1);
    }
	| exclusive_or_expression '^' and_expression {
        $$ = new ParseTree("exclusive_or_expression", 3, $1, $2, $3);
    }
	;

inclusive_or_expression: 
    exclusive_or_expression {
        $$ = new ParseTree("inclusive_or_expression", 1, $1);
    }
	| inclusive_or_expression '|' exclusive_or_expression {
        $$ = new ParseTree("inclusive_or_expression", 3, $1, $2, $3);
    }
	;

logical_and_expression:
    inclusive_or_expression {
        $$ = new ParseTree("logical_and_expression", 1, $1);
    }
	| logical_and_expression AND_OP inclusive_or_expression {
        $$ = new ParseTree("logical_and_expression", 3, $1, $2, $3);
    }
	;

logical_or_expression: 
    logical_and_expression  {
        $$ = new ParseTree("logical_or_expression", 1, $1);
    }
	| logical_or_expression OR_OP logical_and_expression {
        $$ = new ParseTree("logical_or_expression", 3, $1, $2, $3);
    }
	;

conditional_expression: 
    logical_or_expression {
        $$ = new ParseTree("conditional_expression", 1, $1);
    }
	| logical_or_expression '?' expression ':' conditional_expression {
        $$ = new ParseTree("conditional_expression", 5, $1, $2, $3, $4, $5);
    }
	;

assignment_expression: 
    conditional_expression {
        $$ = new ParseTree("assignment_expression", 1, $1);
    }
	| unary_expression assignment_operator assignment_expression {
        $$ = new ParseTree("conditional_expression", 3, $1, $2, $3);
    }
    ;

assignment_operator: 
    '=' {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| MUL_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| DIV_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| MOD_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| ADD_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| SUB_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| LEFT_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| RIGHT_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| AND_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| XOR_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	| OR_ASSIGN {
        $$ = new ParseTree("assignment_operator", 1, $1);
    }
	;

expression: 
    assignment_expression {
        $$ = new ParseTree("expression", 1, $1);
    }
	| expression ',' assignment_expression
	;
