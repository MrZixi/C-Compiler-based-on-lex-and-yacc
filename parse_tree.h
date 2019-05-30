#ifndef _PARSE_TREE_H_
#define _PARSE_TREE_H_
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

extern char *yytext;
extern int yylineo;




class ParseTree
{
public:
    string content;             //终结符内容
    string name;                //符号名称
    int line;                   //代码所在行数
    ParseTree *child;           //子节点
    ParseTree *next_sibling;    //兄弟节点
    ParseTree(string name, int num, ...);
    ParseTree();
    ~ParseTree();
    void levalTrase();
    ofstream file;
    void eval(ParseTree* p,int level);
};

#endif