#include "hashtable_close.h"
#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T>
HashTable_C<T>::HashTable_C(long long d,int size)
{
    divisor=d;tablesize=size;cursize=0;
    ht=new Node<T>[size];
    info=new status[size];
    if(ht==nullptr || info==nullptr)
        cerr<<"分配内存错误！！！"<<endl;
    for(int i=0;i<size;i++)
        info[i]=Empty;
}
template <typename T>
int HashTable_C<T>::FindPos(T elem)
{
    int i=(elem/divisor)%10;
    int j=i;
    do{
        if(info[j]==Empty || (info[j]==Active && ht[j].data==elem))
            return j;
        j=(j+1)%tablesize;
    }while(j!=i);
    return i;//找不到
}
template <typename T>
bool HashTable_C<T>::Insert(T elem,string n,string a)
{
    int i=FindPos(elem);
    if(i==-1|| cursize==tablesize)
        return false;
    if(info[i]!=Active)
    {
        ht[i].data=elem;
        ht[i].name=n;
        ht[i].address=a;
        info[i]=Active;
        cursize++;
        return true;
    }
    if(info[i]==Active && ht[i].data==elem)
    {
        cout<<"元素已经存在"<<endl;
        return false;
    }
    return false;
}
template <typename T>
bool HashTable_C<T>::Remove(T elem)
{
    int i=FindPos(elem);
    if(info[i]==Active && ht[i].data==elem)
    {
        info[i]=Deleted;cursize--;
        return true;
    }
    else
        return false;
}
template <typename T>
bool HashTable_C<T>::Search(T elem)
{
    int i=FindPos(elem);
    if(ht[i].data==elem)
        return true;
    else
        return false;
}
template <typename T>
void HashTable_C<T>::Display()
{
    for(int i=0;i<tablesize;i++)
    {
        if(info[i]==Active)
            cout<<ht[i].name<<" "<<ht[i].data<<"  "<<ht[i].address<<endl;
    }
}
