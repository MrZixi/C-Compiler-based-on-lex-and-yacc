#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct varNode
{

};

struct arrayNode
{

};

struct funcNode
{

};

class block
{
    public:
        bool isFunc;            //if this block is a function
        funcNode _func;             //if so, funcNode
        map<string, struct varNode> _var_map;
        map<string, struct arrayNode> _array_map;
        string gotoLabel;//label name to goto when end
        bool breakable;//if this is a process that can be break
};
#endif