#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template <typename T>
class Stack
{
public:
    Stack()//构造函数
    {}
    virtual bool Push(T &x)=0;//入栈
    virtual bool Pop(T &x)=0;//出栈
    virtual bool getTop(T &x) const=0;//读取栈顶元素
    virtual bool IsEmpty() const=0;//判空
    virtual int getSize() const = 0;//计算栈的长度
};
template <typename T>
struct ListNode//链表结点类
{
    T data;
    ListNode<T> *next;
    ListNode(const T &x,ListNode<T> *ptr=nullptr)//构造链表结点
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
    ListStack()//构造函数，将链式栈的top指针赋值为空
    {
        top=nullptr;
    }
    ~ListStack()//析构函数，将链式栈置为空
    {
        makeEmpty();
    }
    bool Push(T &x);//入栈
    bool Pop(T &x);//出栈
    bool getTop(T &x) const;//读取栈顶元素
    void makeEmpty();//置空
    bool IsEmpty()const;//判空
    int getSize()const;//获取链式栈的长度
    //friend ostream& operator<<(ostream &out,ListStack<T> &s);
};
#endif // STACK_H
