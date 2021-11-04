#include <iostream>
#include "queue.h"
#include <cstdlib>
using namespace std;
template <typename T>
ListQueue<T>::ListQueue()
{
    front=nullptr;last=nullptr;//���캯������ͷָ���β��ָ��NULL
}
template <typename T>
ListQueue<T>::~ListQueue<T>()
{
    makeEmpty();
}
template <typename T>
void ListQueue<T>::EnQueue(T &x)
{
    //��������ڴ�ʧ�ܣ���ʾ
    //����ǲ����һ����㣬�������⴦��
    ListNode<T> *newnode=new ListNode<T>(x);
    if(newnode==nullptr)
        cerr<<"�ڴ����ʧ�ܣ�����"<<endl;
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
    //�ж϶����Ƿ�Ϊ�գ����Ϊ�գ���ʾ����Ϊ��
    //�����Ϊ�գ������д�ǰ��������У�����ɾ����ͷ���
    if(IsEmpty())
    {
        cout<<"����Ϊ�գ�����"<<endl;
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
    //���front�ĵ�ֵַ��Ϊ������в�Ϊ��
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
