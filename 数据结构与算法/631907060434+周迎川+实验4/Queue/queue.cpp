#include <iostream>
#include "queue.h"
#include <cstdlib>
using namespace std;
template <typename T>
ListQueue<T>::ListQueue()
{
    front=nullptr;last=nullptr;//构造函数，将头指针和尾部指针NULL
}
template <typename T>
ListQueue<T>::~ListQueue<T>()
{
    makeEmpty();
}
template <typename T>
void ListQueue<T>::EnQueue(T &x)
{
    //如果分配内存失败，提示
    //如果是插入第一个结点，必须特殊处理
    ListNode<T> *newnode=new ListNode<T>(x);
    if(newnode==nullptr)
        cerr<<"内存分配失败！！！"<<endl;
    if(front==nullptr)
         front=last=newnode;
    else
    {
        last->next=newnode;
        last=newnode;
    }
}
template <typename T>
bool ListQueue<T>::DeQueue(T &x)
{
    //判断队列是否为空，如果为空，提示队列为空
    //如果部为空，出队列从前往后出队列，并且删除队头结点
    if(IsEmpty())
    {
        cout<<"队列为空！！！"<<endl;
         return false;
    }
    ListNode<T> *now=front;
    front=front->next;
    x=now->data;
    delete now;
    return true;
}
template <typename T>
bool ListQueue<T>::IsEmpty()
{
    //如果front的地址值不为空则队列不为空
    if(front==nullptr)
        return true;
    else
        return false;
}
template <typename T>
bool ListQueue<T>::getFront(T &x)
{
    if(!IsEmpty())
    {
         x=front->data;
         return true;
    }
    return false;

}
template <typename T>
int ListQueue<T>::getSize()
{
    ListNode<T> *now=front;
    int length=0;
    while(now!=nullptr)
    {
        length++;
        now=now->next;
    }
    return length;
}
template <typename T>
bool ListQueue<T>::makeEmpty()
{
     ListNode<T> *now=front;
     while(now!=nullptr)
     {
         front=front->next;
         delete now;
         now=front;
     }
     return true;
}
template <typename T>
ListNode<T>* ListQueue<T>::returnFront()
{
    return front;
}
