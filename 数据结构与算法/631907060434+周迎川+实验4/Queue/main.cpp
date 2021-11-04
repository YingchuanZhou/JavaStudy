#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include <iomanip>
using namespace std;
int main()
{
//    int x=1,b;
//    ListQueue<int> Lq;
//    Lq.EnQueue(x);
//    b=2;
//    Lq.EnQueue(b);
//    Lq.DeQueue(x);
//    cout<<x<<endl;
//    Lq.DeQueue(x);
//    cout<<x<<endl;---ok
    int x=1,y=0;
    ListQueue<int> LQ;
    int n;
    cout<<"输入行数："<<endl;
    cin>>n;
    LQ.EnQueue(y);//入队0
    LQ.EnQueue(x);LQ.EnQueue(x);
    LQ.EnQueue(y);//入队0   构成0 1 1 0
    ListNode<int> *p,*q;
    p=LQ.returnFront();q=p->next;
    for(int i=2;i<=n;i++)
    {
        LQ.EnQueue(y);
        for(int j=1;j<=i+2;j++)
        {
            int w=p->data+q->data;
            LQ.EnQueue(w);
            p=q;q=q->next;
        }
//        LQ.EnQueue(y);
    }
    int k=4,b=n-1/*,len=LQ.getSize()*/;
    for(int i=1;i<=n;i++)
    {
        for(int m=b;m>0;m--)
        {
            cout<<setw(3)<<"";
        }
        for(int j=1;j<=k&&j<i+4;j++ )
        {
            int data;
            LQ.DeQueue(data);
            if(data!=0)
                cout<<setw(6)<<data;
        }
        cout<<endl;
        k++;b--;
    }
    return 0;
}
