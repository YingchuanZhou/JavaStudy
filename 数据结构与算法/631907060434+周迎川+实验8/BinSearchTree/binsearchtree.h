#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H
template <typename T,typename E>
struct BinSearchTreeNode
{
    T data;
    BinSearchTreeNode<T,E> *left,*right;
    BinSearchTreeNode()
    {

    }
    BinSearchTreeNode(T &x)
    {
        data=x,left=nullptr,right=nullptr;
    }
    ~BinSearchTreeNode()
    {

    }
};
template <typename T, typename E>
class BinSearchTree
{
private:
    BinSearchTreeNode<T, E> *root;
    T stop;
    BinSearchTreeNode<T, E>* Search(T &x,BinSearchTreeNode<T, E> *root);//搜索过程的子过程
    void makeEmpty(BinSearchTreeNode<T, E> *&root);//将二叉树置空子过程
    void PrintTree(BinSearchTreeNode<T, E> *root);//中序遍历打印二叉树子过程
    bool Remove(T &x,BinSearchTreeNode<T, E> *&root);//删除操作的子过程
    void visit(BinSearchTreeNode<T, E>*root);//输出结点值
public:
    BinSearchTree(T &st);
    BinSearchTree()
    {
        root=nullptr;//一定要置为空，递归结束需要用到
    }
    ~BinSearchTree()
    {

    }
    bool Search(T &x);//搜索操作
    void makeEmpty();//置空操作
    void PrintTree();//打印二叉树
    bool Insert(T &x);//插入x
    bool Insert(T &x, BinSearchTreeNode<T, E> *&root);//像二叉树中插入子过程
    bool Remove(T &x);//删除x
    bool CreateNum();//创建1000个数的搜索树
};
#endif // BINSEARCHTREE_H
