#ifndef _CODE_PRINTER_H_
#define _CODE_PRINTER_H_
#include <iostream>
#include <vector>
#include <string>
#include "parse_tree.h"
#include "code_optimizer.h"
#include "block.h"
using namespace std;

class CodePrinter
{
    private:
        vector<string> CodeList;
    public:
        int temp_var_count, array_count, var_count, label_count;

        CodePrinter();
        void printCode();
        void addCode(string);

        string createCodeforVar(string, string, varNode, varNode);
	    string createCodeforAssign(varNode,varNode);
	    string createCodeforParameter(varNode);
	    string createCodeforReturn(varNode);
	    string createCodeforArgument(varNode);

	    string getNodeName(varNode);
        string getNodeType(varNode);
	    string getarrayNodeName(arrayNode);
	    string getLabelName();
};

#endif