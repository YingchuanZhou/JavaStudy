#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
template <typename T>
struct ListNode
{
    T data;
    ListNode *next;
    ListNode(ListNode<T> *ptr=nullptr)//构造函数
    {
        next=ptr;
       // cout<<"Listnode created"<<endl;
    }
    ListNode(const T&data,ListNode<T> *ptr=nullptr)//构造函数
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
    List();//构造函数
    List(const T&x);//构造函数
    ~List();//析构函数
    void makeEmpty();//将链表清空
    int Length();//获取链表长度
    ListNode<T> *getNextLast() const;//获取倒数第二个元素指针
    ListNode<T> *Search(const T&x);//搜索元素位置
    ListNode<T> *Locate(const int i);//获取第i个元素的位置
    int Find(const T&x);//找到x是第几个节点
    bool Insert(int i,const T &x);//在第i个位置插入元素
    bool Push_back(const T&x);//尾部插入元素
    bool Remove(const T &x);//删除指定元素
    bool Pop();//删除最后一个元素
    bool isEmpty();//判空
    bool RemovePos(int pos);//删除指定位置元素
    void Display();//显示整个表
    bool SaveFile(const char FileName[]);//保存文件
    bool ReadFile(const char FileName[]);//读取文件
};

#endif // LIST_H
