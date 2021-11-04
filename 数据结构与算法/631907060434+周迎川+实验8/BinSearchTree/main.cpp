#include <iostream>
#include "binsearchtree.h"
#include "binsearchtree.cpp"
#include "seqlist.h"
#include "seqlist.cpp"
#include <time.h>
using namespace std;

int main()
{
    //测试二叉搜索树
    int stop =-1;
    int y;
    BinSearchTree<int, char> BST1(stop);
    BST1.PrintTree();
    cout<<"\n输入要删除的元素："<<endl;
    cin>>y;
    BST1.Remove(y);
    BST1.PrintTree();
    cout<<"\n输入要搜索的元素："<<endl;
    cin>>y;
    if(BST1.Search(y))
        cout<<"搜索到了"<<endl;
    else
        cout<<"没有该元素"<<endl;
    BinSearchTree<int,char> BST;
    SeqList<int> SL;
    cout<<"构建完成"<<endl;
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
    cout<<"数据插入成功"<<endl;
    //BST.PrintTree();
    //SL.Display(0,999);
    start=clock();
    if(BST.Search(x))
        cout<<"找到了"<<endl;
    else
        cout<<"没有该元素"<<endl;
    end=clock();
    cout<<"时间"<<double(end-start)/CLOCKS_PER_SEC<<endl;
    SL.Sort();
    //SL.Display(0,999);
    start=clock();
    if(SL.BinSearch(x))
        cout<<"找到了"<<endl;
    else
        cout<<"没有该元素"<<endl;
    end=clock();
    cout<<"时间："<<double(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
