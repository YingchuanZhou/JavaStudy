#include "binsearchtree.h"
#include <iostream>
#include <time.h>
using namespace std;
template <typename T, typename E>
BinSearchTree<T, E>::BinSearchTree(T &st)
{
    //����������������������Ϊ��
    //�����ֵΪstopʱ����ѭ��
    stop = st; root=nullptr;
    T x;
    cout<<"����߽���ֵ����-1������"<<endl;
    cin>>x;
    while (x!=stop) {
        Insert(x,root);
        cin>>x;
    }
}
template <typename T, typename E>
BinSearchTreeNode<T, E>* BinSearchTree<T, E>::Search(T &x, BinSearchTreeNode<T, E>*root)
{
    //�����������ӹ���
    //���˵���Ϊ�գ����ؿ�ָ�룬�ݹ����֮һ
    //������������������С��������������ȸ��ڵ����ֵС��������������������ȸ��ڵ���ֵ������������������
    //�����������ؽڵ�ָ��
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
    //���������ָ�벻Ϊ�գ��������ˣ����򷵻�false
    if(Search(x,root)!=nullptr)
        return true;
    return false;
}
template <typename T, typename E>
void BinSearchTree<T, E>::makeEmpty()
{
    //�ÿգ���root��Ϊ��
    makeEmpty(root);
    root=nullptr;
}
template <typename T, typename E>
void BinSearchTree<T, E>::makeEmpty(BinSearchTreeNode<T, E> *&root)
{
    //�ÿյ��ӹ��̣����root��Ϊ�գ�������������������Ϊ�գ�Ȼ����ɾ�����ڵ�
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
    //������ʺ��������ָ����ָ��ֵ
    cout<<root->data<<" ";
}
template <typename T, typename E>
void BinSearchTree<T, E>::PrintTree(BinSearchTreeNode<T, E>* root)
{
    //���������������ӹ��̣��������������������һ����������
    if(root==nullptr)
        return;
    PrintTree(root->left);
    visit(root);
    PrintTree(root->right);
}
template <typename T, typename E>
void BinSearchTree<T, E>::PrintTree()
{
    //��������������
    PrintTree(root);
}
template <typename T, typename E>
bool BinSearchTree<T, E>::Insert(T &x, BinSearchTreeNode<T, E>*&root)
{
    //����x���ӹ��̣����˵rootΪ�գ�����һ���ڵ㣬��ʼ������Ϊx������true
    //���˵root��Ϊ�գ�x��ֵ��rootС�Ͳ�������������root��Ͳ���������
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
    //������ӹ��̣��ɹ�����true�����ɹ�����false
    if(Insert(x,root))
        return true;
    return false;
}
template <typename T, typename E>
bool BinSearchTree<T, E>::Remove(T &x, BinSearchTreeNode<T, E>*&root)
{
    //ɾ��x��������ڵ�Ϊ�գ�ֱ�ӷ���false
    //���x��dataС��ȥ��������ɾ���������data��ȥ������ɾ��
    //�����data����x����root���������������ڣ�ȥ���������ҵ���С�������Ǿ�����������������
    //һֱҪ��������������Ϊֹ��Ȼ���������ֵ�����ڵ㣬Ȼ��ɾ���Ľ��
    //���˵���ڵ������������һ��Ϊ�գ���ֱ�ӽ��Ľ��ɾ����ֱ�ӽ�ָ���޸�Ϊ��һ���ڵ�
    BinSearchTreeNode<T, E> *temp;
    if(root==nullptr)
        return false;
    if(x<root->data)
        return Remove(x, root->left);
    if(x>root->data)
        return Remove(x, root->right);
    else if(root->left!=nullptr && root->right!=nullptr)
    {
        temp=root->right;//��ָ�����ұ߻������
        while(temp->left!=nullptr)
            temp=temp->left;
        root->data=temp->data;
        return Remove(root->data,temp);//ɾ����������temp���
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
    //ɾ��x��ɾ���ɹ�����true�����ɹ�����false
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
