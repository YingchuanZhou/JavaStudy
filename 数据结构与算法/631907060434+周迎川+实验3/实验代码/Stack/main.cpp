#include <iostream>
#include <cstring>
#include "stack.h"
#include "stack.cpp"
using namespace std;
int main()
{
    char x[100], temp;
    ListStack<char> Ls;//字符栈
    cout<<"输入字符串"<<endl;
    cin>>x;
    unsigned int len=strlen(x);
    //入栈
    for(unsigned int i=0;i<len;i++)
        Ls.Push(x[i]);
    //读取栈顶元素
    Ls.getTop(temp);
    cout<<"栈顶元素"<<temp<<endl;
    cout<<"栈的长度"<<Ls.getSize()<<endl;
    //出栈
    while(Ls.IsEmpty()==false)
    {
        char x;
        Ls.Pop(x);
        cout<<x<<endl;
    }

    //括号匹配
    char expression[100];
    ListStack<char> Le;//括号栈
    cout<<"输入括号"<<endl;
    cin>>expression;
    len=strlen(expression);
    for(unsigned i=0;i<len;i++)
    {
        if(expression[i]=='(')
            Le.Push(expression[i]);
        else if(expression[i]==')')
        {
            if(Le.Pop(temp))
               cout<<"有与第"<<i+1<<"个括号匹配的括号！！！"<<endl;
            else
                cout<<"没有与第"<<i+1<<"个括号匹配的括号！！！"<<endl;
        }
    }
    if(!Le.IsEmpty())
        cout<<"还有“（”没有匹配"<<endl;
    return 0;
}
