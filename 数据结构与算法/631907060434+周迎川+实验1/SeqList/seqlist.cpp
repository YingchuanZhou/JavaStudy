#include<iostream>
#include<cstdlib>
#include<fstream>
#include "seqlist.h"
using namespace std;
template <typename T>
void SeqList<T> ::resetsize(int newsize)//扩展数据元素的长度
{
    /*首先判断传入的newsize是否合法
     * 如果说newsize大于原来的maxsize，则重新分配储存空间
     * 如果重新分配的空间等于NULL说明分配空间失败
     * 然后再将原来的数据元素赋值给新的顺序表
     * 最后还要改变maxsize的值
    */
    if(newsize <=0)
    {
        cerr<<"数组大小无效！！！"<<endl;
        return;
    }
    if(newsize > maxsize)
    {
        T* newarray = new T[newsize];
        if(newarray==NULL)
        {
            cerr<<"内存分配失败！！！"<<endl;
            exit(1);
        }
        int n=num;
        T* str1=data;
        T* str2=newarray;
        while(n--)
            *str2++=*str1++;
        delete [] data;
        data=newarray;
        maxsize=newsize;
    }
}
template <typename T>
SeqList <T> ::SeqList(int sz)
{
    if(sz>0)
    {
        maxsize = sz;num=0;
        data = new T[maxsize];
        if(data==NULL)
        {
            cerr<<"内存分配失败！！！"<<endl;
            exit(1);
        }
    }
}
template <typename T>
SeqList <T> ::~SeqList()
{
    delete []data;
}
template <typename T>
int SeqList <T> ::Length()const
{
    //直接返回现在顺序表中的元素个数久是表的长度
    return num;
}
template <typename T>
bool SeqList <T> ::IsFull() const
{
    //如果现在顺序表中的元素个数和最大储存元素个数相同表明表已经满了
    return (num==maxsize)?true:false;
}
template <typename T>
bool SeqList <T> ::IsEmpty() const
{
    //如果顺序表的元素个数为0，表明表为空
    return (num==0)?true:false;
}
template <typename T>
int SeqList<T> ::Search(T& x) const
{
    /*如果data数组里面有与x相同的对象则flag=1并且返回是第几个元素
     * 如果没有返回-1
     */
    int flag=0;
    for(int i = 0;i < num;i++)
    {
        if(data[i]==x)
        {
            flag=1;
            return i+1;
        }
    }
      if(!flag){
            cerr<<"没有该元素"<<endl;
            return -1;
        }
}
template <typename T>
T& SeqList <T>::Get(int i)
{
    //判断一个输入的位置是否合法，合法则返回该位置的对象
    if(i<num && i>0)
        return data[i-1];
    else
    {
        cerr<<"该位置没有元素！！！"<<endl;
    }
}
template <typename T>
bool SeqList<T>::Push_back(const T &x)
{
    //在尾部插入对象，首先判断顺序表是否已经满了，如果已经满了，先对顺序表进行扩展，然后再插入对象，数量num值增加1；
    //如果没有满，直接插入末尾，num值增加1
    if(IsFull())
    {
        resetsize(2*maxsize);
        data[num]=x;
        num++;
        return true;
    }
    else
    {
        data[num]=x;
        num++;
        return true;
    }

}
template <typename T>
bool SeqList<T> ::Insert(int i,const T& x)
{
    //首先判断传入的i是否合法
    //再判断顺序表是否已经满了
    //如果满了扩展顺序表，然后将第i个位子以后的元素一次向后移动一个位置，然后将x插入，num值增加1
    //如果没有满，直接将第i个位子以后的元素一次向后移动一个位置，然后将x插入，num值增加1
    if(i<0||i>num)
    {
        cerr<<"输入位置错误！！！"<<endl;
        return false;
    }
    if(IsFull())
    {
        resetsize(2*maxsize);
        for(int j=num-1;j>=i-1;j--)
            data[j+1]=data[j];
        data[i-1]=x;
        num++;
        return true;
    }
    else
    {
        for(int j=num-1;j>=i-1;j--)
            data[j+1]=data[j];
        data[i-1]=x;
        num++;
        return true;
    }
}
template <typename T>
bool SeqList<T>::Remove(T& x)
{
    //首先判断顺序表是否为空，空表不能删除
    //如果部位空，只需要找到改元素的位置，并且将改元素后面的元素向前移动一个位置，num值减1
    if(IsEmpty())
    {
        cerr<<"顺序表为空，不能进行删除！！！"<<endl;
        return false;
    }
    int i=Search(x);
    if(i==-1)
        return false;
    for(int j=i-1;j<num;j++)
    {
        data[j]=data[j+1];
    }
    num--;
    return true;
}
template <typename T>
bool SeqList<T>::RemovePos(int pos)
{
    //首先判断传入的位置信息是否合法
    //如果合法，检验表是否为空
    //如果为空不能进行删除操作
    //如果不为空将该位置后面的元素向前移动一个位置，num值减1
    if(pos<1||pos>num)
    {
        cerr<<"输入位置错误！！！"<<endl;
        return false;
    }
    if(IsEmpty())
    {
        cerr<<"顺序表为空，不能进行删除！！！"<<endl;
        return false;
    }
    for(int j=pos;j<num;j++)
    {
        data[j-1]=data[j];
    }
    num--;
    return true;
}
template <typename T>
void SeqList<T>::Display(int start,int end)
{
    //遍历顺序表
    cout<<endl;
    for(int i=start;i<=end;i++)
    {
        cout<<data[i]<<endl;
    }
    cout<<"dispaly over"<<endl;
    return;
}
template <typename T>
bool SeqList<T>::ReadFile(const char FileName[])
{
    //首先定义读文件的对象
    //打开文件，如果打开文件失败，提示打开失败
    ifstream fin;
    fin.open(FileName);
    if(fin.fail())
    {
        cerr<<"文件打开失败！！！"<<endl;
        return false;
    }
    fin>>num;
    for(int i=0;i<num;i++)
        fin>>data[i];
    fin.close();
    cout<<"readover"<<endl;
    return true;
}
template <typename T>
bool SeqList<T>::SaveFile(const char FileName[])
{
    //首先定义存文件的对象
     //打开文件，如果打开文件失败，提示打开失败
    ofstream fout;
    fout.open(FileName);
    if(fout.fail())
    {
        cerr<<"文件打开失败！！！"<<endl;
        return false;
    }
    fout<<num<<endl;
    for(int i=0;i<num;i++)
        fout<<data[i]<<endl;
    fout.close();
    cout<<"保存成功"<<endl;
    return true;
}
template <typename T>
int SeqList<T>::Getnum()
{
    return num;
}
