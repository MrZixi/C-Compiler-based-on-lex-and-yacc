#ifndef _CODE_OPTIMIZER_H
#define _CODE_OPTIMIZER_H
#include<string>
#include<vector>
using namespace std;
class CodeOptimizer
{
private:
    /* data */
public:
    CodeOptimizer(vector<string>);
    ~CodeOptimizer();
    vector<string> getCodeList();
};



#endif