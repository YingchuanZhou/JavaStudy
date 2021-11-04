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
    LinkNode(LinkNode<T> *p=nullptr)  //����ʼ��ָ��Ĺ��캯��
    {
        link=p;
    }
    LinkNode(const T &q,LinkNode<T> *p=nullptr)   //��ʼ�����ݼ�ָ��Ĺ��캯��
    {
        data=q;
        link=p;
    }
    ~LinkNode()   //��������
    {
        delete [] link;
    }
};
template <class T>
class List{           //��������ͷ���
    protected:
    LinkNode<T> *head;
public:
    List()  //���캯��
    {
        head=new LinkNode<T>;  //����ͷ���

    }
    List(const T &x)   //���캯��
    {
        head=new LinkNode<T>(x);   //��������ͷ���
    }
    List(List<T> &L);  //���ƹ��캯��
    ~List()             //��������
    {makeEmpty();}
    void makeEmpty();  //����������
    int Length()const;  //��������ĳ���
    LinkNode<T> *getHead()const {return  head;}  //����ͷָ���ַ
    LinkNode<T> *getLast()const   //�������һ�����ĵ�ַ
    {
        LinkNode<T> *current=head;
        while(current->link!=nullptr)   //ѭ���ҵ����һ�����
            current=current->link;
        return current;
    }
    LinkNode<T> *Search(T &x);  //������������
    LinkNode<T> *Locate(int i); //���ص�i��Ԫ�صĵ�ַ
    bool getData(int i,T &x)const;//��ȡ��i��Ԫ�ص�ֵ
    void UpData(int i,T &x); //�޸ĵ�i��Ԫ�ص�ֵ
    void Push_back(T &x);  //��xѹ��β��
    void input(); //����
    void output(); //���
    bool Insert(int i, T &x); //���뵽��i�����λ����
    bool Insertfront(int i, T &x); //���뵽��i�����ǰһ��λ����
    bool Insertback(int i, T &x); //���뵽��i������һ��λ����
    bool Remove(int i,T &X); //�Ƴ���i����㣬ͨ��x���ظý��Ԫ�ص�ֵ
    bool IsEmpty()const   //�жϱ��
    {
        if(head->link==nullptr)
            return  true;
        else
            return  false;
    }
    void Sort(); //ð������
    void SortFrombigtosmall();
    List<T>& operator=(List<T> &L); //����=�����
    bool SavetoFile(const char Filename[]);  //���ݱ��溯��
    bool ReadfromFile(const char Filename[]);  //���ݶ�ȡ����

};
extern List<Room> *L;
template <class T>
List<T>::List(List<T> &L)   //���ƹ��캯��
{
    T value;
    LinkNode<T> *p=L.getHead();
    LinkNode<T> *current=head=new LinkNode<T>;
    LinkNode<T> *x;
    while(p->link!=nullptr)  //�������
    {
        value=p->link->data;
        p=p->link;          //�����Ʊ�ָ����һ������
        x=new LinkNode<T>(value);
        current->link=x;
        current=current->link;
    }
}
template <class T>
void List<T>::makeEmpty()   //����������
{

    while(head->link!=nullptr)   //������Ϊ��ʱ��ѭ��ɾ�������еĽ��
    {
        LinkNode<T> *current;
        current=head->link;
        head->link=current->link;
        current->link=nullptr;
        delete current;
    }

}
template <class T>
int List<T>::Length()const      //����������
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
LinkNode<T> *List<T>::Search(T &x)   //������������
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
        return 0;
    }
    LinkNode<T> *current=head;
    while(current->link!=nullptr)    //���������ҵ���x��ȵ����ݵĽ��
    {
        current=current->link;
        if(current->data==x)
            break;
    }
    if(current->data==x)   //���ҵ�
        return  current;
    else
    {
        cout<<"δ���������ҵ������ݣ�"<<endl;
        return 0;
    }
}
template <class T>
LinkNode<T> *List<T>::Locate(int i)   //���ص�i��Ԫ�صĵ�ַ
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
        return 0;
    }
    else if(i<=0||i>Length())   //�ж�i�Ƿ��������ȷ�Χ��
    {
        cout<<"���������ȷ�Χ�ڣ�"<<endl;
        return 0;
    }
    else
    {
        LinkNode<T> *current=head;
        for(int j=1;j<=i;j++)    //ѭ���ҵ���i��Ԫ�صĽ��
        {
            current=current->link;
        }
        return  current;
    }
}

