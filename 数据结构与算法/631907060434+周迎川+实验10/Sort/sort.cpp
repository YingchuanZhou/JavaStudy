#include<iostream>
#include<cstdlib>
#include "sort.h"
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
bool SeqList<T>::Push_back(const T x)
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
void SeqList<T>::Display()
{
    for(int i=0;i<num;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
template <typename T>
void InserSort(SeqList<T> &SL,int left,int right)
{
    //后一个元素与前面的比较，如果这个元素比前面的小，则将原来的元素后移，找到这个元素一个插入的位置，
    int j;T temp;int account=0;
    for(int i=left+1;i<=right;i++)
    {
        if(SL[i]<SL[i-1])//注意这个if的括号，之前都错了
        {
            temp=SL[i];j=i-1;
        do
        {
            SL[j+1]=SL[j];j--;
            account++;
        }while(j>=left && SL[j]>temp);
        SL[j+1]=temp;
        }
    }
    cout<<"交换次数："<<account<<endl;
}
template <typename  T>
void ChangeSort(SeqList<T> &SL,int left,int right)
{
    //选择排序，相比较，如果后面的比前面小，交换
    T temp;int count=0;
    for(int i=left;i<right;i++)
        for(int j=i+1;j<=right;j++)
        {
            if(SL[i]>SL[j])
            {
                temp=SL[i];
                SL[i]=SL[j];
                SL[j]=temp;
                count++;
            }
        }
    cout<<"交换次数："<<count<<endl;
}
template <typename T>
void SelectSort(SeqList<T> &SL,int left,int right)
{
    //选择排序，从当前元素像后面找，找出后面最大的元素，然后交换
    T temp;int account=0;
    for(int i=left;i<right;i++)
    {
        int m=i;
        for(int j=i+1;j<=right;j++)
        {
            if(SL[m]>SL[j])
                m=j;
        }
        if(m!=i)
        {
            temp=SL[i];
            SL[i]=SL[m];
            SL[m]=temp;
            account++;
        }
    }
    cout<<"交换次数："<<account<<endl;
}
template <typename T>
void merge(SeqList<T> &SL,SeqList<T> &SL2,int left,int mid,int right)
{
    //先将SL复制给SL2
    for(int i=left;i<=right;i++)
        SL2[i]=SL[i];
    int s1=left,s2=mid+1,t=left;//s1和s2是位置信息，没有比较完继续比较
    while(s1<=mid && s2<=right)
        if(SL2[s1]<=SL2[s2])
            SL[t++]=SL2[s1++];
    else
            SL[t++]=SL2[s2++];
        while(s1<=mid)//第一个没有比较完，复制
            SL[t++]=SL2[s1++];
        while(s2<=right)//第二个没有比较完，复制
            SL[t++]=SL2[s2++];
}
template <typename T>
void MergeSort(SeqList<T> &SL,SeqList<T> &SL2,int left,int right,int &account)
{
    if(left>=right)
        return ;
    account++;
    //将顺序表从中间分开，分成两个子序列
    int mid=(left+right)/2;
    MergeSort(SL,SL2,left,mid,account);
    MergeSort(SL,SL2,mid+1,right,account);
    merge(SL,SL2,left,mid,right);
}
