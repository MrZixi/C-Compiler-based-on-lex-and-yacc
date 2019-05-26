#ifndef _CODE_OPTIMIZER_H
#define _CODE_OPTIMIZER_H
#include<string>
#include<vector>
#include<map>
using namespace std;
struct tempMessage
{
    int line;
    int num = -1;
};
class CodeOptimizer
{
private:
    vector<string> codeList;
    map<string, tempMessage>tempMap;
    void establishTempMap(vector<string>&);
    void dropTemp(vector<string>&);
public:
    CodeOptimizer(vector<string>);
    ~CodeOptimizer();
    vector<string> getCodeList();
};



#endif