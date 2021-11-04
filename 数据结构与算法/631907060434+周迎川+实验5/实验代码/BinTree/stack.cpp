#include "stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T>
bool ListStack<T>::Push(T &x)
{
    //入栈就是链表的前插，链表的头指针就是top指针
    ListNode<T> *newnode=new ListNode<T>(x);
    if(newnode==nullptr)
        cerr<<"分配储存错误！！！"<<endl;
    newnode->next=top;
    top=newnode;
    return true;
}
template <typename T>
bool ListStack<T>::Pop(T &x)
{
    //如果链式栈为空，则不能Pop返回false
    if(IsEmpty())
        return false;
    ListNode<T> *now=top;
    top=now->next;
    x=now->data;
    delete now;
    return true;
}
template <typename T>
bool ListStack<T>::getTop(T &x) const
{
    //如果链式栈为空，返回false
    if(IsEmpty())
        return false;
    x=top->data;
    return false;
}
template <typename T>
void ListStack<T>::makeEmpty()
{
    //如果说现在的指针不是指向nullptr，则还可以继续删除
    ListNode<T> *now;
    while(top!=nullptr)
    {
        now=top;
        top=top->next;
        delete now;
    }
}
template <typename T>
bool ListStack<T>::IsEmpty() const
{
    //如果说链式栈的top指针指向nullptr则为空
    if(top==nullptr)
       return true;
    else
        return false;
}
template <typename T>
int ListStack<T>::getSize() const
{
    ListNode<T> *now=top;
    int account=0;
    while(now!=nullptr)
    {
        account++;
        now=now->next;
    }
    return account;
}
//template <typename T>
//ostream& operator<<(ostream &out,ListStack<T> &s)
//{
//    out<<s.data<<endl;
//}
