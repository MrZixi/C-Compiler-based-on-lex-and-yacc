#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct varNode
{
    //global then true
    bool global_or_local;
    bool useAddress = false;
    string boolValue;  
    string name, type;
    int count = -1;
    //const then true
    bool isConst = false;
};

struct arrayNode
{
    //global then true
    bool global_or_local;  
    string name, type;
    int count = -1;
};

struct funcNode
{
    //global then true
     bool global_or_local;  
     bool is_defined;
     string name;
     string return_type;
     vector<varNode> param_list;
};

class block
{
    public:
        bool isFunc;            //if this block is a function
        funcNode _func;             //if so, funcNode of it
        map<string, struct varNode> _var_map;
        map<string, struct arrayNode> _array_map;
        string gotoLabel;//label name to goto when end
        bool breakable;//if this is a process that can be break
};
#endif