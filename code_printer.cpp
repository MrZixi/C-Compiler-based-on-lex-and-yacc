#include "code_printer.h"
#include <fstream>
CodePrinter::CodePrinter()
{
    temp_var_count = 0;
    array_count = 0;
    var_count = 0;
    label_count = 0;
}

void CodePrinter::addCode(string s)
{
    CodeList.push_back(s);
}

void CodePrinter::printCode()
{
    CodeOptimizer code_optimizer(CodeList);
    CodeList = code_optimizer.getCodeList();
    ofstream out("IR.txt");
    for(string s:CodeList)
    {
        out<<s<<endl;
    }
}

string CodePrinter::createCodeforVar(string tempname, string op, varNode node1, varNode node2)
{
    string result;
    result = tempname + " = " + getNodeName(node1) + " " + op + " " + getNodeName(node2);
    return result;
}
string CodePrinter::createCodeforAssign(varNode node1, varNode node2)
{ 
    string result;
    result = getNodeName(node1) + " = " + getNodeName(node2);
    return result;
}
string CodePrinter::createCodeforParameter(varNode node)
{
    string result = "LOAD_PARAM ";
    result += getNodeName(node);
    return result;
}
string CodePrinter::createCodeforReturn(varNode node)
{
    string result;
    result += "RETURN " + getNodeType(node) + " " + getNodeName(node);
    return result;
}
string CodePrinter::createCodeforArgument(varNode node)
{
    string result = "PASS ";
    result += getNodeName(node);
    return result;
}

string CodePrinter::getNodeName(varNode node)
{
    if (node.useAddress) {
		return "*" + node.name;
	}
	else {
		if (node.count < 0) {
			return node.name;
		}
		else return "var" + to_string(node.count);
	}
}

string CodePrinter::getNodeType(varNode node)
{
   if(node.type.compare("int") == 0)
    {
        return "I32";
    }
    else if(node.type.compare("long") == 0)
    {
        return "I32";
    }
    else if(node.type.compare("long long") == 0)
    {
        return "I64";
    }
    else if(node.type.compare("float") == 0)
    {
        return "FLOAT";
    }
    else if(node.type.compare("double") == 0)
    {
        return "DOUBLE";
    }
    else if(node.type.compare("void") == 0)
    {
        return "";
    }
    return "";
}
string CodePrinter::getarrayNodeName(arrayNode node)
{
    return "array" + to_string(array_count);
}
string CodePrinter::getLabelName()
{
    return "label" + to_string(label_count);
}