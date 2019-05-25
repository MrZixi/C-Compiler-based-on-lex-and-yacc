#include "code_printer.h"
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

}
string CodePrinter::createCodeforAssign(varNode node1, varNode node2)
{ 

}
string CodePrinter::createCodeforParameter(varNode node)
{

}
string CodePrinter::createCodeforReturn(varNode node)
{

}
string CodePrinter::createCodeforArgument(varNode node)
{

}

string CodePrinter::getNodeName(varNode node)
{

}
string CodePrinter::getarrayNodeName(arrayNode node)
{
    return "array" + to_string(array_count);
}
string CodePrinter::getLabelName()
{
    return "label" + to_string(label_count);
}