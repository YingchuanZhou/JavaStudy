#include "minheap.h"
#include <iostream>
#include <cstdlib>
#define DefaultSize 100
using namespace std;
template <typename T>
void MinHeap<T>::ShiftDown(int start,int end)
{
    int i=start,j=2*i+1;
    T temp = heap[i];
    while(j<=end)
    {
        if(j<end-1&&heap[j]>heap[j+1])
            j++;//ʹ��jʼ��ָ��i�������ӽ�����С
        if(temp>heap[j])
        {
            heap[i]=heap[j];
            i=j;
            j=2*i+1;
        }
        else
            break;
    }
    heap[i]=temp;
}
template <typename T>
void MinHeap<T>::ShiftUp(int postion)
{
    int j=postion,i=(j-1)/2;
    T temp = heap[j];
    while(j>0)
    {
        if(temp<heap[i])
        {
            heap[j]=heap[i];
            j=i;
            i=(j-1)/2;
        }
        else
            break;
    }
    heap[j]=temp;
}
template <typename T>
MinHeap<T>::MinHeap(int size)
{
    maxSize=(size>DefaultSize) ? size : DefaultSize;
    heap = new T[maxSize];
    if(heap == nullptr)
        cerr<<"���䴢��ʧ�ܣ�����"<<endl;
    currentSize = 0;
}
template <typename T>
MinHeap<T>::MinHeap(T arr[],int n)
{
    maxSize=(DefaultSize>n) ? DefaultSize:n;
    heap = new T[maxSize];
    if(heap==nullptr)
        cerr<<"�����ڴ�ʧ�ܣ�����"<<endl;
    for(int i=0;i<n;i++)
        heap[i]=arr[i];
    currentSize=n;
    int now=(currentSize-2)/2;
    while (now>=0) {
        ShiftDown(now,currentSize-1);
        now--;
    }
}
template <typename T>
MinHeap<T>:: ~MinHeap()
{
    delete []heap;
}
template <typename T>
bool MinHeap<T>::IsEmpty()
{
    if(currentSize==0)
        return true;
    return false;
}
template <typename T>
bool MinHeap<T>::IsFull()
{
    if(currentSize==maxSize)
        return true;
    return false;
}
template <typename T>
bool MinHeap<T>::Insert(T &x)
{
    if(IsFull())
    {
        cerr<<"��С�ֶ�����������"<<endl;
        return false;
    }
    heap[currentSize]=x;
    ShiftUp(currentSize);
    currentSize++;
    return true;
}
template <typename T>
bool MinHeap<T>::RemoveMin(T &x)
{
    if(IsEmpty())
    {
        cerr<<"��С��Ϊ��"<<endl;
        return false;
    }
    x=heap[0];
    heap[0]=heap[currentSize-1];
    currentSize--;
    ShiftDown(0,currentSize-1);
    return true;
}
template <typename T>
void MinHeap<T>::print()
{
    for(int i=0;i<currentSize;i++)
    {
        cout<<heap[i]<<"  ";
    }
    cout<<endl;
}
