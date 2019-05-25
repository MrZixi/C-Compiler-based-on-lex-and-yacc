%{
#include <iostream>
#include <stdio.h>
#include "grammar.tab.h"
#include "parse_tree.h"

void count();
void comment();
int check_type();
int column = 0;

%}

%option yylineno

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			([Ee][+-]?{D}+)
P           ([Pp][+-]?{D}+)
FS			(f|F|l|L)
IS          ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%%

"/*"([^"*"]|("*")*[^"*/"])*("*")*"*/"			{ comment(); }
"//"[^\n]*      { /* consume //-comment */ }


"auto"			{ count(); yylval.pt = new ParseTree("auto", 0, yylineno); return(AUTO); }
"_Bool"			{ count(); yylval.pt = new ParseTree("bool", 0, yylineno); return(BOOL); }
"break"			{ count(); yylval.pt = new ParseTree("break", 0, yylineno); return(BREAK); }
"case"			{ count(); yylval.pt = new ParseTree("case", 0, yylineno); return(CASE); }
"char"			{ count(); yylval.pt = new ParseTree("char", 0, yylineno); return(CHAR); }
"_Complex"		{ count(); yylval.pt = new ParseTree("complex", 0, yylineno); return(COMPLEX); }
"const"			{ count(); yylval.pt = new ParseTree("const", 0, yylineno); return(CONST); }
"continue"		{ count(); yylval.pt = new ParseTree("continue", 0, yylineno); return(CONTINUE); }
"default"		{ count(); yylval.pt = new ParseTree("default", 0, yylineno); return(DEFAULT); }
"do"			{ count(); yylval.pt = new ParseTree("do", 0, yylineno); return(DO); }
"double"		{ count(); yylval.pt = new ParseTree("double", 0, yylineno); return(DOUBLE); }
"else"			{ count(); yylval.pt = new ParseTree("else", 0, yylineno); return(ELSE); }
"enum"			{ count(); yylval.pt = new ParseTree("enum", 0, yylineno); return(ENUM); }
"extern"		{ count(); yylval.pt = new ParseTree("extern", 0, yylineno); return(EXTERN); }
"float"			{ count(); yylval.pt = new ParseTree("float", 0, yylineno); return(FLOAT); }
"for"			{ count(); yylval.pt = new ParseTree("for", 0, yylineno); return(FOR); }
"goto"			{ count(); yylval.pt = new ParseTree("goto", 0, yylineno); return(GOTO); }
"if"			{ count(); yylval.pt = new ParseTree("if", 0, yylineno); return(IF); }
"_Imaginary"    { count(); yylval.pt = new ParseTree("imaginary", 0, yylineno); return(IMAGINARY); }
"inline"		{ count(); yylval.pt = new ParseTree("inline", 0, yylineno); return(INLINE); }
"int"			{ count(); yylval.pt = new ParseTree("int", 0, yylineno); return(INT); }
"long"			{ count(); yylval.pt = new ParseTree("long", 0, yylineno); return(LONG); }
"register"		{ count(); yylval.pt = new ParseTree("register", 0, yylineno); return(REGISTER); }
"restrict"		{ count(); yylval.pt = new ParseTree("restrict", 0, yylineno); return(RESTRICT); }
"return"		{ count(); yylval.pt = new ParseTree("return", 0, yylineno); return(RETURN); }
"short"			{ count(); yylval.pt = new ParseTree("short", 0, yylineno); return(SHORT); }
"signed"		{ count(); yylval.pt = new ParseTree("signed", 0, yylineno); return(SIGNED); }
"sizeof"		{ count(); yylval.pt = new ParseTree("sizeof", 0, yylineno); return(SIZEOF); }
"static"		{ count(); yylval.pt = new ParseTree("static", 0, yylineno); return(STATIC); }
"struct"		{ count(); yylval.pt = new ParseTree("struct", 0, yylineno); return(STRUCT); }
"switch"		{ count(); yylval.pt = new ParseTree("switch", 0, yylineno); return(SWITCH); }
"typedef"		{ count(); yylval.pt = new ParseTree("typedef", 0, yylineno); return(TYPEDEF); }
"union"			{ count(); yylval.pt = new ParseTree("union", 0, yylineno); return(UNION); }
"unsigned"		{ count(); yylval.pt = new ParseTree("unsigned", 0, yylineno); return(UNSIGNED); }
"void"			{ count(); yylval.pt = new ParseTree("void", 0, yylineno); return(VOID); }
"volatile"		{ count(); yylval.pt = new ParseTree("volatile", 0, yylineno); return(VOLATILE); }
"while"			{ count(); yylval.pt = new ParseTree("while", 0, yylineno); return(WHILE); }

