#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template <typename T>
class Stack
{
public:
    Stack()//���캯��
    {}
    virtual bool Push(T &x)=0;//��ջ
    virtual bool Pop(T &x)=0;//��ջ
    virtual bool getTop(T &x) const=0;//��ȡջ��Ԫ��
    virtual bool IsEmpty() const=0;//�п�
    virtual int getSize() const = 0;//����ջ�ĳ���
};
template <typename T>
struct ListNode//��������
{
    T data;
    ListNode<T> *next;
    ListNode(const T &x,ListNode<T> *ptr=nullptr)//����������
    {
        data=x; next=ptr;
    }
};

template <typename T>
class ListStack: public Stack<T>
{
private:
    ListNode<T> *top;
public:
    ListStack()//���캯��������ʽջ��topָ�븳ֵΪ��
    {
        top=nullptr;
    }
    ~ListStack()//��������������ʽջ��Ϊ��
    {
        makeEmpty();
    }
    bool Push(T &x);//��ջ
    bool Pop(T &x);//��ջ
    bool getTop(T &x) const;//��ȡջ��Ԫ��
    void makeEmpty();//�ÿ�
    bool IsEmpty()const;//�п�
    int getSize()const;//��ȡ��ʽջ�ĳ���
    //friend ostream& operator<<(ostream &out,ListStack<T> &s);
};
#endif // STACK_H
