#ifndef MINSPANTREE_H
#define MINSPANTREE_H
#define Defaultsize 100
template <typename T, typename E>
struct MinSpanTreeEdge
{
    int head,last; E weight;//��С�������ı߽�����ʼ�����ֹ�㣬����Ȩֵ
    MinSpanTreeEdge()
    {
        head=-1;last=-1;weight=0;//��ʼ��
    }
    bool operator<(MinSpanTreeEdge<T, E> &Edge)//����С�����������С���ƶ���ʱ����
    {
        if(weight<Edge.weight)
            return true;
        else
            return false;
    }
    bool operator>(MinSpanTreeEdge<T, E>& Edge)//���ش��ڷ��ţ���С���ƶ���ʱ����
    {
        if(weight>Edge.weight)
            return true;
        else
            return false;
    }
    bool operator=(MinSpanTreeEdge<T, E>& Edge)//���ص��ڷ��ţ���С���ƶ���ʱ����
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
    MinSpanTreeEdge<T,E> *Edge;//�����ָ������
    int maxEdge,curEdge;//�������͵�ǰ����
public:
    MinSpanTree(int size=Defaultsize)
    {
        Edge = new MinSpanTreeEdge<T, E>[size];//��̬�����ڴ�
        maxEdge=size;curEdge=0;//��ʼ��
    }
    bool Insert(MinSpanTreeEdge<T, E> &edge)
    {
        //������������һ����
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
    void Dispaly(MinSpanTree<T, E> &MST);//��ʾ��С������
};
#endif // MINSPANTREE_H