{L}({L}|{D})*		{ count(); yylval.pt = new ParseTree("IDENTIFIER", 0, yylineno); return(check_type()); }

0[xX]{H}+{IS}?		{ count(); yylval.pt = new ParseTree("CONSTANT_INT", 0, yylineno); return(CONSTANT_INT); /*16进制*/}
0[0-7]*{IS}?		{ count(); yylval.pt = new ParseTree("CONSTANT_INT", 0, yylineno); return(CONSTANT_INT); /*8进制整数*/}
[1-9]{D}*{IS}?		{ count(); yylval.pt = new ParseTree("CONSTANT_INT", 0, yylineno); return(CONSTANT_INT); /*10进制整数*/}
L?'(\\.|[^\\'\n])+'	{ count(); yylval.pt = new ParseTree("CONSTANT_CHAR", 0, yylineno); return(CONSTANT_CHAR); }

{D}+{E}{FS}?				 { count(); yylval.pt = new ParseTree("CONSTANT_FLOAT", 0, yylineno); return(CONSTANT_FLOAT); }
{D}*"."{D}+{E}?{FS}?		 { count(); yylval.pt = new ParseTree("CONSTANT_FLOAT", 0, yylineno); return(CONSTANT_FLOAT); }
{D}+"."{D}*{E}?{FS}?		 { count(); yylval.pt = new ParseTree("CONSTANT_FLOAT", 0, yylineno); return(CONSTANT_FLOAT); }
0[xX]{H}+{P}{FS}?			 { count(); yylval.pt = new ParseTree("CONSTANT_FLOAT", 0, yylineno); return(CONSTANT_FLOAT); }
0[xX]{H}*"."{H}+{P}{FS}?     { count(); yylval.pt = new ParseTree("CONSTANT_FLOAT", 0, yylineno); return(CONSTANT_FLOAT); }
0[xX]{H}+"."{H}*{P}{FS}?     { count(); yylval.pt = new ParseTree("CONSTANT_FLOAT", 0, yylineno); return(CONSTANT_FLOAT); }


L?\"(\\.|[^\\"\n])*\"	{ count(); yylval.pt = new ParseTree("STRING_LITERAL", 0, yylineno); return(STRING_LITERAL); }

