#include "hashtable.h"
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
template <typename T>
HashTable<T>::HashTable(long long d, int size)
{
    TableSize=size;divisor=d;
    head=new ChainNode<T> *[size];
    if(head==nullptr)
        cerr<<"内存分配失败!!!"<<endl;
    for(int i=0;i<size;i++)
        head[i]=new ChainNode<T>(i,"","");
}
template <typename T>
ChainNode<T>* HashTable<T>::FindPos(T elem)
{
    int i=elem/divisor%10;
    ChainNode<T> *p=head[i];
    if(p!=nullptr)
        return p;
    else
        return nullptr;
}
template <typename T>
bool HashTable<T>::Insert(T elem,string n,string a)
{
    ChainNode<T> *p=FindPos(elem);
//    if(p==nullptr)
//        cout<<"kong"<<endl;
//    else
//        cout<<"bukong"<<endl;
    ChainNode<T> *q=new ChainNode<T>(elem,n,a);
    if(q==nullptr)
    {
        cerr<<"内存分配失败！！！"<<endl;
        return false;
    }
    q->next=p->next;
    p->next=q;
    return true;
}
template <typename T>
bool HashTable<T>::Remove(T elem)
{
    ChainNode<T> *p=FindPos(elem), *q=p;
    if(p==nullptr)
    {
        cerr<<"不存在该元素！！！"<<endl;
        return false;
    }
    if(p->data==elem)//如果元素是第一个元素
    {
        q=p->next;
        delete p;
    }
    while (p!=nullptr && p->data!=elem) {
        q=p;p=p->next;
    }
    q->next=p->next;
    delete p;
    return true;

}
template <typename  T>
bool HashTable<T>::Search(T elem)
{
    ChainNode<T> *p=FindPos(elem);
    while (p->next!=nullptr && p->data!=elem) {
        p=p->next;
    }
    if(p==nullptr)
        return false;
    else
        return true;
}
template <typename T>
void HashTable<T>::Display()
{
    ChainNode<T> *p;
    for(int i=0;i<TableSize;i++)
    {
        p=head[i]->next;
        while (p!=nullptr) {
            cout<<p->name<<" "<<p->data<<" "<<p->address<<endl;
            p=p->next;
        }
    }
}
