#include "bintree.h"
#include "stack.h"
#include "stack.cpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
template <typename T>
void BinTree<T>::CreateBinTree(BinTreeNode<T> *&tree)
{
    T item;
    cin>>item;
    if(item!=stop)
    {
        tree= new BinTreeNode<T>(item);
        //tree->date=item;
        //cout<<tree->date<<endl;
        //cout<<"00000"<<endl;
        if(tree==nullptr)
        {
            cerr<<"·ÖÅäÄÚ´æ´íÎó£¡£¡£¡"<<endl;
            return;
        }
        CreateBinTree(tree->lchild);
       // cout<<"11111"<<endl;
        CreateBinTree(tree->rchild);
    }
    else
        tree=nullptr;
}
template <typename T>
void BinTree<T>::destroy(BinTreeNode<T> *&tree)
{
    if(tree!=nullptr)
    {
        destroy(tree->lchild);
        destroy(tree->rchild);
        delete tree;
    }
}
template <typename T>
BinTreeNode<T>* BinTree<T>::Find(BinTreeNode<T>* &tree,T& x)
{
    if(tree==nullptr)
        return nullptr;
    if(tree->date==x)
        return tree;
    BinTreeNode<T>* p;
    if((p=Find(tree->lchild,x))!=nullptr)
        return p;
    else
        return Find(tree->rchild,x);
}
template <typename T>
BinTreeNode<T>* BinTree<T>::Copy(BinTreeNode<T>*origin)
{
    if(origin==nullptr)
        return nullptr;
    BinTreeNode<T>* newtree=new BinTreeNode<T>;
    newtree->date=origin->date;
    newtree->lchild=Copy(origin->lchild);
    newtree->rchild=Copy(origin->rchild);
    return newtree;
}
template <typename T>
int BinTree<T>::Height(BinTreeNode<T>*tree)
{
    if(tree==nullptr)
        return 0;
    int i=Height(tree->lchild);
    int j=Height(tree->rchild);
    return (i>j) ? i+1:j+1;
}
template <typename T>
int BinTree<T>::Size(BinTreeNode<T>*tree)
{
    if(tree==nullptr)
        return 0;
    return 1+Size(tree->lchild)+Size(tree->rchild);
}
template <typename T>
int BinTree<T>::LeavesCount(BinTreeNode<T> *tree)
{
    if(tree==nullptr)
        return 0;
    else if(tree->lchild==nullptr&&tree->rchild==nullptr)
        return 1;
    else
    {
        return LeavesCount(tree->rchild)+LeavesCount(tree->lchild);
    }
}
template <typename T>
int BinTree<T>::NodeDeg(BinTreeNode<T>*now)
{
    if(now==nullptr)
        return 0;
    if(now->lchild!=nullptr&&now->rchild!=nullptr)
        return 2;
    if(now->lchild!=nullptr)
        return 1;
    if(now->rchild!=nullptr)
        return 1;
    else
        return 0;
}
template <typename T>
BinTreeNode<T>* BinTree<T>::Parent(BinTreeNode<T> *tree,BinTreeNode<T>* now)
{
    if(tree==nullptr||now==root)
        return nullptr;
    else if(tree->lchild==now||tree->rchild==now)
        return tree;
    BinTreeNode<T> *p;
    if((p=Parent(tree->lchild,now))!=nullptr)
        return p;
    else
    {
        p=Parent(tree->rchild,now);
        return p;
    }
}
template <typename T>
BinTreeNode<T>* BinTree<T>::LeftChild(BinTreeNode<T> *now)
{
    return (now==nullptr) ? nullptr:now->lchild;
}
template <typename T>
BinTreeNode<T>* BinTree<T>::RightChild(BinTreeNode<T>*now)
{
    return (now==nullptr) ? nullptr:now->rchild;
}
template <typename T>
void BinTree<T>::Traverse(BinTreeNode<T> *tree)
{
    if(tree!=nullptr)
    {
        cout<<tree->date<<" ";
        Traverse(tree->lchild);
        Traverse(tree->rchild);
    }
}
template <typename T>
void BinTree<T>::visit(BinTreeNode<T>* tree)
{
    cout<<tree->date<<"    ";
}
template <typename T>
void BinTree<T>::preOrder(BinTreeNode<T> *tree)
{
    if(tree==nullptr)
        return;
    visit(tree);
    preOrder(tree->lchild);
    preOrder(tree->rchild);
}
template <typename T>
void BinTree<T>::inOrder(BinTreeNode<T>* tree)
{
    if(tree==nullptr)
        return;
    inOrder(tree->lchild);
    visit(tree);
    inOrder(tree->rchild);
}
template <typename T>
void BinTree<T>::postOrder(BinTreeNode<T>*tree)
{
    if(tree==nullptr)
        return;
    postOrder(tree->lchild);
    postOrder(tree->rchild);
    visit(tree);
}
template <typename T>
void BinTree<T>::PreOrder(BinTreeNode<T>*tree)
{
    Stack<BinTreeNode<T>*> S;
    BinTreeNode<T> *p=tree;
    S.Push(nullptr);
    while(p!=nullptr)
    {
        visit(p);
        if(p->rchild!=nullptr)
            S.Push(p->rchild);
        if(p->lchild!=nullptr)
            p=p->lchild;
        else
            S.Pop(p);
    }
//    S.Push(p);
//    while(!S.IsEmpty())
//    {
//        S.Pop(p);
//        visit(p);
//        if(p->rchild!=nullptr)
//            S.Push(p->rchild);
//        if(p->lchild!=nullptr)
//            S.Push(p->lchild);
//    }
}
template <typename T>
void BinTree<T>::InOrder(BinTreeNode<T> *tree)
{
    Stack<BinTreeNode<T>*> S;
    BinTreeNode<T> *p=tree;
    do{
        while(p!=nullptr)
        {
            S.Push(p);
            p=p->lchild;
        }
        if(!S.IsEmpty())
        {
            S.Pop(p);
            visit(p);
            p=p->rchild;
        }
    }while(p!=nullptr||!S.IsEmpty());
}
template <typename T>
void BinTree<T>::PostOrder(BinTreeNode<T>* tree)
{
    Stack<BinTreeNode<T>*> S1;
    Stack<BinTreeNode<T>*> Res;
    BinTreeNode<T> *p=tree;
    S1.Push(p);
    while(!S1.IsEmpty())
    {
        S1.Pop(p);
        Res.Push(p);
        if(p->lchild!=nullptr)
            S1.Push(p->lchild);
        if(p->rchild!=nullptr)
            S1.Push(p->rchild);
    }
    while (!Res.IsEmpty()) {
        Res.Pop(p);
        visit(p);
    }
}
template <typename T>
void BinTree<T>::NodeLevel(BinTreeNode<T>* tree,T &x,int lev,int &level)
{
    if(tree==nullptr)
        level=0;
    else
    {
        if(tree->date==x)
            level=lev+1;
        else
        {
            if(level==0)
                NodeLevel(tree->lchild,x,lev+1,level);
            if(level==0)
                NodeLevel(tree->rchild,x,lev+1,level);
        }
    }
}
//template <typename T>
//istream& operator>>(istream& in, BinTreeNode<T>&c)
//{
//    CreateBinTree(in,c.root);
//    return in;
//}
//template <typename T>
//ostream& operator<<(ostream& out,BinTreeNode<T>& c)
//{
//    out<<"¶þ²æÊ÷Ç°Ðò±éÀú"<<endl;
//    c.Traversal(out,c.root);
//    out<<endl;
//    return out;
//}
template <typename T>
BinTree<T>::BinTree(BinTree<T>&s)
{
    root=Copy(s.root);
}