"..."			{ count(); yylval.pt = new ParseTree("ELLIPSIS", 0, yylineno); return(ELLIPSIS); }
">>="			{ count(); yylval.pt = new ParseTree("RIGHT_ASSIGN", 0, yylineno); return(RIGHT_ASSIGN); }
"<<="			{ count(); yylval.pt = new ParseTree("LEFT_ASSIGN", 0, yylineno); return(LEFT_ASSIGN); }
"+="			{ count(); yylval.pt = new ParseTree("ADD_ASSIGN", 0, yylineno); return(ADD_ASSIGN); }
"-="			{ count(); yylval.pt = new ParseTree("SUB_ASSIGN", 0, yylineno); return(SUB_ASSIGN); }
"*="			{ count(); yylval.pt = new ParseTree("MUL_ASSIGN", 0, yylineno); return(MUL_ASSIGN); }
"/="			{ count(); yylval.pt = new ParseTree("DIV_ASSIGN", 0, yylineno); return(DIV_ASSIGN); }
"%="			{ count(); yylval.pt = new ParseTree("MOD_ASSIGN", 0, yylineno); return(MOD_ASSIGN); }
"&="			{ count(); yylval.pt = new ParseTree("AND_ASSIGN", 0, yylineno); return(AND_ASSIGN); }
"^="			{ count(); yylval.pt = new ParseTree("XOR_ASSIGN", 0, yylineno); return(XOR_ASSIGN); }
"|="			{ count(); yylval.pt = new ParseTree("OR_ASSIGN", 0, yylineno); return(OR_ASSIGN); }
">>"			{ count(); yylval.pt = new ParseTree("RIGHT_OP", 0, yylineno); return(RIGHT_OP); }
"<<"			{ count(); yylval.pt = new ParseTree("LEFT_OP", 0, yylineno); return(LEFT_OP); }
"++"			{ count(); yylval.pt = new ParseTree("INC_OP", 0, yylineno); return(INC_OP); }
"--"			{ count(); yylval.pt = new ParseTree("DEC_OP", 0, yylineno); return(DEC_OP); }
"->"			{ count(); yylval.pt = new ParseTree("PTR_OP", 0, yylineno); return(PTR_OP); }
"&&"			{ count(); yylval.pt = new ParseTree("AND_OP", 0, yylineno); return(AND_OP); }
"||"			{ count(); yylval.pt = new ParseTree("OR_OP", 0, yylineno); return(OR_OP); }
"<="			{ count(); yylval.pt = new ParseTree("LE_OP", 0, yylineno); return(LE_OP); }
">="			{ count(); yylval.pt = new ParseTree("GE_OP", 0, yylineno); return(GE_OP); }
"=="			{ count(); yylval.pt = new ParseTree("EQ_OP", 0, yylineno); return(EQ_OP); }
"!="			{ count(); yylval.pt = new ParseTree("NE_OP", 0, yylineno); return(NE_OP); }
";"				{ count(); yylval.pt = new ParseTree(";", 0, yylineno); return(';'); }
("{"|"<%")		{ count(); yylval.pt = new ParseTree("{", 0, yylineno); return('{'); }
("}"|"%>")		{ count(); yylval.pt = new ParseTree("}", 0, yylineno); return('}'); }
","				{ count(); yylval.pt = new ParseTree(",", 0, yylineno); return(','); }
":"				{ count(); yylval.pt = new ParseTree(":", 0, yylineno); return(':'); }
"="				{ count(); yylval.pt = new ParseTree("=", 0, yylineno); return('='); }
"("				{ count(); yylval.pt = new ParseTree("(", 0, yylineno); return('('); }
")"				{ count(); yylval.pt = new ParseTree(")", 0, yylineno); return(')'); }
("["|"<:")		{ count(); yylval.pt = new ParseTree("[", 0, yylineno); return('['); }
("]"|":>")		{ count(); yylval.pt = new ParseTree("]", 0, yylineno); return(']'); }
"."				{ count(); yylval.pt = new ParseTree(".", 0, yylineno); return('.'); }
"&"				{ count(); yylval.pt = new ParseTree("&", 0, yylineno); return('&'); }
"!"				{ count(); yylval.pt = new ParseTree("!", 0, yylineno); return('!'); }
"~"				{ count(); yylval.pt = new ParseTree("~", 0, yylineno); return('~'); }
"-"				{ count(); yylval.pt = new ParseTree("-", 0, yylineno); return('-'); }
"+"				{ count(); yylval.pt = new ParseTree("+", 0, yylineno); return('+'); }
"*"				{ count(); yylval.pt = new ParseTree("*", 0, yylineno); return('*'); }
"/"				{ count(); yylval.pt = new ParseTree("/", 0, yylineno); return('/'); }
"%"				{ count(); yylval.pt = new ParseTree("%", 0, yylineno); return('%'); }
"<"				{ count(); yylval.pt = new ParseTree("<", 0, yylineno); return('<'); }
">"				{ count(); yylval.pt = new ParseTree(">", 0, yylineno); return('>'); }
"^"				{ count(); yylval.pt = new ParseTree("^", 0, yylineno); return('^'); }
"|"				{ count(); yylval.pt = new ParseTree("|", 0, yylineno); return('|'); }
"?"				{ count(); yylval.pt = new ParseTree("?", 0, yylineno); return('?'); }

[ \t\v\n\f]		{ count(); }
.				{ /* Add code to complain about unmatched characters */ }

%%


int yywrap()
{
	return 1;
}


void comment()
{
	// char c, prev = 0;
  
	// while (cin >> c)      /* (EOF maps to 0) */
	// {
	// 	if (c == '/' && prev == '*')
	// 		return;
	// 	prev = c;
	// }
	// // error("unterminated comment");
	 cout << "/*comment*/";
}


void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return TYPE_NAME;
*
*	return IDENTIFIER;
*/

/*
*	it actually will only return IDENTIFIER
*/

	return IDENTIFIER;
}