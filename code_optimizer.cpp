#include "code_optimizer.h"
#include<set>
CodeOptimizer::CodeOptimizer(vector<string> codeList)
{
    establishTempMap(codeList);
    dropTemp(codeList);
}

CodeOptimizer::~CodeOptimizer()
{

}
vector<string> CodeOptimizer::getCodeList()
{
    return codeList;
}
void CodeOptimizer::establishTempMap(vector<string>& codeList)
{
    for(int i = 0;i < codeList.size();i++)
    {
        string temp_code = codeList[i];
        int begin_pos = 0;
        int begin = temp_code.find("temp", begin_pos);
     
        while(begin != string::npos)
        {
            int end = temp_code.find(" ", begin);
            string temp_name = temp_code.substr(begin, end - begin);
            if(tempMap.find(temp_name) != tempMap.end())
            {
                if(temp_code.find("CALL") != string::npos)
                {
                    //gurantee that it won't be optimized
                    tempMap[temp_name].num += 2;
                }
                tempMap[temp_name].num++;
            }
            else
            {
                tempMessage message;
                message.line = i;
                message.num = 1;
                tempMap.insert({temp_name, message});
            }

            begin = end;
            begin_pos = temp_code.find("temp", begin);
        }

    }
}
void CodeOptimizer::dropTemp(vector<string>& codeList)
{
    set<int>dropLine;
    for(auto it = tempMap.begin();it != tempMap.end();it++)
    {
        if(it->second.num == 1)
        {
            dropLine.insert(it->second.line);
        }
    }
    for(int i = 0;i < codeList.size();i++)
    {
        if(dropLine.find(i) == dropLine.end())
        {
            this->codeList.push_back(codeList[i]);
        }
    }
}