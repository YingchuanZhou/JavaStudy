#include <iostream>
#include "minheap.h"
#include "minheap.cpp"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int a[100];int x;
    clock_t start,end;
    srand((unsigned)time(nullptr));
    for(int i=0;i<100;i++)
        a[i]=rand()%1000;
    MinHeap<int> mh1(a,100);
    mh1.print();
    start=clock();
    cout<<"��������ֱ�ӹ�����С��"<<endl;
    mh1.RemoveMin(x);
    end=clock();
    cout<<"���ȼ����Ϊ��"<<x<<"������ʱ��Ϊ��"<<((double)(end-start)/CLOCKS_PER_SEC)<<"s"<<endl;
    cout<<endl;
    cout<<"��������������С�ѣ�һ��Ԫ��һ��Ԫ�ز���"<<endl;
    start=clock();
    MinHeap<int> mh(100);
    for(int i=0;i<100;i++)
    mh.Insert(a[i]);
    mh.RemoveMin(x);
    end=clock();
     cout<<"���ȼ����Ϊ��"<<x<<"������ʱ��Ϊ��"<<((double)(end-start)/CLOCKS_PER_SEC)<<"s"<<endl;
    //mh1.print();
    //mh.print();
    cout<<endl;
    cout<<"����һ�����β�����СԪ��"<<endl;
    start=clock();
    Function1(a,100,x);
    end=clock();
     cout<<"���ȼ����Ϊ��"<<x<<"������ʱ��Ϊ��"<<((double)(end-start)/CLOCKS_PER_SEC)<<"s"<<endl;
    cout<<endl;
    cout<<"��������ѡ����������"<<endl;
    start=clock();
    Function2(a,100,x);
    end=clock();
     cout<<"���ȼ����Ϊ��"<<x<<"������ʱ��Ϊ��"<<((double)(end-start)/CLOCKS_PER_SEC)<<"s"<<endl;
    return 0;
}
