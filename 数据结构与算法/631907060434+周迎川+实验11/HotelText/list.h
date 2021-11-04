#ifndef LIST_H
#define LIST_H
#include<iostream>
#include "infohotel.h"
using namespace std;
#include<fstream>
#endif // LIST_H
template <class T>
struct LinkNode{
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *p=nullptr)  //仅初始化指针的构造函数
    {
        link=p;
    }
    LinkNode(const T &q,LinkNode<T> *p=nullptr)   //初始化数据及指针的构造函数
    {
        data=q;
        link=p;
    }
    ~LinkNode()   //析构函数
    {
        delete [] link;
    }
};
template <class T>
class List{           //包含附加头结点
    protected:
    LinkNode<T> *head;
public:
    List()  //构造函数
    {
        head=new LinkNode<T>;  //附加头结点

    }
    List(const T &x)   //构造函数
    {
        head=new LinkNode<T>(x);   //包含附加头结点
    }
    List(List<T> &L);  //复制构造函数
    ~List()             //析构函数
    {makeEmpty();}
    void makeEmpty();  //将链表置零
    int Length()const;  //计算链表的长度
    LinkNode<T> *getHead()const {return  head;}  //返回头指针地址
    LinkNode<T> *getLast()const   //返回最后一个结点的地址
    {
        LinkNode<T> *current=head;
        while(current->link!=nullptr)   //循环找到最后一个结点
            current=current->link;
        return current;
    }
    LinkNode<T> *Search(T &x);  //无序搜索函数
    LinkNode<T> *Locate(int i); //返回第i个元素的地址
    bool getData(int i,T &x)const;//获取第i个元素的值
    void UpData(int i,T &x); //修改第i个元素的值
    void Push_back(T &x);  //将x压入尾部
    void input(); //输入
    void output(); //输出
    bool Insert(int i, T &x); //插入到第i个结点位置上
    bool Insertfront(int i, T &x); //插入到第i个结点前一项位置上
    bool Insertback(int i, T &x); //插入到第i个结点后一项位置上
    bool Remove(int i,T &X); //移除第i个结点，通过x返回该结点元素的值
    bool IsEmpty()const   //判断表空
    {
        if(head->link==nullptr)
            return  true;
        else
            return  false;
    }
    void Sort(); //冒泡排序
    void SortFrombigtosmall();
    List<T>& operator=(List<T> &L); //重载=运算符
    bool SavetoFile(const char Filename[]);  //数据保存函数
    bool ReadfromFile(const char Filename[]);  //数据读取函数

};
extern List<Room> *L;
template <class T>
List<T>::List(List<T> &L)   //复制构造函数
{
    T value;
    LinkNode<T> *p=L.getHead();
    LinkNode<T> *current=head=new LinkNode<T>;
    LinkNode<T> *x;
    while(p->link!=nullptr)  //逐个复制
    {
        value=p->link->data;
        p=p->link;          //被复制表指向下一个数据
        x=new LinkNode<T>(value);
        current->link=x;
        current=current->link;
    }
}
template <class T>
void List<T>::makeEmpty()   //将链表置零
{

    while(head->link!=nullptr)   //当链表不为空时，循环删除链表中的结点
    {
        LinkNode<T> *current;
        current=head->link;
        head->link=current->link;
        current->link=nullptr;
        delete current;
    }

}
template <class T>
int List<T>::Length()const      //计算链表长度
{
    int i=0;
    LinkNode<T> *current=head;
    while(current->link!=nullptr)
    {
        i++;
        current=current->link;
    }
    return  i;
}
template <class T>
LinkNode<T> *List<T>::Search(T &x)   //无序搜索函数
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return 0;
    }
    LinkNode<T> *current=head;
    while(current->link!=nullptr)    //遍历链表，找到与x相等的数据的结点
    {
        current=current->link;
        if(current->data==x)
            break;
    }
    if(current->data==x)   //查找到
        return  current;
    else
    {
        cout<<"未在链表中找到该数据！"<<endl;
        return 0;
    }
}
template <class T>
LinkNode<T> *List<T>::Locate(int i)   //返回第i个元素的地址
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return 0;
    }
    else if(i<=0||i>Length())   //判断i是否在链表长度范围内
    {
        cout<<"不在链表长度范围内！"<<endl;
        return 0;
    }
    else
    {
        LinkNode<T> *current=head;
        for(int j=1;j<=i;j++)    //循环找到第i个元素的结点
        {
            current=current->link;
        }
        return  current;
    }
}

