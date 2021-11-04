#include<iostream>
#include<cstdlib>
#include<fstream>
#include "seqlist.h"
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
int SeqList<T> ::Search(T& x) const
{
    /*���data������������x��ͬ�Ķ�����flag=1���ҷ����ǵڼ���Ԫ��
     * ���û�з���-1
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
            cerr<<"û�и�Ԫ��"<<endl;
            return -1;
        }
}
template <typename T>
T& SeqList <T>::Get(int i)
{
    //�ж�һ�������λ���Ƿ�Ϸ����Ϸ��򷵻ظ�λ�õĶ���
    if(i<num && i>0)
        return data[i-1];
    else
    {
        cerr<<"��λ��û��Ԫ�أ�����"<<endl;
    }
}
template <typename T>
bool SeqList<T>::Push_back(const T &x)
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
bool SeqList<T> ::Insert(int i,const T& x)
{
    //�����жϴ����i�Ƿ�Ϸ�
    //���ж�˳����Ƿ��Ѿ�����
    //���������չ˳���Ȼ�󽫵�i��λ���Ժ��Ԫ��һ������ƶ�һ��λ�ã�Ȼ��x���룬numֵ����1
    //���û������ֱ�ӽ���i��λ���Ժ��Ԫ��һ������ƶ�һ��λ�ã�Ȼ��x���룬numֵ����1
    if(i<0||i>num)
    {
        cerr<<"����λ�ô��󣡣���"<<endl;
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
    //�����ж�˳����Ƿ�Ϊ�գ��ձ���ɾ��
    //�����λ�գ�ֻ��Ҫ�ҵ���Ԫ�ص�λ�ã����ҽ���Ԫ�غ����Ԫ����ǰ�ƶ�һ��λ�ã�numֵ��1
    if(IsEmpty())
    {
        cerr<<"˳���Ϊ�գ����ܽ���ɾ��������"<<endl;
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
    //�����жϴ����λ����Ϣ�Ƿ�Ϸ�
    //����Ϸ���������Ƿ�Ϊ��
    //���Ϊ�ղ��ܽ���ɾ������
    //�����Ϊ�ս���λ�ú����Ԫ����ǰ�ƶ�һ��λ�ã�numֵ��1
    if(pos<1||pos>num)
    {
        cerr<<"����λ�ô��󣡣���"<<endl;
        return false;
    }
    if(IsEmpty())
    {
        cerr<<"˳���Ϊ�գ����ܽ���ɾ��������"<<endl;
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
    //����˳���
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
    //���ȶ�����ļ��Ķ���
    //���ļ���������ļ�ʧ�ܣ���ʾ��ʧ��
    ifstream fin;
    fin.open(FileName);
    if(fin.fail())
    {
        cerr<<"�ļ���ʧ�ܣ�����"<<endl;
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
    //���ȶ�����ļ��Ķ���
     //���ļ���������ļ�ʧ�ܣ���ʾ��ʧ��
    ofstream fout;
    fout.open(FileName);
    if(fout.fail())
    {
        cerr<<"�ļ���ʧ�ܣ�����"<<endl;
        return false;
    }
    fout<<num<<endl;
    for(int i=0;i<num;i++)
        fout<<data[i]<<endl;
    fout.close();
    cout<<"����ɹ�"<<endl;
    return true;
}
template <typename T>
int SeqList<T>::Getnum()
{
    return num;
}
