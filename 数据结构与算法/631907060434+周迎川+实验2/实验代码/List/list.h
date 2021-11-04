#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
template <typename T>
struct ListNode
{
    T data;
    ListNode *next;
    ListNode(ListNode<T> *ptr=nullptr)//���캯��
    {
        next=ptr;
       // cout<<"Listnode created"<<endl;
    }
    ListNode(const T&data,ListNode<T> *ptr=nullptr)//���캯��
    {
        this->data=data;next=ptr;
        //cout<<"LIstnode created"<<endl;
    }
};
template <typename T>
class List
{
private:
    ListNode<T> *head,*last;
public:
    List();//���캯��
    List(const T&x);//���캯��
    ~List();//��������
    void makeEmpty();//���������
    int Length();//��ȡ������
    ListNode<T> *getNextLast() const;//��ȡ�����ڶ���Ԫ��ָ��
    ListNode<T> *Search(const T&x);//����Ԫ��λ��
    ListNode<T> *Locate(const int i);//��ȡ��i��Ԫ�ص�λ��
    int Find(const T&x);//�ҵ�x�ǵڼ����ڵ�
    bool Insert(int i,const T &x);//�ڵ�i��λ�ò���Ԫ��
    bool Push_back(const T&x);//β������Ԫ��
    bool Remove(const T &x);//ɾ��ָ��Ԫ��
    bool Pop();//ɾ�����һ��Ԫ��
    bool isEmpty();//�п�
    bool RemovePos(int pos);//ɾ��ָ��λ��Ԫ��
    void Display();//��ʾ������
    bool SaveFile(const char FileName[]);//�����ļ�
    bool ReadFile(const char FileName[]);//��ȡ�ļ�
};

#endif // LIST_H
