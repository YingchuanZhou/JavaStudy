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
    BinSearchTreeNode<T, E>* Search(T &x,BinSearchTreeNode<T, E> *root);//�������̵��ӹ���
    void makeEmpty(BinSearchTreeNode<T, E> *&root);//���������ÿ��ӹ���
    void PrintTree(BinSearchTreeNode<T, E> *root);//���������ӡ�������ӹ���
    bool Remove(T &x,BinSearchTreeNode<T, E> *&root);//ɾ���������ӹ���
    void visit(BinSearchTreeNode<T, E>*root);//������ֵ
public:
    BinSearchTree(T &st);
    BinSearchTree()
    {
        root=nullptr;//һ��Ҫ��Ϊ�գ��ݹ������Ҫ�õ�
    }
    ~BinSearchTree()
    {

    }
    bool Search(T &x);//��������
    void makeEmpty();//�ÿղ���
    void PrintTree();//��ӡ������
    bool Insert(T &x);//����x
    bool Insert(T &x, BinSearchTreeNode<T, E> *&root);//��������в����ӹ���
    bool Remove(T &x);//ɾ��x
    bool CreateNum();//����1000������������
};
#endif // BINSEARCHTREE_H
