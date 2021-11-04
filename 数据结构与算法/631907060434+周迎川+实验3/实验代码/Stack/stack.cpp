#include "stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T>
bool ListStack<T>::Push(T &x)
{
    //��ջ���������ǰ�壬�����ͷָ�����topָ��
    ListNode<T> *newnode=new ListNode<T>(x);
    if(newnode==nullptr)
        cerr<<"���䴢����󣡣���"<<endl;
    newnode->next=top;
    top=newnode;
    return true;
}
template <typename T>
bool ListStack<T>::Pop(T &x)
{
    //�����ʽջΪ�գ�����Pop����false
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
    //�����ʽջΪ�գ�����false
    if(IsEmpty())
        return false;
    x=top->data;
    return false;
}
template <typename T>
void ListStack<T>::makeEmpty()
{
    //���˵���ڵ�ָ�벻��ָ��nullptr���򻹿��Լ���ɾ��
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
    //���˵��ʽջ��topָ��ָ��nullptr��Ϊ��
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
