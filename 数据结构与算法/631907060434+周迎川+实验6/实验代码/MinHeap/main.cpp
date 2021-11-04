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
    cout<<"方案三：直接构建最小堆"<<endl;
    mh1.RemoveMin(x);
    end=clock();
    cout<<"优先级最高为："<<x<<"，运行时间为："<<((double)(end-start)/CLOCKS_PER_SEC)<<"s"<<endl;
    cout<<endl;
    cout<<"方案三：构建最小堆，一个元素一个元素插入"<<endl;
    start=clock();
    MinHeap<int> mh(100);
    for(int i=0;i<100;i++)
    mh.Insert(a[i]);
    mh.RemoveMin(x);
    end=clock();
     cout<<"优先级最高为："<<x<<"，运行时间为："<<((double)(end-start)/CLOCKS_PER_SEC)<<"s"<<endl;
    //mh1.print();
    //mh.print();
    cout<<endl;
    cout<<"方案一：依次查找最小元素"<<endl;
    start=clock();
    Function1(a,100,x);
    end=clock();
     cout<<"优先级最高为："<<x<<"，运行时间为："<<((double)(end-start)/CLOCKS_PER_SEC)<<"s"<<endl;
    cout<<endl;
    cout<<"方案二：选择排序后查找"<<endl;
    start=clock();
    Function2(a,100,x);
    end=clock();
     cout<<"优先级最高为："<<x<<"，运行时间为："<<((double)(end-start)/CLOCKS_PER_SEC)<<"s"<<endl;
    return 0;
}
