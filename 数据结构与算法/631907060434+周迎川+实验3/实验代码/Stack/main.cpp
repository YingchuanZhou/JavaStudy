#include <iostream>
#include <cstring>
#include "stack.h"
#include "stack.cpp"
using namespace std;
int main()
{
    char x[100], temp;
    ListStack<char> Ls;//�ַ�ջ
    cout<<"�����ַ���"<<endl;
    cin>>x;
    unsigned int len=strlen(x);
    //��ջ
    for(unsigned int i=0;i<len;i++)
        Ls.Push(x[i]);
    //��ȡջ��Ԫ��
    Ls.getTop(temp);
    cout<<"ջ��Ԫ��"<<temp<<endl;
    cout<<"ջ�ĳ���"<<Ls.getSize()<<endl;
    //��ջ
    while(Ls.IsEmpty()==false)
    {
        char x;
        Ls.Pop(x);
        cout<<x<<endl;
    }

    //����ƥ��
    char expression[100];
    ListStack<char> Le;//����ջ
    cout<<"��������"<<endl;
    cin>>expression;
    len=strlen(expression);
    for(unsigned i=0;i<len;i++)
    {
        if(expression[i]=='(')
            Le.Push(expression[i]);
        else if(expression[i]==')')
        {
            if(Le.Pop(temp))
               cout<<"�����"<<i+1<<"������ƥ������ţ�����"<<endl;
            else
                cout<<"û�����"<<i+1<<"������ƥ������ţ�����"<<endl;
        }
    }
    if(!Le.IsEmpty())
        cout<<"���С�����û��ƥ��"<<endl;
    return 0;
}
