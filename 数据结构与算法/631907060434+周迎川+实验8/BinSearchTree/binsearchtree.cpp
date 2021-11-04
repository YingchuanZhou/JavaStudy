#include "binsearchtree.h"
#include <iostream>
#include <time.h>
using namespace std;
template <typename T, typename E>
BinSearchTree<T, E>::BinSearchTree(T &st)
{
    //构建二叉搜索树，将根置为空
    //输入的值为stop时结束循环
    stop = st; root=nullptr;
    T x;
    cout<<"输入边界点的值，以-1结束："<<endl;
    cin>>x;
    while (x!=stop) {
        Insert(x,root);
        cin>>x;
    }
}
template <typename T, typename E>
BinSearchTreeNode<T, E>* BinSearchTree<T, E>::Search(T &x, BinSearchTreeNode<T, E>*root)
{
    //二叉搜索的子过程
    //如果说结点为空，返回空指针，递归出口之一
    //二叉搜索树的左子树小于右子树，如果比根节点的数值小，在左子树搜索，如果比根节点数值大，则在右子树中搜索
    //搜索到，返回节点指针
    if(root==nullptr)
        return nullptr;
    if(x<root->data)
        return Search(x, root->left);
    if(x>root->data)
        return Search(x, root->right);
    else
        return root;
}
template <typename T, typename E>
bool BinSearchTree<T, E>::Search(T &x)
{
    //如果搜索的指针不为空，搜索到了，否则返回false
    if(Search(x,root)!=nullptr)
        return true;
    return false;
}
template <typename T, typename E>
void BinSearchTree<T, E>::makeEmpty()
{
    //置空，将root置为空
    makeEmpty(root);
    root=nullptr;
}
template <typename T, typename E>
void BinSearchTree<T, E>::makeEmpty(BinSearchTreeNode<T, E> *&root)
{
    //置空的子过程，如果root不为空，则将左子树和右子树置为空，然后再删除根节点
    if(root!=nullptr)
    {
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
    }
}
template <typename T, typename E>
void BinSearchTree<T, E>::visit(BinSearchTreeNode<T, E> *root)
{
    //定义访问函数，输出指针所指的值
    cout<<root->data<<" ";
}
template <typename T, typename E>
void BinSearchTree<T, E>::PrintTree(BinSearchTreeNode<T, E>* root)
{
    //遍历二叉搜索树子过程，二叉搜索树中序遍历是一个递增序列
    if(root==nullptr)
        return;
    PrintTree(root->left);
    visit(root);
    PrintTree(root->right);
}
template <typename T, typename E>
void BinSearchTree<T, E>::PrintTree()
{
    //遍历二叉搜索树
    PrintTree(root);
}
template <typename T, typename E>
bool BinSearchTree<T, E>::Insert(T &x, BinSearchTreeNode<T, E>*&root)
{
    //插入x的子过程，如果说root为空，分配一个节点，初始化数据为x，返回true
    //如果说root不为空，x的值比root小就插入左子树，比root大就插入右子树
    if(root==nullptr)
    {
        root=new BinSearchTreeNode<T, E>(x);
        return true;
    }
    if(x<root->data)
        return Insert(x,root->left);
    else if(x>root->data)
        return Insert(x,root->right);
    else
        return false;
}
template <typename T, typename E>
bool BinSearchTree<T, E>::Insert(T &x)
{
    //插入的子过程，成功返回true，不成功返回false
    if(Insert(x,root))
        return true;
    return false;
}
template <typename T, typename E>
bool BinSearchTree<T, E>::Remove(T &x, BinSearchTreeNode<T, E>*&root)
{
    //删除x，如果根节点为空，直接返回false
    //如果x比data小，去左子树中删除，如果比data大去右子树删除
    //再如果data等于x，且root的左右子树都存在，去右子树中找到最小的数，那就是右子树的左子树
    //一直要到不存在左子树为止，然后将这个数赋值给根节点，然后删除改结点
    //如果说根节点的左右子树有一个为空，则直接将改结点删除，直接将指针修改为下一个节点
    BinSearchTreeNode<T, E> *temp;
    if(root==nullptr)
        return false;
    if(x<root->data)
        return Remove(x, root->left);
    if(x>root->data)
        return Remove(x, root->right);
    else if(root->left!=nullptr && root->right!=nullptr)
    {
        temp=root->right;//先指向结点右边或者左边
        while(temp->left!=nullptr)
            temp=temp->left;
        root->data=temp->data;
        return Remove(root->data,temp);//删除右子树中temp结点
    }
    else
    {
        temp=root;
        if(root->left!=nullptr)
            root=root->left;
        else
            root=root->right;
        delete temp;
        return true;
    }
}
template <typename T, typename E>
bool BinSearchTree<T, E>::Remove(T &x)
{
    //删除x，删除成功返回true，不成功返回false
    if(Remove(x, root))
        return true;
    return false;
}
template <typename T, typename E>
bool BinSearchTree<T, E>::CreateNum()
{
    int x;
    srand((unsigned)time(nullptr));
    for(int i=0;i<1000;i++)
    {
        x=rand()%2000;
       // cout<<x<<" ";
        Insert(x,root);
    }
    return true;
}
