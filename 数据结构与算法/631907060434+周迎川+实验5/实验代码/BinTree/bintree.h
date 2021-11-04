#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
using namespace std;
template <typename T>
struct BinTreeNode
{
    T date;
    BinTreeNode *lchild,*rchild;
    BinTreeNode()
    {
        lchild=nullptr;rchild=nullptr;
    }
    BinTreeNode(T &x,BinTreeNode<T> *l=nullptr,BinTreeNode<T> *r=nullptr)
    {
        date=x;rchild=r;lchild=l;
    }
};
template <typename T>
class BinTree
{
private:
    BinTreeNode<T> *root;
    T stop;
    //bool Insert(BinTreeNode<T> *&tree,T& x);//�������
    void CreateBinTree(BinTreeNode<T> *&tree);//ǰ�򴴽�������
    void destroy(BinTreeNode<T>*& tree);//ɾ��
    BinTreeNode<T>* Find(BinTreeNode<T>*& tree,T& x);//����x
    int Height(BinTreeNode<T>* tree);//�����ĸ߶�
    int Size(BinTreeNode<T>* tree);//�����Ľ�����
    int LeavesCount(BinTreeNode<T> *tree);//��Ҷ�ڵ�����
    BinTreeNode<T>* Parent(BinTreeNode<T>* tree,BinTreeNode<T>* now);//�ҵ�˫�׽��
    void visit(BinTreeNode<T>*tree);//���ʺ���
    void preOrder(BinTreeNode<T> *tree);//ǰ�����
    void inOrder(BinTreeNode<T> *tree);//�������
    void postOrder(BinTreeNode<T> *tree);//��������
    void PreOrder(BinTreeNode<T> *tree);//ǰ�����
    void InOrder(BinTreeNode<T> *tree);//�������
    void PostOrder(BinTreeNode<T> *tree);//��������
    void NodeLevel(BinTreeNode<T>* tree,T &x,int lev,int &level);//ĳ���������һ��
    //friend istream& operator>>(istream& in,BinTreeNode<T>& tr);//����>>
    //friend ostream& operator<<(ostream& out,BinTreeNode<T>& tr);//����<<
public:
    BinTree()//���캯��
    {
        root=nullptr;stop=-1;
    }
    BinTree(BinTree<T>& c);//���ƹ��캯��
    void CreateBinTree()
    {
        CreateBinTree(this->root);
    }
    ~BinTree()//��������
    {
        destroy(root);
    }
    bool IsEmpty()//�п�
    {
        return (root==nullptr)? true:false;
    }
    int NodeDeg(BinTreeNode<T>*now);//����ýڵ�Ķ�
    BinTreeNode<T>* Parent(BinTreeNode<T> *now)//���ظ��ڵ�
    {
        return (root==nullptr||now==root) ? nullptr:Parent(root,now);
    }
    BinTreeNode<T>* LeftChild(BinTreeNode<T>* now);//�ҵ���������Ů
    BinTreeNode<T>* RightChild(BinTreeNode<T>* now);//�ҵ���������Ů
    BinTreeNode<T>* Copy(BinTreeNode<T>* origin);//����
    void Traverse(BinTreeNode<T>* tree);//ǰ��������
//    BinTreeNode<T>* LeftChild(BinTreeNode<T> *now)//��������������ַ
//    {
//        return (now==nullptr)? nullptr:now->lchild;
//    }
//    BinTreeNode<T>* RightChild(BinTreeNode<T> *now)//��������������ַ
//    {
//        return (now==nullptr)? nullptr:now->rchild;
//    }
    int Height()//�������ĸ߶�
    {
        return Height(root);
    }
    int Size()//�������Ľ����
    {
        return Size(root);
    }
    BinTreeNode<T>* getRoot()//��ȡ�����
    {
        return root;
    }
    void preOrder()//ǰ�����
    {
        preOrder(this->root);
    }

    void inOrder()//�������
    {
        inOrder(this->root);
    }
    void postOrder()//��������
    {
        postOrder(this->root);
    }
    void PreOrder()//ǰ�����
    {
        preOrder(this->root);
    }

    void InOrder()//�������
    {
        inOrder(this->root);
    }
    void PostOrder()//��������
    {
        postOrder(this->root);
    }
    //int Insert(T& x);
    BinTreeNode<T>* Find(T& x)
    {
        return Find(this->root,x);
    }
    int LeavesCount()
    {
    return LeavesCount(root);
    }
    int NodeLevel(T& x)
    {
        int level=0;
        NodeLevel(root,x,0,level);
        return level;
    }
    void setRoot(BinTreeNode<T>*tree)
    {
        root=tree;
    }
};
#endif // BINTREE_H
