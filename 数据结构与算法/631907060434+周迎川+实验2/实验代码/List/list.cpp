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
    //�ݻ�����
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
    ListNode<T> *p=head->next;//��ͷ�ڵ����һ����ʼ����
    while(p!=nullptr)
    {
        p=p->next;
        account++;
    }
    return account;
}
template <typename T>
ListNode<T>* List<T>::getNextLast() const
{//���ص����ڶ������
    ListNode<T> *now = head->next;
    if(now->next==last)
        return nullptr;
    while(now->next!=last)
        now=now->next;
    return now;

}
template <typename T>
ListNode<T>* List<T>::Search(const T&x)
{//��ͷ��βһ��Ѱ�ң����Ѱ�ҵ�������ָ��λ�ã����û���ҵ����ؿ�ָ��
    ListNode<T> *now=head->next;//����ͷ�ڵ�
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
    //��λ��i��Ԫ��λ�ã�����ܹ�û��i������ô����now=nullptr������ҵ��˵�i��λ�ã����ص�ֵַ
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
    {//��ͷ��βһ��Ѱ�ң����Ѱ�ҵ��������ǵڼ��������û���ҵ�����-1
        ListNode<T> *now=head->next;//����ͷ�ڵ�
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
    //��λ��i-1��λ�ã�Ȼ�����Ԫ��
    ListNode<T>* now=Locate(i-1);
    ListNode<T>* in=new ListNode<T>(x);
    if(in==nullptr)
    {
        cerr<<"����ʧ�ܣ�����"<<endl;
        return false;
    }
    in->next=now->next;
    now->next=in;
    return true;
}
template <typename T>
bool List<T>::Push_back(const T&x)
{//��β������ڵ㣬��Ҫβ��ָ��ָ�����Ԫ�أ�next�ռ�ָ��NULL
    ListNode<T>* in=new ListNode<T>(x);
    //cout<<"3"<<endl;
    if(in==nullptr)
    {
        cerr<<"����ʧ�ܣ�����"<<endl;
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
    //�ҵ���Ԫ�����ڵ�λ�ã��ҵ���Ԫ��ǰһ���ڵ�λ�ú͸�Ԫ��λ��
    if(isEmpty())
    {
        cerr<<"����Ϊ�գ�����"<<endl;
        return false;
    }
    int i=Find(x);
    ListNode<T> *now=Locate(i-1);
    ListNode<T> *del=Locate(i);
    now->next=del->next;
    delete del;
    if(last==del)//���ɾ���Ľ�������һ�����
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
    //ɾ�����һ����㣬���ֻ��һ����㣬ɾ���ýڵ㲢��last=head
    //����ж���ڵ㣬��λ�������ڶ�����㣬Ȼ��ɾ�����һ������last���ڵ����ڶ������
   ListNode<T> *now=head->next;
   ListNode<T> *del;
   if(isEmpty())
   {
       cerr<<"����Ϊ�գ�����"<<endl;
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
        cerr<<"����Ϊ�գ�����"<<endl;
        return true;
    }
    else
        return false;
}
template <typename T>
bool List<T>::RemovePos(int i)
{
    //��λ��i-1��λ�ã�Ȼ��ɾ��Ԫ��
    //�ҵ���Ԫ�����ڵ�λ�ã��ҵ���Ԫ��ǰһ���ڵ�λ�ú͸�Ԫ��λ��
    if(isEmpty())
    {
        cerr<<"����Ϊ�գ�����"<<endl;
        return false;
    }
    ListNode<T> *now=Locate(i-1);
    ListNode<T> *del=Locate(i);
    now->next=del->next;
    delete del;
    if(last==del)//���ɾ���Ľ�������һ�����
    {
        delete del;
        last=now;
        return true;
    }
    return true;
}
template <typename T>
void List<T>::Display()
{//����ͷ�ڵ㣬����
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
    //���ȶ�����ļ��Ķ���
     //���ļ���������ļ�ʧ�ܣ���ʾ��ʧ��
    ListNode<T> *now=head->next;
    ofstream fout;
    fout.open(FileName);
    if(fout.fail())
    {
        cerr<<"���ļ�ʧ�ܣ�����"<<endl;
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
        cerr<<"���ļ�ʧ�ܣ�����"<<endl;
        exit(1);
    }
    while (fin>>in)
    {
        Push_back(in);
       // cout<<"gogogo"<<endl;
    }
    return true;
}
