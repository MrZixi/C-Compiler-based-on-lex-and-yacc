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
	class ParseTree pt;
}

%token <pt> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_FLOAT
%token <pt> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP


