#include<iostream>
#include<cstdlib>
#include "sort.h"
using namespace std;
template <typename T>
void SeqList<T> ::resetsize(int newsize)//��չ����Ԫ�صĳ���
{
    /*�����жϴ����newsize�Ƿ�Ϸ�
     * ���˵newsize����ԭ����maxsize�������·��䴢��ռ�
     * ������·���Ŀռ����NULL˵������ռ�ʧ��
     * Ȼ���ٽ�ԭ��������Ԫ�ظ�ֵ���µ�˳���
     * ���Ҫ�ı�maxsize��ֵ
    */
    if(newsize <=0)
    {
        cerr<<"�����С��Ч������"<<endl;
        return;
    }
    if(newsize > maxsize)
    {
        T* newarray = new T[newsize];
        if(newarray==NULL)
        {
            cerr<<"�ڴ����ʧ�ܣ�����"<<endl;
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
            cerr<<"�ڴ����ʧ�ܣ�����"<<endl;
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
    //ֱ�ӷ�������˳����е�Ԫ�ظ������Ǳ�ĳ���
    return num;
}
template <typename T>
bool SeqList <T> ::IsFull() const
{
    //�������˳����е�Ԫ�ظ�������󴢴�Ԫ�ظ�����ͬ�������Ѿ�����
    return (num==maxsize)?true:false;
}
template <typename T>
bool SeqList <T> ::IsEmpty() const
{
    //���˳����Ԫ�ظ���Ϊ0��������Ϊ��
    return (num==0)?true:false;
}
template <typename T>
bool SeqList<T>::Push_back(const T x)
{
    //��β��������������ж�˳����Ƿ��Ѿ����ˣ�����Ѿ����ˣ��ȶ�˳��������չ��Ȼ���ٲ����������numֵ����1��
    //���û������ֱ�Ӳ���ĩβ��numֵ����1
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
    //��һ��Ԫ����ǰ��ıȽϣ�������Ԫ�ر�ǰ���С����ԭ����Ԫ�غ��ƣ��ҵ����Ԫ��һ�������λ�ã�
    int j;T temp;int account=0;
    for(int i=left+1;i<=right;i++)
    {
        if(SL[i]<SL[i-1])//ע�����if�����ţ�֮ǰ������
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
    cout<<"����������"<<account<<endl;
}
template <typename  T>
void ChangeSort(SeqList<T> &SL,int left,int right)
{
    //ѡ��������Ƚϣ��������ı�ǰ��С������
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
    cout<<"����������"<<count<<endl;
}
template <typename T>
void SelectSort(SeqList<T> &SL,int left,int right)
{
    //ѡ�����򣬴ӵ�ǰԪ��������ң��ҳ���������Ԫ�أ�Ȼ�󽻻�
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
    cout<<"����������"<<account<<endl;
}
template <typename T>
void merge(SeqList<T> &SL,SeqList<T> &SL2,int left,int mid,int right)
{
    //�Ƚ�SL���Ƹ�SL2
    for(int i=left;i<=right;i++)
        SL2[i]=SL[i];
    int s1=left,s2=mid+1,t=left;//s1��s2��λ����Ϣ��û�бȽ�������Ƚ�
    while(s1<=mid && s2<=right)
        if(SL2[s1]<=SL2[s2])
            SL[t++]=SL2[s1++];
    else
            SL[t++]=SL2[s2++];
        while(s1<=mid)//��һ��û�бȽ��꣬����
            SL[t++]=SL2[s1++];
        while(s2<=right)//�ڶ���û�бȽ��꣬����
            SL[t++]=SL2[s2++];
}
template <typename T>
void MergeSort(SeqList<T> &SL,SeqList<T> &SL2,int left,int right,int &account)
{
    if(left>=right)
        return ;
    account++;
    //��˳�����м�ֿ����ֳ�����������
    int mid=(left+right)/2;
    MergeSort(SL,SL2,left,mid,account);
    MergeSort(SL,SL2,mid+1,right,account);
    merge(SL,SL2,left,mid,right);
}
