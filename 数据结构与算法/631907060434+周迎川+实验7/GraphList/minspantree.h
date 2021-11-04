#ifndef MINSPANTREE_H
#define MINSPANTREE_H
#define Defaultsize 100
template <typename T, typename E>
struct MinSpanTreeEdge
{
    int head,last; E weight;//最小生成树的边结点的起始点和终止点，还有权值
    MinSpanTreeEdge()
    {
        head=-1;last=-1;weight=0;//初始化
    }
    bool operator<(MinSpanTreeEdge<T, E> &Edge)//重载小于运算符，最小堆移动的时候用
    {
        if(weight<Edge.weight)
            return true;
        else
            return false;
    }
    bool operator>(MinSpanTreeEdge<T, E>& Edge)//重载大于符号，最小堆移动的时候用
    {
        if(weight>Edge.weight)
            return true;
        else
            return false;
    }
    bool operator=(MinSpanTreeEdge<T, E>& Edge)//重载等于符号，最小堆移动的时候用
    {
        if(weight==Edge.weight)
            return true;
        else
            return false;
    }
};
template <typename T, typename E>
class MinSpanTree
{
private:
    MinSpanTreeEdge<T,E> *Edge;//定义边指针数组
    int maxEdge,curEdge;//最大边数和当前边数
public:
    MinSpanTree(int size=Defaultsize)
    {
        Edge = new MinSpanTreeEdge<T, E>[size];//动态分配内存
        maxEdge=size;curEdge=0;//初始化
    }
    bool Insert(MinSpanTreeEdge<T, E> &edge)
    {
        //向边数组里面加一条边
        if(curEdge<maxEdge-1)
        {
            Edge[curEdge].head=edge.head;
            Edge[curEdge].last=edge.last;
            Edge[curEdge].weight=edge.weight;
            curEdge++;
            return true;
        }
        return false;
    }
    void Dispaly(MinSpanTree<T, E> &MST);//显示最小生成树
};
#endif // MINSPANTREE_H