template<class T>
bool List<T>::getData(int i,T &x)const   //��ȡ��i��Ԫ�ص�ֵ��ͨ��x����
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
       return false;
    }
    else if(i<=0||i>Length())   //�ж�i�Ƿ��������ȷ�Χ��
    {
        cout<<"���������ȷ�Χ�ڣ�"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        for(int j=1;j<=i;j++)    //ѭ���ҵ���i��Ԫ�صĽ��
        {
            current=current->link;
        }
        x=current->data;
        return true;
    }
}
template  <class T>
void List<T>::UpData(int i,T &x)   //�޸ĵ�i��Ԫ�ص�ֵ
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
        return;
    }
    else if(i<=0||i>Length())   //�ж�i�Ƿ��������ȷ�Χ��
    {
        cout<<"���������ȷ�Χ�ڣ�"<<endl;
        return;
    }
    else
    {
        LinkNode<T> *current=head;
        for(int j=1;j<=i;j++)    //ѭ���ҵ���i��Ԫ�صĽ��
        {
            current=current->link;
        }
        current->data=x;
    }
}
template <class T>
void List<T>::Push_back(T &x)     //��xѹ��β��
{
    LinkNode<T> *current=getLast();  //��currentָ��ָ�����һ�����
    LinkNode<T> *value=new LinkNode<T>(x);
    current->link=value;
}
template <class T>
void List<T>::input()  //����
{
    int i=0;
    T x;
    cout<<"������Ҫ��ӵĽ�������";
    cin>>i;
    LinkNode<T> *current=getLast();  //currentָ��ָ���������һ�����
    LinkNode<T> *value;
    for(int j=1;j<=i;j++)
    {
        cout<<"�����"<<j<<"���������ݣ�"<<endl;
        cin>>x;
        value=new LinkNode<T>(x);
        current->link=value;
        current=current->link;
    }
}
template <class T>
void List<T>::output() //���
{
    LinkNode<T> *current=head;
    current=current->link;
    if(IsEmpty())
    {
        cout<<"����Ϊ�գ�"<<endl;
        return;
    }
    else
    {
        int i=1;
        while(current->link!=nullptr)
        {
            cout<<"��"<<i<<"����������Ϊ��"<<endl<<current->data<<endl;
            i++;
            current=current->link;
        }
        cout<<"��"<<i<<"����������Ϊ��"<<endl<<current->data<<endl;
    }
}
template <class T>
bool List<T>::Insert(int i,T &x) //���뵽��i�����λ����
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
        return false;
    }
    else if(i<=0||i>Length())   //�ж�i�Ƿ��������ȷ�Χ��
    {
        cout<<"���������ȷ�Χ�ڣ�"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        LinkNode<T> *p;
        for(int j=1;j<i;j++)   //ѭ���ҵ���i��Ԫ�ؽ���ǰһ�����
              current=current->link;
        LinkNode<T> *value=new LinkNode<T>(x);
        p=current->link;   //pָ���i�����
        current->link=value;
        current=current->link;
        current->link=p;
        return true;
    }
}
template <class T>
bool List<T>::Insertfront(int i,T &x)//���뵽��i�����ǰһ��λ����
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
        return false;
    }
    else if(i<=0||i>Length())   //�ж�i�Ƿ��������ȷ�Χ��
    {
        cout<<"���������ȷ�Χ�ڣ�"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        LinkNode<T> *p;
        for(int j=1;j<i;j++)   //ѭ���ҵ���i��Ԫ�ؽ���ǰһ�����
              current=current->link;
        LinkNode<T> *value=new LinkNode<T>(x);
        p=current->link;   //pָ���i�����
        current->link=value;
        current=current->link;
        current->link=p;
        return true;
    }
}
template <class T>
bool List<T>::Insertback(int i,T &x)//���뵽��i������һ��λ����
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
        return false;
    }
    else if(i<=0||i>Length())   //�ж�i�Ƿ��������ȷ�Χ��
    {
        cout<<"���������ȷ�Χ�ڣ�"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        LinkNode<T> *p;
        for(int j=1;j<i+1;j++)   //ѭ���ҵ���i��Ԫ�ؽ��
              current=current->link;
        LinkNode<T> *value=new LinkNode<T>(x);
        p=current->link;   //pָ���i�����
        current->link=value;
        current=current->link;
        current->link=p;
        return true;
    }
}
template <class T>
bool List<T>::Remove(int i,T &x) //�Ƴ���i����㣬ͨ��x���ظý��Ԫ�ص�ֵ
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
        return false;
    }
    else if(i<=0||i>Length())   //�ж�i�Ƿ��������ȷ�Χ��
    {
        cout<<"���������ȷ�Χ�ڣ�"<<endl;
        return false;
    }
    else
    {
        LinkNode<T> *current=head;
        LinkNode<T> *p;
        for(int j=1;j<i;j++)   //ѭ���ҵ���i��Ԫ�ؽ���ǰһ�����
              current=current->link;
        p=current->link;   //pָ���i�����
        x=p->data;      //ͨ��x���ص�i������Ԫ�ص�ֵ
        current->link=p->link;
        p->link=nullptr;
        delete p;
        return true;
    }
}
template <class T>
void List<T>::Sort() //ð������,��С����
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
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
List<T> &List<T>::operator=(List<T> &L)  //����=�����
{
    T value;
    LinkNode<T> *p=L.getHead();
    LinkNode<T> *current=head=new LinkNode<T>;
    LinkNode<T> *x;
    while(p->link!=nullptr)  //�������
    {
        value=p->link->data;
        p=p->link;          //�����Ʊ�ָ����һ������
        x=new LinkNode<T>(value);
        current->link=x;
        current=current->link;
    }
}
template <class T>
bool List<T>::SavetoFile(const char filename[])   //���ݱ��溯��
{
    ofstream out;
    out.open(filename);
    if(out.fail())
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        return false;
    }
    else
    {
        int i=Length();
        out<<i<<endl;    //�������ȴ����ļ�
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
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        return false;
    }
    else
    {
        int i;
        in>>i;   //��ȡ�ļ��д�ȡ��������
        T x;
        LinkNode<T> *current=getLast();  //currentָ��ָ������β��
        LinkNode<T> *value;
        for(int j=1;j<=i;j++)    //ѭ������i�����
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
//���Ϻ����Ѳ���
template <class T>
void List<T>::SortFrombigtosmall() //ð������,��С����
{
    if(IsEmpty())    //�жϸñ��Ƿ�Ϊ�ձ�
    {
        cout<<"������Ϊ��Ϊ����"<<endl;
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
