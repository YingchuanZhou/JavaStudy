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
    //bool Insert(BinTreeNode<T> *&tree,T& x);//插入操作
    void CreateBinTree(BinTreeNode<T> *&tree);//前序创建二叉树
    void destroy(BinTreeNode<T>*& tree);//删除
    BinTreeNode<T>* Find(BinTreeNode<T>*& tree,T& x);//查找x
    int Height(BinTreeNode<T>* tree);//求树的高度
    int Size(BinTreeNode<T>* tree);//求树的结点个数
    int LeavesCount(BinTreeNode<T> *tree);//求叶节点数量
    BinTreeNode<T>* Parent(BinTreeNode<T>* tree,BinTreeNode<T>* now);//找到双亲结点
    void visit(BinTreeNode<T>*tree);//访问函数
    void preOrder(BinTreeNode<T> *tree);//前序遍历
    void inOrder(BinTreeNode<T> *tree);//中序遍历
    void postOrder(BinTreeNode<T> *tree);//后续遍历
    void PreOrder(BinTreeNode<T> *tree);//前序遍历
    void InOrder(BinTreeNode<T> *tree);//中序遍历
    void PostOrder(BinTreeNode<T> *tree);//后续遍历
    void NodeLevel(BinTreeNode<T>* tree,T &x,int lev,int &level);//某个结点再哪一层
    //friend istream& operator>>(istream& in,BinTreeNode<T>& tr);//重载>>
    //friend ostream& operator<<(ostream& out,BinTreeNode<T>& tr);//重载<<
public:
    BinTree()//构造函数
    {
        root=nullptr;stop=-1;
    }
    BinTree(BinTree<T>& c);//复制构造函数
    void CreateBinTree()
    {
        CreateBinTree(this->root);
    }
    ~BinTree()//析构函数
    {
        destroy(root);
    }
    bool IsEmpty()//判空
    {
        return (root==nullptr)? true:false;
    }
    int NodeDeg(BinTreeNode<T>*now);//计算该节点的度
    BinTreeNode<T>* Parent(BinTreeNode<T> *now)//返回父节点
    {
        return (root==nullptr||now==root) ? nullptr:Parent(root,now);
    }
    BinTreeNode<T>* LeftChild(BinTreeNode<T>* now);//找到结点的左子女
    BinTreeNode<T>* RightChild(BinTreeNode<T>* now);//找到结点的有子女
    BinTreeNode<T>* Copy(BinTreeNode<T>* origin);//复制
    void Traverse(BinTreeNode<T>* tree);//前序遍历输出
//    BinTreeNode<T>* LeftChild(BinTreeNode<T> *now)//返回左子树结点地址
//    {
//        return (now==nullptr)? nullptr:now->lchild;
//    }
//    BinTreeNode<T>* RightChild(BinTreeNode<T> *now)//返回右子树结点地址
//    {
//        return (now==nullptr)? nullptr:now->rchild;
//    }
    int Height()//计算树的高度
    {
        return Height(root);
    }
    int Size()//计算树的结点数
    {
        return Size(root);
    }
    BinTreeNode<T>* getRoot()//获取根结点
    {
        return root;
    }
    void preOrder()//前序遍历
    {
        preOrder(this->root);
    }

    void inOrder()//中序遍历
    {
        inOrder(this->root);
    }
    void postOrder()//后续遍历
    {
        postOrder(this->root);
    }
    void PreOrder()//前序遍历
    {
        preOrder(this->root);
    }

    void InOrder()//中序遍历
    {
        inOrder(this->root);
    }
    void PostOrder()//后续遍历
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
