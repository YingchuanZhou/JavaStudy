#include <iostream>
#include "binsearchtree.h"
#include "binsearchtree.cpp"
#include "seqlist.h"
#include "seqlist.cpp"
#include <time.h>
using namespace std;

int main()
{
    //���Զ���������
    int stop =-1;
    int y;
    BinSearchTree<int, char> BST1(stop);
    BST1.PrintTree();
    cout<<"\n����Ҫɾ����Ԫ�أ�"<<endl;
    cin>>y;
    BST1.Remove(y);
    BST1.PrintTree();
    cout<<"\n����Ҫ������Ԫ�أ�"<<endl;
    cin>>y;
    if(BST1.Search(y))
        cout<<"��������"<<endl;
    else
        cout<<"û�и�Ԫ��"<<endl;
    BinSearchTree<int,char> BST;
    SeqList<int> SL;
    cout<<"�������"<<endl;
    int x;
    time_t start,end;
        start=clock();
    BST.CreateNum();
    srand((unsigned)time(nullptr));
    for(int i=0;i<1000;i++)
    {
        x=rand()%2000;
        //cout<<x<<" ";
        SL.Insert(i,x);
    }
    cout<<"���ݲ���ɹ�"<<endl;
    //BST.PrintTree();
    //SL.Display(0,999);
    start=clock();
    if(BST.Search(x))
        cout<<"�ҵ���"<<endl;
    else
        cout<<"û�и�Ԫ��"<<endl;
    end=clock();
    cout<<"ʱ��"<<double(end-start)/CLOCKS_PER_SEC<<endl;
    SL.Sort();
    //SL.Display(0,999);
    start=clock();
    if(SL.BinSearch(x))
        cout<<"�ҵ���"<<endl;
    else
        cout<<"û�и�Ԫ��"<<endl;
    end=clock();
    cout<<"ʱ�䣺"<<double(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
