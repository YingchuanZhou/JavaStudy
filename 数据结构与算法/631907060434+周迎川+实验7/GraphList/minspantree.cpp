#include "minspantree.h"
#include "minheap.h"
#include "minheap.cpp"
#include "ufsets.cpp"
#include "graphlist.h"
//#include "graphlist.cpp"
template <typename T, typename E>
void Kruskal(GraphList<T, E> &G, MinSpanTree<T, E>& MST)
{
    //�����еı߼�����С����
    //���ò��鼯��ѡ����С������С�ıߣ�Ȼ��ͨ�����鼯���ѯ
    MinSpanTreeEdge<T, E> edge;int u,v,account;
    int n =G.NumberOfVertex();
    int m=G.NumberOfEdge();
    MinHeap<MinSpanTreeEdge<T, E>> H(m);
    UFSets F(n);
    for(u=0; u<n; u++)
        for(v=u+1; v<n;v++)
        {
            if(G.getWeight(u,v)!=-1)
            {
                edge.head=u;edge.last=v;
                edge.weight=G.getWeight(u,v);
                H.Insert(edge);
            }
        }
    account=1;
    while (account<n) {
        H.RemoveMin(edge);
        u=F.Find(edge.head);
        v=F.Find(edge.last);
        if(u!=v)
        {
            F.Union(u,v);
            MST.Insert(edge);
            account++;
        }
    }
}
template <typename T, typename E>
void Prim(GraphList<T, E>&G, T u, MinSpanTree<T, E> &MST)
{
    //�ȴ���һ����С�ѣ���һ��������飬�����е���u�����ӵı߽�����С�ѣ�Ȼ�����С����ȡ��Ȩֵ��С�ѱ�
    //���Ϊ�������fasleȻ�󽫸õ�ı������ֵ��Ϊtrue�������ñ߲�����С�������ı�������
    //��С��������n-1���ߣ���Ϊѭ���Ľ�������
    int n=G.NumberOfVertex();int m=G.NumberOfEdge();
    int index=G.getVertexIndex(u),index2;
    MinSpanTreeEdge<T, E> edge;
    MinHeap<MinSpanTreeEdge<T, E>> H(m);
    bool *Vmst=new bool[n];
    for(int i=0; i<n; i++)
        Vmst[i]=false;
    Vmst[index]=true;
    int account=1;
    do
    {
        index2=G.getFirstNode(index);
        while(index2!=-1)
        {
            if(Vmst[index2]==false)
            {
                edge.head=index2;edge.last=index;
                edge.weight=G.getWeight(index,index2);
                H.Insert(edge);
            }
            index2=G.getNextNode(index,index2);
        }
        while(H.IsEmpty()==false && account<n)
        {
            H.RemoveMin(edge);
            if(Vmst[edge.head]==false)
            {
                MST.Insert(edge);
                index=edge.head;
                Vmst[edge.head]=true;
                account++;
                break;
            }
        }
    }while(account<n);//n���������С��������Ҫn-1����
}
template <typename T, typename E>
void MinSpanTree<T, E>::Dispaly(MinSpanTree<T, E> &MST)
{
    //��ʾ��С�������ı�
    for(int i=0; i<MST.curEdge; i++)
    {
        cout<<MST.Edge[i].head<<"--"<<MST.Edge[i].last
           <<"  "<<MST.Edge[i].weight<<endl;
    }
}
