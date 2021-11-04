#include <iostream>
#include "bintree.h"
#include "bintree.cpp"
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    BinTree<int> tree;
    BinTree<int> tree2;
    BinTreeNode<int> *now;
//    ifstream in("E:\\Qtprojects\\BinTree\\TreeData.txt");
//    if(in.fail())
//        cerr<<"���ļ�ʧ�ܣ���"<<endl;
    tree.CreateBinTree();
    int a=5;
    cout<<"5���ڵĲ���:"<<endl;
    cout<<tree.NodeLevel(a)<<endl;
    cout<<"���Ľ����Ϊ��"<<endl;
    cout<<tree.Size()<<endl;
    cout<<"����Ҷ�ڵ���Ϊ��"<<endl;
    cout<<tree.LeavesCount()<<endl;
    cout<<"�������ĸ߶ȣ�"<<endl;
    cout<<tree.Height()<<endl;
    cout<<"���Ķ���:"<<endl;
    int b=1;
    cout<<"5���Ķ���:"<<tree.NodeDeg(tree.Find(a))<<endl;
    cout<<"1���Ķ���:"<<tree.NodeDeg(tree.Find(b))<<endl;
    cout<<"���5��˫�ף�"<<endl;
    now=tree.Parent(tree.Find(a));
    if(now!=nullptr)
        cout<<now->date<<endl;
    else
        cout<<"�ý��Ϊ�����"<<endl;
    cout<<"���1������Ů��"<<endl;
    now=tree.LeftChild(tree.Find(b));
    if(now!=nullptr)
        cout<<now->date<<endl;
    else
        cout<<"����������Ů"<<endl;
    cout<<"���1������Ů��"<<endl;
    now=tree.RightChild(tree.Find(b));
    if(now!=nullptr)
        cout<<now->date<<endl;
    else
        cout<<"����������Ů"<<endl;
    cout<<"�ݹ�ʵ�֣�"<<endl;
    cout<<"ǰ�������"<<endl;
    tree.preOrder();
    cout<<endl;
    cout<<"���������"<<endl;
    tree.inOrder();
    cout<<endl;
    cout<<"���������"<<endl;
    tree.postOrder();
    cout<<endl;
    cout<<"�ǵݹ�ʵ�֣�"<<endl;
    cout<<"ǰ�������"<<endl;
    tree.PreOrder();
    cout<<endl;
    cout<<"���������"<<endl;
    tree.InOrder();
    cout<<endl;
    cout<<"���������"<<endl;
    tree.PostOrder();
    cout<<endl;
    cout<<"�������ĸ���"<<endl;
    tree2.setRoot(tree2.Copy(tree.getRoot()));
    cout<<"���Ƶ�����ֵ"<<endl;
    tree2.Traverse(tree2.getRoot());
    cout<<endl;
    return 0;
}
