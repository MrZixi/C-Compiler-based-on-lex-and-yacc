#include "parse_tree.h"

ParseTree::ParseTree(string name, int num, ...)
{
    va_list valist;
    this->child = NULL;
    this->next_sibling = NULL;
    this->content = "";
    this->name = name;
    ParseTree *temp = NULL;
    va_start(valist, num);
    if (num > 0)
    {
        temp = va_arg(valist, ParseTree *);
        this->child = temp;
        this->line = temp->line;
        //如果只有一个子节点
        if (num == 1)
        {
            //如果是终结符
            if (temp->content.size() > 0)
            {
                this->content = temp->content;
            }
            else
            {
                this->content = "";
            }
        }
        //如果有不止一个子节点
        else
        {
            for (int i = 0; i < num - 1; i++)
            {
                // cout << "child" << i << temp->name << endl;;
                temp->next_sibling = va_arg(valist, ParseTree *);
                temp = temp->next_sibling;
            }
        }
    }
    else
    {
        int line = va_arg(valist, int);
        this->line = line;
        if (this->name == "CONSTANT_INT")
        {
            int value;
            //8进制
            if (strlen(yytext) > 1 && yytext[0] == '0' && yytext[1] != 'x' && yytext[1] != 'X')
            {
                sscanf(yytext, "%o", &value);
            }
            //16进制
            else if (strlen(yytext) > 1 && yytext[0] == '0' && (yytext[1] == 'x' || yytext[1] == 'X'))
            {
                sscanf(yytext, "%x", &value);
            }
            //10进制
            else
            {
                value = atoi(yytext);
            }
            this->content = to_string(value);
        }
        else if (this->name == "CONSTANT_FLOAT")
        {
            this->content = yytext;
        }
        else if (this->name == "STRING_LITERAL")
        {
            this->content = yytext;
        }
        else if (this->name == "IDENTIFIER")
        {
            this->content = yytext;
        }
        else
        {
            this->content = yytext;
        }
    }
}

ParseTree::ParseTree()
{
    child = NULL;
    next_sibling = NULL;
    content = "";
    name = "";
}

ParseTree::~ParseTree()
{
}

void ParseTree::levalTrase()
{
    // if (this != NULL) {
    //     cout << this->name << " ";
    //     if(this->content != "") {
    //         cout << "content:"<< this->content <<" ";
    //     }
    // }
    // if (this->next_sibling != NULL) {
    //     this->next_sibling->levalTrase();
    // }
    // cout << endl;
    // this->next_sibling->levalTrase();
    int front, rear;
    ParseTree *que[40960];
    front = rear = 0;
    ParseTree *p, *q;
    if (this != NULL)
    {
        rear++;
        que[rear] = this;
        while (front != rear)
        {
            front++;
            q = que[front];
            cout << q->name;
            p = q->child;
            while (p != NULL)
            {
                cout << "-" <<p->name;
                rear++;
                que[rear] = p;
                p = p->next_sibling;
            }
            cout << endl;
        }
    }
}