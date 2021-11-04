#include "list.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
template <typename T>
List<T>::List()
{
    head=new ListNode<T>;
    last=head;
    head->next=nullptr;
    //cout<<"List crated"<<endl;
}
template <typename T>
List<T>::List(const T&x)
{
    head=new ListNode<T>(x);
    last=head;
    head=nullptr;
    //cout<<"List crated"<<endl;
}
template <typename T>
List<T>::~List()
{
    makeEmpty();
}
template <typename T>
void List<T>::makeEmpty()
{
    //摧毁链表
    ListNode<T> *now;
    while(head->next!=nullptr)
    {
        now=head->next;
        head->next=now->next;
        delete now;
    }
}
template <typename T>
int List<T>::Length()
{
    int account=0;
    ListNode<T> *p=head->next;//从头节点后面一个开始计数
    while(p!=nullptr)
    {
        p=p->next;
        account++;
    }
    return account;
}
template <typename T>
ListNode<T>* List<T>::getNextLast() const
{//返回倒数第二个结点
    ListNode<T> *now = head->next;
    if(now->next==last)
        return nullptr;
    while(now->next!=last)
        now=now->next;
    return now;

}
template <typename T>
ListNode<T>* List<T>::Search(const T&x)
{//从头到尾一次寻找，如果寻找到，返回指针位置，如果没有找到返回空指针
    ListNode<T> *now=head->next;//跳过头节点
    while(now->next!=nullptr)
    {
        now=now->next;
        if(now->data==x)
            return now;
    }
    return nullptr;
}
template <typename T>
ListNode<T>* List<T>::Locate(int i)
{
    //定位第i个元素位置，如果总共没有i个，那么返回now=nullptr；如果找到了第i个位置，返回地址值
    ListNode<T> *now=head;
    int k=0;
    while(now->next!=nullptr&&k<i)
    {
        k++;now=now->next;
    }
    return now;
}
template <typename T>
int List<T>::Find(const T&x)
{
    {//从头到尾一次寻找，如果寻找到，返回是第几个，如果没有找到返回-1
        ListNode<T> *now=head->next;//跳过头节点
        int num=1;
        while(now->next!=nullptr)
        {
            num++;
            now=now->next;
            if(now->data==x)
                return num;
        }
        return -1;
    }
}
template <typename T>
bool List<T>::Insert(int i,const T&x)
{
    //定位到i-1的位置，然后插入元素
    ListNode<T>* now=Locate(i-1);
    ListNode<T>* in=new ListNode<T>(x);
    if(in==nullptr)
    {
        cerr<<"插入失败！！！"<<endl;
        return false;
    }
    in->next=now->next;
    now->next=in;
    return true;
}
template <typename T>
bool List<T>::Push_back(const T&x)
{//在尾部插入节点，需要尾部指针指向差人元素，next空间指向NULL
    ListNode<T>* in=new ListNode<T>(x);
    //cout<<"3"<<endl;
    if(in==nullptr)
    {
        cerr<<"插入失败！！！"<<endl;
        return false;
    }
    in->next=last;
    last->next=in;
    last=in;
    last->next=nullptr;
    //cout<<"pushover"<<endl;
    return true;
}
template <typename T>
bool List<T>::Remove(const T&x)
{
    //找到改元素所在的位置，找到改元素前一个节点位置和该元素位置
    if(isEmpty())
    {
        cerr<<"链表为空！！！"<<endl;
        return false;
    }
    int i=Find(x);
    ListNode<T> *now=Locate(i-1);
    ListNode<T> *del=Locate(i);
    now->next=del->next;
    delete del;
    if(last==del)//如果删除的结点是最后一个结点
    {
        delete del;
        last=now;
        return true;
    }
    return true;
}
template <typename T>
bool List<T>::Pop()
{
    //删除最后一个结点，如果只有一个结点，删除该节点并将last=head
    //如果有多个节点，定位到倒数第二个结点，然后删除最后一个，将last等于倒数第二个结点
   ListNode<T> *now=head->next;
   ListNode<T> *del;
   if(isEmpty())
   {
       cerr<<"链表为空！！！"<<endl;
       return false;
   }
   if(now->next==nullptr)
   {
       del=last;
       last=head;
       delete del;
       return true;
   }
  now=getNextLast();
  del=last;
  now->next=nullptr;
  delete del;
  last=now;
  last->next=nullptr;
  return true;
}
template <typename T>
bool List<T>::isEmpty()
{
    if(head->next==nullptr)
    {
        cerr<<"链表为空！！！"<<endl;
        return true;
    }
    else
        return false;
}
template <typename T>
bool List<T>::RemovePos(int i)
{
    //定位到i-1的位置，然后删除元素
    //找到改元素所在的位置，找到改元素前一个节点位置和该元素位置
    if(isEmpty())
    {
        cerr<<"链表为空！！！"<<endl;
        return false;
    }
    ListNode<T> *now=Locate(i-1);
    ListNode<T> *del=Locate(i);
    now->next=del->next;
    delete del;
    if(last==del)//如果删除的结点是最后一个结点
    {
        delete del;
        last=now;
        return true;
    }
    return true;
}
template <typename T>
void List<T>::Display()
{//跳过头节点，遍历
    ListNode<T>* now=head->next;
    //cout<<"2"<<endl;
    while(now!=nullptr)
    {
        cout<<now->data<<endl;
        now=now->next;
    }
}
template <typename T>
bool List<T>::SaveFile(const char FileName[])
{
    //首先定义存文件的对象
     //打开文件，如果打开文件失败，提示打开失败
    ListNode<T> *now=head->next;
    ofstream fout;
    fout.open(FileName);
    if(fout.fail())
    {
        cerr<<"打开文件失败！！！"<<endl;
        return false;
    }
    while(now->next!=nullptr)
        fout<<now->data<<endl;
    return true;
}
template <typename T>
bool List<T>::ReadFile(const char FileName[])
{
    T in;
    ifstream fin;
    fin.open(FileName);
    if(fin.fail())
    {
        cerr<<"打开文件失败！！！"<<endl;
        exit(1);
    }
    while (fin>>in)
    {
        Push_back(in);
       // cout<<"gogogo"<<endl;
    }
    return true;
}
