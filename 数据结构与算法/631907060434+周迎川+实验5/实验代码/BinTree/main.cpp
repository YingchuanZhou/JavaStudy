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
//        cerr<<"打开文件失败！！"<<endl;
    tree.CreateBinTree();
    int a=5;
    cout<<"5所在的层数:"<<endl;
    cout<<tree.NodeLevel(a)<<endl;
    cout<<"树的结点数为："<<endl;
    cout<<tree.Size()<<endl;
    cout<<"树的叶节点数为："<<endl;
    cout<<tree.LeavesCount()<<endl;
    cout<<"二叉树的高度："<<endl;
    cout<<tree.Height()<<endl;
    cout<<"结点的度数:"<<endl;
    int b=1;
    cout<<"5结点的度数:"<<tree.NodeDeg(tree.Find(a))<<endl;
    cout<<"1结点的度数:"<<tree.NodeDeg(tree.Find(b))<<endl;
    cout<<"结点5的双亲："<<endl;
    now=tree.Parent(tree.Find(a));
    if(now!=nullptr)
        cout<<now->date<<endl;
    else
        cout<<"该结点为根结点"<<endl;
    cout<<"结点1的左子女："<<endl;
    now=tree.LeftChild(tree.Find(b));
    if(now!=nullptr)
        cout<<now->date<<endl;
    else
        cout<<"不存在左子女"<<endl;
    cout<<"结点1的右子女："<<endl;
    now=tree.RightChild(tree.Find(b));
    if(now!=nullptr)
        cout<<now->date<<endl;
    else
        cout<<"不存在右子女"<<endl;
    cout<<"递归实现："<<endl;
    cout<<"前序遍历："<<endl;
    tree.preOrder();
    cout<<endl;
    cout<<"中序遍历："<<endl;
    tree.inOrder();
    cout<<endl;
    cout<<"后序遍历："<<endl;
    tree.postOrder();
    cout<<endl;
    cout<<"非递归实现："<<endl;
    cout<<"前序遍历："<<endl;
    tree.PreOrder();
    cout<<endl;
    cout<<"中序遍历："<<endl;
    tree.InOrder();
    cout<<endl;
    cout<<"后序遍历："<<endl;
    tree.PostOrder();
    cout<<endl;
    cout<<"二叉树的复制"<<endl;
    tree2.setRoot(tree2.Copy(tree.getRoot()));
    cout<<"复制的树的值"<<endl;
    tree2.Traverse(tree2.getRoot());
    cout<<endl;
    return 0;
}