template<class T>
bool List<T>::getData(int i,T &x)const   //获取第i个元素的值，通过x返回
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
       return false;
    }
    else if(i<=0||i>Length())   //判断i是否在链表长度范围内
    {
        cout<<"不在链表长度范围内！"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        for(int j=1;j<=i;j++)    //循环找到第i个元素的结点
        {
            current=current->link;
        }
        x=current->data;
        return true;
    }
}
template  <class T>
void List<T>::UpData(int i,T &x)   //修改第i个元素的值
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return;
    }
    else if(i<=0||i>Length())   //判断i是否在链表长度范围内
    {
        cout<<"不在链表长度范围内！"<<endl;
        return;
    }
    else
    {
        LinkNode<T> *current=head;
        for(int j=1;j<=i;j++)    //循环找到第i个元素的结点
        {
            current=current->link;
        }
        current->data=x;
    }
}
template <class T>
void List<T>::Push_back(T &x)     //将x压入尾部
{
    LinkNode<T> *current=getLast();  //将current指针指向最后一个结点
    LinkNode<T> *value=new LinkNode<T>(x);
    current->link=value;
}
template <class T>
void List<T>::input()  //输入
{
    int i=0;
    T x;
    cout<<"请输入要添加的结点个数：";
    cin>>i;
    LinkNode<T> *current=getLast();  //current指针指向链表最后一个结点
    LinkNode<T> *value;
    for(int j=1;j<=i;j++)
    {
        cout<<"输入第"<<j<<"个结点的数据："<<endl;
        cin>>x;
        value=new LinkNode<T>(x);
        current->link=value;
        current=current->link;
    }
}
template <class T>
void List<T>::output() //输出
{
    LinkNode<T> *current=head;
    current=current->link;
    if(IsEmpty())
    {
        cout<<"链表为空！"<<endl;
        return;
    }
    else
    {
        int i=1;
        while(current->link!=nullptr)
        {
            cout<<"第"<<i<<"个结点的数据为："<<endl<<current->data<<endl;
            i++;
            current=current->link;
        }
        cout<<"第"<<i<<"个结点的数据为："<<endl<<current->data<<endl;
    }
}
template <class T>
bool List<T>::Insert(int i,T &x) //插入到第i个结点位置上
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return false;
    }
    else if(i<=0||i>Length())   //判断i是否在链表长度范围内
    {
        cout<<"不在链表长度范围内！"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        LinkNode<T> *p;
        for(int j=1;j<i;j++)   //循环找到第i个元素结点的前一个结点
              current=current->link;
        LinkNode<T> *value=new LinkNode<T>(x);
        p=current->link;   //p指向第i个结点
        current->link=value;
        current=current->link;
        current->link=p;
        return true;
    }
}
template <class T>
bool List<T>::Insertfront(int i,T &x)//插入到第i个结点前一项位置上
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return false;
    }
    else if(i<=0||i>Length())   //判断i是否在链表长度范围内
    {
        cout<<"不在链表长度范围内！"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        LinkNode<T> *p;
        for(int j=1;j<i;j++)   //循环找到第i个元素结点的前一个结点
              current=current->link;
        LinkNode<T> *value=new LinkNode<T>(x);
        p=current->link;   //p指向第i个结点
        current->link=value;
        current=current->link;
        current->link=p;
        return true;
    }
}
template <class T>
bool List<T>::Insertback(int i,T &x)//插入到第i个结点后一项位置上
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return false;
    }
    else if(i<=0||i>Length())   //判断i是否在链表长度范围内
    {
        cout<<"不在链表长度范围内！"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        LinkNode<T> *p;
        for(int j=1;j<i+1;j++)   //循环找到第i个元素结点
              current=current->link;
        LinkNode<T> *value=new LinkNode<T>(x);
        p=current->link;   //p指向第i个结点
        current->link=value;
        current=current->link;
        current->link=p;
        return true;
    }
}
template <class T>
bool List<T>::Remove(int i,T &x) //移除第i个结点，通过x返回该结点元素的值
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return false;
    }
    else if(i<=0||i>Length())   //判断i是否在链表长度范围内
    {
        cout<<"不在链表长度范围内！"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        LinkNode<T> *p;
        for(int j=1;j<i;j++)   //循环找到第i个元素结点的前一个结点
              current=current->link;
        p=current->link;   //p指向第i个结点
        x=p->data;      //通过x返回第i个结点的元素的值
        current->link=p->link;
        p->link=nullptr;
        delete p;
        return true;
    }
}
template <class T>
void List<T>::Sort() //冒泡排序,从小到大
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return;
    }
    int i=1,j=0;
    LinkNode<T> *p;
    LinkNode<T> *q;
    T x;
    p=head;
    for(;i<this->Length();i++)
    {
        p=p->link;
        q=p;
        for(j=i+1;j<=this->Length();j++)
        {
            q=q->link;
            if(p->data>q->data)
            {
                x=p->data;
                p->data=q->data;
                q->data=x;
            }
        }

    }
}
template <class T>
List<T> &List<T>::operator=(List<T> &L)  //重载=运算符
{
    T value;
    LinkNode<T> *p=L.getHead();
    LinkNode<T> *current=head=new LinkNode<T>;
    LinkNode<T> *x;
    while(p->link!=nullptr)  //逐个复制
    {
        value=p->link->data;
        p=p->link;          //被复制表指向下一个数据
        x=new LinkNode<T>(value);
        current->link=x;
        current=current->link;
    }
}
template <class T>
bool List<T>::SavetoFile(const char filename[])   //数据保存函数
{
    ofstream out;
    out.open(filename);
    if(out.fail())
    {
        cout<<"文件打开失败！"<<endl;
        return false;
    }
    else
    {
        int i=Length();
        out<<i<<endl;    //将链表长度存入文件
        LinkNode<T> *current=head;
        while(current->link!=nullptr)
        {
            current=current->link;
            out<<current->data<<endl;
        }
        out.close();
        return true;
    }
}
template <class T>
bool List<T>::ReadfromFile(const char filename[])  //
{
    ifstream in;
    in.open(filename);
    if(in.fail())
    {
        cout<<"文件打开失败！"<<endl;
        return false;
    }
    else
    {
        int i;
        in>>i;   //读取文件中存取的链表长度
        T x;
        LinkNode<T> *current=getLast();  //current指针指向链表尾部
        LinkNode<T> *value;
        for(int j=1;j<=i;j++)    //循环创建i个结点
        {
            in>>x;
            value=new LinkNode<T>(x);
            current->link=value;
            current=current->link;
        }
        in.close();
        return true;
    }

}
//以上函数已测试
template <class T>
void List<T>::SortFrombigtosmall() //冒泡排序,从小到大
{
    if(IsEmpty())    //判断该表是否为空表
    {
        cout<<"该链表为空为链表！"<<endl;
        return;
    }
    int i=1,j=0;
    LinkNode<T> *p;
    LinkNode<T> *q;
    T x;
    p=head;
    for(;i<this->Length();i++)
    {
        p=p->link;
        q=p;
        for(j=i+1;j<=this->Length();j++)
        {
            q=q->link;
            if(p->data<q->data)
            {
                x=p->data;
                p->data=q->data;
                q->data=x;
            }
        }

    }
}
