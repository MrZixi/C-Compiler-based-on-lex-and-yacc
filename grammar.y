%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

%token <pt> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_FLOAT CONSTANT_CHAR
%token <pt> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <pt> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <pt> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token <pt> XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token <pt> TYPEDEF EXTERN STATIC AUTO REGISTER
%token <pt> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token <pt> STRUCT UNION ENUM ELLIPSIS

%token <pt> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token <pt> ';' ',' ':' '=' '[' ']' '.' '&' '!' '~' '-' '+' '*' '/' '%' '<' '>' '^' '|' '?' '{' '}' '(' ')' 

%token <pt> BOOL COMPLEX IMAGINARY INLINE RESTRICT

%type <pt> primary_expression postfix_expression argument_expression_list unary_expression unary_operator
%type <pt> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type <pt> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <pt> assignment_expression assignment_operator expression constant_expression

%type <pt> declaration init_declarator_list init_declarator type_specifier type_name type_qualifier specifier_qualifier_list struct_declarator_list

%type <pt> declarator pointer cast_expression conditional_expression declaration_specifiers storage_class_specifier
    
%type <pt> parameter_list parameter_declaration identifier_list direct_abstract_declarator struct_declaration struct_declarator
%type <pt> abstract_declarator initializer initializer_list struct_or_union_specifier struct_or_union struct_declaration_list
%type <pt> statement labeled_statement compound_statement expression_statement enum_specifier enumerator_list direct_declarator enumerator
%type <pt> selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition 
%type <pt> declaration_list parameter_type_list type_qualifier_list statement_list


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
    | CONSTANT_CHAR {
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
        $$ = new ParseTree("postfix_expression", 3, $1, $2, $3);
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
        $$ = new ParseTree("multiplicative_expression", 3, $1, $2, $3);
    }
	| multiplicative_expression '/' cast_expression {
        $$ = new ParseTree("multiplicative_expression", 3, $1, $2, $3);
    }
	| multiplicative_expression '%' cast_expression {
        $$ = new ParseTree("multiplicative_expression", 3, $1, $2, $3);
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
	| expression ',' assignment_expression {
        $$ = new ParseTree("expression", 3, $1, $2, $3);
    }
	;

constant_expression: 
    conditional_expression {
        $$ = new ParseTree("constant_expression", 1, $1);
    }
	;

declaration: 
    declaration_specifiers ';' {
        $$ = new ParseTree("declaration", 2, $1, $2);
    }
	| declaration_specifiers init_declarator_list ';' {
        $$ = new ParseTree("declaration", 3, $1, $2, $3);
    }
	;

declaration_specifiers: 
    storage_class_specifier {
        $$ = new ParseTree("declaration_specifer", 1, $1);
    }
	| storage_class_specifier declaration_specifiers {
        $$ = new ParseTree("declaration_specifer", 2, $1, $2);
    }
	| type_specifier {
        $$ = new ParseTree("declaration_specifer", 1, $1);
    }
	| type_specifier declaration_specifiers {
        $$ = new ParseTree("declaration_specifer", 2, $1, $2);
    }
	| type_qualifier {
        $$ = new ParseTree("declaration_specifer", 1, $1);
    }
	| type_qualifier declaration_specifiers {
        $$ = new ParseTree("declaration_specifer", 2, $1, $2);
    }
	;

init_declarator_list: 
    init_declarator {
        $$ = new ParseTree("init_declarator_list", 1, $1);
    }
	| init_declarator_list ',' init_declarator {
        $$ = new ParseTree("init_declarator_list", 3, $1, $2, $3);
    }
	;

init_declarator: 
    declarator{
        $$ = new ParseTree("init_declarator", 1, $1);
    }
	| declarator '=' initializer {
        $$ = new ParseTree("init_declarator", 3, $1, $2, $3);
    }
	;

storage_class_specifier: 
    TYPEDEF {
        $$ = new ParseTree("storage_class_specifier", 1, $1);
    }
	| EXTERN {
        $$ = new ParseTree("storage_class_specifier", 1, $1);
    }
	| STATIC {
        $$ = new ParseTree("storage_class_specifier", 1, $1);
    }
	| AUTO {
        $$ = new ParseTree("storage_class_specifier", 1, $1);
    }
	| REGISTER {
        $$ = new ParseTree("storage_class_specifier", 1, $1);
    }
	;

type_specifier: 
    VOID {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| CHAR {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| SHORT {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| INT {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| LONG {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| FLOAT {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| DOUBLE {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| SIGNED {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| UNSIGNED {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| struct_or_union_specifier {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| enum_specifier {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	| TYPE_NAME {
        $$ = new ParseTree("type_specifier", 1, $1);
    }
	;

struct_or_union_specifier: 
    struct_or_union IDENTIFIER '{' struct_declaration_list '}' {
        $$ = new ParseTree("struct_or_union_specifier", 5, $1, $2, $3, $4, $5);
    }
	| struct_or_union '{' struct_declaration_list '}' {
        $$ = new ParseTree("struct_or_union_specifier", 4, $1, $2, $3, $4);
    }
	| struct_or_union IDENTIFIER {
        $$ = new ParseTree("struct_or_union_specifier", 2, $1, $2);
    }
	;

struct_or_union: 
    STRUCT {
        $$ = new ParseTree("struct_or_union", 1, $1);
    }
	| UNION {
        $$ = new ParseTree("struct_or_union", 1, $1);
    }
	;

struct_declaration_list: 
    struct_declaration {
        $$ = new ParseTree("struct_declaration_list", 1, $1);
    }
	| struct_declaration_list struct_declaration {
        $$ = new ParseTree("struct_declaration_list", 2, $1, $2);
    }
	;

struct_declaration: 
    specifier_qualifier_list struct_declarator_list ';' {
        $$ = new ParseTree("struct_declaration", 3, $1, $2, $3);
    }
	;

specifier_qualifier_list: 
    type_specifier specifier_qualifier_list {
        $$ = new ParseTree("specifier_qualifier_list", 2, $1, $2);
    }
	| type_specifier {
        $$ = new ParseTree("specifier_qualifier_list", 1, $1);
    }
	| type_qualifier specifier_qualifier_list {
        $$ = new ParseTree("specifier_qualifier_list", 2, $1, $2);
    }
	| type_qualifier {
        $$ = new ParseTree("specifier_qualifier_list", 1, $1);
    }
	;

struct_declarator_list: 
    struct_declarator {
        $$ = new ParseTree("struct_declarator_list", 1, $1);
    }
	| struct_declarator_list ',' struct_declarator {
        $$ = new ParseTree("struct_declarator_list", 3, $1, $2, $3);
    }
	;

struct_declarator: 
    declarator {
        $$ = new ParseTree("struct_declarator", 1, $1);
    }
	| ':' constant_expression {
        $$ = new ParseTree("struct_declarator", 2, $1, $2);
    }
	| declarator ':' constant_expression {
        $$ = new ParseTree("struct_declarator_list", 3, $1, $2, $3);
    }
	;

enum_specifier: 
    ENUM '{' enumerator_list '}' {
        $$ = new ParseTree("enum_specifier", 4, $1, $2, $3, $4);
    }
	| ENUM IDENTIFIER '{' enumerator_list '}' {
        $$ = new ParseTree("enum_specifier", 5, $1, $2, $3, $4 ,$5);
    }
	| ENUM IDENTIFIER {
        $$ = new ParseTree("enum_specifier", 2, $1, $2);
    }
	;

enumerator_list: 
    enumerator {
        $$ = new ParseTree("enum_list", 1, $1);
    }
	| enumerator_list ',' enumerator {
        $$ = new ParseTree("enum_list", 3, $1, $2, $3);
    }
	;

enumerator: 
    IDENTIFIER {
        $$ = new ParseTree("enumerator", 1, $1);
    }
	| IDENTIFIER '=' constant_expression {
        $$ = new ParseTree("enumerator", 3, $1, $2, $3);
    }
	;

type_qualifier: 
    CONST {
        $$ = new ParseTree("type_qualifier", 1, $1);
    }
	| VOLATILE {
        $$ = new ParseTree("type_qualifier", 1, $1);
    }
    ;

declarator: 
    pointer direct_declarator {
        $$ = new ParseTree("declarator", 2, $1, $2);
    }
	| direct_declarator {
        $$ = new ParseTree("declarator", 1, $1);
    }
	;

direct_declarator: 
    IDENTIFIER {
        $$ = new ParseTree("direct_declarator", 1, $1);
    }
	| '(' declarator ')' {
        $$ = new ParseTree("direct_declarator", 3, $1, $2, $3);
    }
	| direct_declarator '[' constant_expression ']' {
        $$ = new ParseTree("direct_declarator", 4, $1, $2, $3, $4);
    }
	| direct_declarator '[' ']' {
        $$ = new ParseTree("direct_declarator", 3, $1, $2, $3);
    }
	| direct_declarator '(' parameter_type_list ')' {
        $$ = new ParseTree("direct_declarator", 4, $1, $2, $3, $4);
    }
	| direct_declarator '(' identifier_list ')' {
        $$ = new ParseTree("direct_declarator", 4, $1, $2, $3, $4);
    }
	| direct_declarator '(' ')' {
        $$ = new ParseTree("direct_declarator", 3, $1, $2, $3);
    }
	;

pointer: 
    '*' {
        $$ = new ParseTree("pointer", 1, $1);
    }
	| '*' type_qualifier_list {
        $$ = new ParseTree("pointer", 2, $1, $2);
    }
	| '*' pointer {
        $$ = new ParseTree("pointer", 2, $1, $2);
    }
	| '*' type_qualifier_list pointer {
        $$ = new ParseTree("pointer", 3, $1, $2, $3);
    }
	;

type_qualifier_list: 
    type_qualifier {
        $$ = new ParseTree("type_qualifier_list", 1, $1);
    }
	| type_qualifier_list type_qualifier {
        $$ = new ParseTree("type_qualifier_list", 2, $1, $2);
    }
	;

parameter_type_list: 
    parameter_list {
        $$ = new ParseTree("parameter_type_list", 1, $1);
    }
	| parameter_list ',' ELLIPSIS {
        $$ = new ParseTree("parameter_type_list", 3, $1, $2, $3);
    }
	;

parameter_list: 
    parameter_declaration {
        $$ = new ParseTree("parameter_list", 1, $1);
    }
	| parameter_list ',' parameter_declaration {
        $$ = new ParseTree("parameter_list", 3, $1, $2, $3);
    }
	;

parameter_declaration: 
    declaration_specifiers declarator {
        $$ = new ParseTree("parameter_declaration", 2, $1, $2);
    }
	| declaration_specifiers abstract_declarator {
        $$ = new ParseTree("parameter_declaration", 2, $1, $2);
    }
	| declaration_specifiers {
        $$ = new ParseTree("parameter_declaration", 1, $1);
    }
	;

identifier_list: 
    IDENTIFIER {
        $$ = new ParseTree("identifier_list", 1, $1);
    }
	| identifier_list ',' IDENTIFIER {
        $$ = new ParseTree("identifier_list", 3, $1, $2, $3);
    }
	;

type_name: 
    specifier_qualifier_list {
        $$ = new ParseTree("type_name", 1, $1);
    }
	| specifier_qualifier_list abstract_declarator {
        $$ = new ParseTree("type_name", 2, $1, $2);
    }
	;

abstract_declarator: 
    pointer {
        $$ = new ParseTree("abstract_declarator", 1, $1);
    }
	| direct_abstract_declarator {
        $$ = new ParseTree("abstract_declarator", 1, $1);
    }
	| pointer direct_abstract_declarator {
        $$ = new ParseTree("abstract_declarator", 2, $1, $2);
    }
	;

direct_abstract_declarator: 
    '(' abstract_declarator ')' {
        $$ = new ParseTree("direct_abstract_declarator", 3, $1, $2, $3);
    }
	| '[' ']' {
        $$ = new ParseTree("direct_abstract_declarator", 2, $1, $2);
    }
	| '[' constant_expression ']' {
        $$ = new ParseTree("direct_abstract_declarator", 3, $1, $2, $3);
    }
	| direct_abstract_declarator '[' ']' {
        $$ = new ParseTree("direct_abstract_declarator", 3, $1, $2, $3);
    }
	| direct_abstract_declarator '[' constant_expression ']' {
        $$ = new ParseTree("direct_abstract_declarator", 4, $1, $2, $3, $4);
    }
	| '(' ')' {
        $$ = new ParseTree("direct_abstract_declarator", 2, $1, $2);
    }
	| '(' parameter_type_list ')' {
        $$ = new ParseTree("direct_abstract_declarator", 3, $1, $2, $3);
    }
	| direct_abstract_declarator '(' ')' {
        $$ = new ParseTree("direct_abstract_declarator", 3, $1, $2, $3);
    }
	| direct_abstract_declarator '(' parameter_type_list ')' {
        $$ = new ParseTree("direct_abstract_declarator", 4, $1, $2, $3, $4);
    }
	;

initializer: 
    assignment_expression {
        $$ = new ParseTree("initializer", 1, $1);
    }
	| '{' initializer_list '}' {
        $$ = new ParseTree("initializer", 3, $1, $2, $3);
    }
	| '{' initializer_list ',' '}' {
        $$ = new ParseTree("initializer", 4, $1, $2, $3, $4);
    }
	;

initializer_list: 
    initializer {
        $$ = new ParseTree("initializer_list", 1, $1);
    }
	| initializer_list ',' initializer {
        $$ = new ParseTree("initializer_list", 3, $1, $2, $3);
    }
	;

statement: 
    labeled_statement {
        $$ = new ParseTree("statement", 1, $1);
    }
	| compound_statement {
        $$ = new ParseTree("statement", 1, $1);
    }
	| expression_statement {
        $$ = new ParseTree("statement", 1, $1);
    }
	| selection_statement {
        $$ = new ParseTree("statement", 1, $1);
    }
	| iteration_statement {
        $$ = new ParseTree("statement", 1, $1);
    }
	| jump_statement {
        $$ = new ParseTree("statement", 1, $1);
    }
	;

labeled_statement: 
    IDENTIFIER ':' statement {
        $$ = new ParseTree("labeled_statement", 3, $1, $2, $3);
    }
	| CASE constant_expression ':' statement {
        $$ = new ParseTree("labeled_statement", 4, $1, $2, $3, $4);
    }
	| DEFAULT ':' statement {
        $$ = new ParseTree("labeled_statement", 3, $1, $2, $3);
    }
	;

compound_statement: 
    '{' '}' {
        $$ = new ParseTree("compound_statement", 2, $1, $2);
    }
	| '{' statement_list '}' {
        $$ = new ParseTree("compound_statement", 3, $1, $2, $3);
    }
	| '{' declaration_list '}' {
        $$ = new ParseTree("compound_statement", 3, $1, $2, $3);
    }
	| '{' declaration_list statement_list '}' {
        $$ = new ParseTree("compound_statement", 4, $1, $2, $3, $4);
    }
	;

declaration_list: 
    declaration {
        $$ = new ParseTree("declaration_list", 1, $1);
    }
	| declaration_list declaration {
        $$ = new ParseTree("declaration_list", 2, $1, $2);
    }
	;

statement_list: 
    statement {
        $$ = new ParseTree("statement_list", 1, $1);
    }
	| statement_list statement {
        $$ = new ParseTree("statement_list", 2, $1, $2);
    }
	;

expression_statement: 
    ';' {
        $$ = new ParseTree("expression_statement", 1, $1);
    }
	| expression ';' {
        $$ = new ParseTree("expression_statement", 2, $1, $2);
    }
	;

selection_statement: 
    IF '(' expression ')' statement {
        $$ = new ParseTree("selection_statement", 5, $1, $2, $3, $4, $5);
    }
	| IF '(' expression ')' statement ELSE statement {
        $$ = new ParseTree("selection_statement", 7, $1, $2, $3, $4, $5, $6, $7);
    }
	| SWITCH '(' expression ')' statement {
        $$ = new ParseTree("selection_statement", 5, $1, $2, $3, $4, $5);
    }
	;

iteration_statement: 
    WHILE '(' expression ')' statement {
        $$ = new ParseTree("iteration_statement", 5, $1, $2, $3, $4, $5);
    }
	| DO statement WHILE '(' expression ')' ';' {
        $$ = new ParseTree("iteration_statement", 7, $1, $2, $3, $4, $5, $6, $7);
    }
	| FOR '(' expression_statement expression_statement ')' statement {
        $$ = new ParseTree("iteration_statement", 6, $1, $2, $3, $4, $5, $6);
    }
	| FOR '(' expression_statement expression_statement expression ')' statement {
        $$ = new ParseTree("iteration_statement", 7, $1, $2, $3, $4, $5, $6, $7);
    }
	| FOR '(' declaration expression_statement ')' statement {
        $$ = new ParseTree("iteration_statement", 6, $1, $2, $3, $4, $5, $6);
    }
	| FOR '(' declaration expression_statement expression ')' statement {
        $$ = new ParseTree("iteration_statement", 7, $1, $2, $3, $4, $5, $6, $7);
    }
	;

jump_statement: 
    GOTO IDENTIFIER ';' {
        $$ = new ParseTree("jump_statement", 3, $1, $2, $3);
    }
	| CONTINUE ';' {
        $$ = new ParseTree("jump_statement", 2, $1, $2);
    }
	| BREAK ';' {
        $$ = new ParseTree("jump_statement", 2, $1, $2);
    }
	| RETURN ';' {
        $$ = new ParseTree("jump_statement", 2, $1, $2);
    }
	| RETURN expression ';' {
        $$ = new ParseTree("jump_statement", 3, $1, $2, $3);
    }
	;

translation_unit: 
    external_declaration {
        $$ = new ParseTree("translation_unit", 1, $1);
    }
	| translation_unit external_declaration {
        $$ = new ParseTree("translation_unit", 2, $1, $2);
    }
	;

external_declaration: 
    function_definition {
        $$ = new ParseTree("external_declaration", 1, $1);
    }
	| declaration {
        $$ = new ParseTree("external_declaration", 1, $1);
    }
	;

function_definition: 
    declaration_specifiers declarator declaration_list compound_statement {
        $$ = new ParseTree("function_definition", 4, $1, $2, $3, $4);
    }
	| declaration_specifiers declarator compound_statement {
        $$ = new ParseTree("function_definition", 3, $1, $2, $3);
    }
    ;

%%

void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


int main(int argc,char* argv[]) {

	yyin = fopen(argv[1],"r");
	
	yyparse();
	printf("\n");

    root->levalTrase();

	fclose(yyin);
	return 0;
}
