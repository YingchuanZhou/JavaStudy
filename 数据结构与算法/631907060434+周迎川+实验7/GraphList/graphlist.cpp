#include "graphlist.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "queue.h"
#include "queue.cpp"
using namespace std;
template <typename T, typename E>
int GraphList<T, E>::getVertexIndex(const T &vertex)
{
    //根据顶点名字获取顶点数组的索引，没有该顶点返回-1
    for(int i=0;i<numVertex;i++)
    {
        if(NodeArray[i].name==vertex)
            return i;
    }
    return -1;
}
template <typename T, typename E>
bool GraphList<T, E>::reSize(int size)
{
    //如果原来的定点数组不够大，将其扩展为原来的两倍
    //定义一个新的顶点数组，将原来的顶点数组依次赋值给新数组，并且将原来的数组删除
    //将新数组赋值给原来数组
    Vertex<T, E> *NewNodeArray = new Vertex<T, E>[size*2];
    if(NewNodeArray==nullptr)
    {
        cerr<<"内存分配失败！！！"<<endl;
        return false;
    }
    maxVertex=2*size;
    for(int i=0; i<numVertex; i++)
    {
        NewNodeArray[i].name=NodeArray[i].name;
        NewNodeArray[i].link=NodeArray[i].link;
    }
    for(int i=numVertex; i<maxVertex; i++)
        NewNodeArray[i].link=nullptr;
    delete [] NodeArray;
    NodeArray=NewNodeArray;
    return true;
}
template <typename T, typename E>
GraphList<T, E>::GraphList(int size)
{
    //首先将邻接表的顶点数组分配好，顶点链表中存有顶点的名字还有边链表的头指针
    //如果分配内存失败暑促和提示信息并且退出
    //分配成功之后将边链表的头指针置为nullptr
    maxVertex=size;numEdge=0;numVertex=0;
    NodeArray = new Vertex<T, E>[maxVertex];
    if(NodeArray==nullptr)
    {
        cerr<<"内存分配失败！！！"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<maxVertex;i++)
        NodeArray[i].link=nullptr;
}
template <typename T, typename E>
GraphList<T, E>::~GraphList()
{
    //析构函数，首先将边链表的结点释放调再释放顶点数组
    for(int i=0; i<numVertex; i++)
    {
        Edge<T, E> *p=NodeArray[i].link;
        while(p!=nullptr)
        {
            NodeArray[i].link=p->next;
            delete p;
            p=NodeArray[i].link;
        }
    }
    delete [] NodeArray;
}
template <typename T, typename E>
int GraphList<T, E>::NumberOfVertex()
{
    //返回顶点数
    return numVertex;
}
template <typename T, typename E>
int GraphList<T, E>::NumberOfEdge()
{
    //返回边数
    return numEdge;
}
template <typename T,typename E>
bool GraphList<T, E>::IsFull() const
{
    //判断顶点是否已经满了，边是链表，不需要判断是否满
    return (maxVertex==numVertex) ? true :false;
}
template <typename T, typename E>
T GraphList<T, E>::getName(int v)
{
    //通过顶点的索引下标返回顶点的名字
    if(v<0 || v>=numVertex)
    {
        cerr<<"没有该顶点!!!"<<endl;
        return 0;
    }
    return NodeArray[v].name;
}
template <typename T, typename E>
E GraphList<T, E>::getWeight(int v1, int v2)
{
    //获取边的权值
    //如果第v1个顶点和第v2个顶点不存在，返回负权值
    //存在则找到第v1-v2的边，返回权值，没有找到返回-1
    if(v1==-1 && v2==-1)
        return -1;//返回负权值
    Edge<T, E> *p= NodeArray[v1].link;
    while(p != nullptr && p->node != v2)
        p=p->next;
    if(p!=nullptr)
        return p->weight;
    else
        return -1;
}
template <typename T, typename E>
bool GraphList<T, E>::IsExistVertex(T &v)
{
    //判断是否存在名字为v的顶点
    for(int i=0; i<numVertex;i++)
        if(NodeArray[i].name==v)
            return true;
    return false;
}
template <typename T, typename E>
bool GraphList<T, E>::InsertVertex(T &v)
{
    //插入顶点
    //如果顶点存在，输出提示信息，返回false
    //不存在，先判断是否已经满了，满了进行扩展
    //然后把顶点的名字赋给NodeArray，下标为当前顶点数，然后当前顶点值加1
    if(IsExistVertex(v))
    {
        cerr<<"顶点已经存在！！！"<<endl;
        return false;
    }
    if(IsFull())
        reSize(maxVertex);
    NodeArray[numVertex].name=v;
    numVertex++;
    return true;
}
template <typename T, typename E>
bool GraphList<T, E>::InsertEdge(int v1, int v2,E weight)
{
    //插入边
    //首先判断第v1和v2两个顶点是否合法，不合法输出提示信息
    //合法定义两个边节点指针，先在边链表中搜索，看v2是否已经存在边链表中
    //如果存在返回false，不存在则定义一个边界点，
    //并且将v2顶点赋值给新节点的node将weight赋值给新节点的weight，连入边链表中
    //因为是无向图，所以还要寻找到对称点，将对称的v2-v1的边
    //同样将v1赋值给节点的node，将weight赋值给节点的weight
    //然后边的数量加1
    if(v1>=0 && v1<numVertex && v2>=0 && v2<numVertex)
    {
        Edge<T, E> *p=NodeArray[v1].link, *q;
        while(p != nullptr && p->node!=v2)
            p=p->next;
        if(p != nullptr)
            return false;
        p= new Edge<T, E>;
        p->node=v2;p->weight=weight;
        p->next=NodeArray[v1].link;
        NodeArray[v1].link=p;
        q= new Edge<T, E>;
        q->node=v1;q->weight=weight;
        q->next=NodeArray[v2].link;
        NodeArray[v2].link=q;
        numEdge++;
        return true;
    }
    else
    {
        cerr<<"不存在该顶点！！！"<<endl;
        return false;
    }
}
template <typename T,typename E>
bool GraphList<T, E>::RemoveVertex(T &x)
{
    //删除顶点
    //首先删除每个每一条边链表中含有该顶点的边
    //然后再把最后一个顶点移动到该顶点的位置，将该顶点覆盖
    //然后再把边链表中两个顶点中含有最后一个顶点的边链表node修改
    int n=getVertexIndex(x);
    if(n<0)
    {
        cerr<<"没有该顶点！！！"<<endl;
        return false;
    }
    Edge<T, E> *p,*q,*t=nullptr;int k;
    while(NodeArray[n].link!=nullptr)
    {
        p=NodeArray[n].link;
        k=p->node;
        q=NodeArray[k].link;
        while(q!=nullptr && q->node!=n)
        {
            t=q; q=q->next;
        }
        if(q!=nullptr)
        {
            if(t==nullptr)
                NodeArray[k].link=q->next;
            else
                t->next=q->next;
            delete q;
        }
        NodeArray[n].link=p->next;
        delete p;
        numEdge--;
    }
    numVertex--;
    NodeArray[n].name=NodeArray[numVertex].name;
    NodeArray[n].link=NodeArray[numVertex].link;
    p=NodeArray[n].link;
    while(p!=nullptr)
    {
        q=NodeArray[p->node].link;
        while(q!=nullptr)
        {
            if(q->node==numVertex)
            {
                q->node=n; break;
            }
            else
                q=q->next;
        }
    }
    return true;
}
template <typename T, typename E>
bool GraphList<T, E>::RemoveEdge(int v1, int v2)
{
    //删除边
    //两点确定一条边，首先找到第一个顶点的下标和边链表的头指针，
    //通过头指针找到v2，并且将v2这个边链表节点删掉
    //对称的找到第二个顶点的边链表头指针，找到边链表节点为v1的结点删掉
    if(v1>=0 && v1<numVertex && v2>=0 && v2<numVertex)
    {
        Edge<T, E> *p=NodeArray[v1].link, *q;
        while(p!=nullptr && p->node != v2)
        {
            q=p;p=p->next;
        }
        if(p!=nullptr)
        {
            q->next=p->next;
            delete p;
        }
        else
        {
            cerr<<v1<<"顶点与"<<v2<<"顶点之间不存在边"<<endl;
            return false;
        }
        p=NodeArray[v2].link;
        while(p!=nullptr && p->node!=v1)
        {
            q=p;p=p->next;
        }
        if(p!=nullptr)
        {
            q->next=p->next;
            delete p;
        }
        else
        {
            cerr<<v1<<"顶点与"<<v2<<"顶点之间不存在边"<<endl;
            return false;
        }
    }
    else
    {
        cerr<<"没有该顶点！！！"<<endl;
        return false;
    }
}
template <typename T, typename E>
int GraphList<T, E>::DegOfVertex(int v)
{
    //顶点的度数就是边结点的个数
    int degree=0;//顶点的度
    Edge<T, E> *p=NodeArray[v].link;
    while(p!=nullptr)
    {
        degree++;
        p=p->next;
    }
    return degree;
}
template <typename T, typename E>
int GraphList<T, E>::getFirstNode(int v)
{
    //获取顶点的第一个边结点
    if(v!=-1)
    {
        Edge<T, E> *p = NodeArray[v].link;
        if(p!=nullptr)
            return p->node;
    }
    return -1;
}
template <typename T, typename E>
int GraphList<T, E>::getNextNode(int v,int w)
{
    //获取w的下一个结点
    if(v!=-1)
    {
        Edge<T,E> *p=NodeArray[v].link;
        while(p!=nullptr && p->node!=w)
            p=p->next;
        if(p!=nullptr && p->next!=nullptr)
            return p->next->node;
    }
    return -1;
}
template <typename T, typename E>
void GraphList<T,E>::DFS(GraphList<T, E> &G, T &v)
{
    //深度优先搜索，要定义一个标记数组，表示顶点是否已经被访问
    int n=G.NumberOfVertex();
    bool *visit = new bool[n];
    for(int i=0;i<n;i++)
        visit[i]=false;
    int m =G.getVertexIndex(v);
    DFS(G,m,visit);
    delete [] visit;
}
template <typename T, typename E>
void GraphList<T, E>::DFS(GraphList<T, E> &G,int index,bool visit[])
{
    //深度优先遍历的子过程
    //首先获取边链表的第一个结点，只要边链表还有结点，就一直往下获取节点
    cout<<G.getName(index)<<" ";
    visit[index]=true;
    int n = G.getFirstNode(index);
    while(n!=-1)
    {
        if(visit[n]==false)
            DFS(G,n,visit);
        n=G.getNextNode(index,n);
    }
}
template <typename T, typename E>
void GraphList<T, E>::BFS(GraphList<T, E>& G, T& v)
{
    int n=G.NumberOfVertex();
    bool *visit=new bool[n];
    for(int i=0; i<n; i++)
        visit[i]=false;
    int index=G.getVertexIndex(v);
    cout<<G.getName(index)<<" ";
    visit[index]=true;
    ListQueue<int> Q;
    Q.EnQueue(index);
    while(!Q.IsEmpty())
    {
        Q.DeQueue(index);
        int m = G.getFirstNode(index);
        while(m!=-1)
        {
            if(visit[m]==false)
            {
                cout<<G.getName(m)<<" ";
                visit[m]=true;
                Q.EnQueue(m);
            }
            m=G.getNextNode(index,m);
        }
    }
    delete [] visit;
}
template <typename T, typename E>
istream& operator>>(istream& in, GraphList<T, E> &G)
{
    int n,m; T v1,v2; E w;
    cout<<"输入顶点数和边数："<<endl;
    in>>n>>m;
    if(n>G.maxVertex)
    {
        cerr<<"输入的顶点数过大！！！"<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"输入顶点名字！"<<endl;
    for(int i=0; i<n; i++)
    {
        in>>v1;
        G.InsertVertex(v1);
    }
    for(int i=0; i<m; i++)
    {
        cout<<"输入边的两个顶点和权值："<<endl;
        in>>v1>>v2>>w;
        int j=G.getVertexIndex(v1);int k=G.getVertexIndex(v2);
        if(j==-1||k==-1)
            cout<<"边的信息有误！！！"<<endl;
        else
            G.InsertEdge(v1,v2,w);

    }
    return in;
}
template <typename T, typename E>
ostream& operator<<(ostream& out, GraphList<T, E>& G)
{
    int n,m;T v1,v2; E w;Edge<T, E> *p,*q;
    n=G.NumberOfVertex();m=G.NumberOfEdge();
    out<<"顶点数："<<n<<"边数："<<m<<endl;
    out<<"(顶点1，顶点2，权值"<<endl;
    for(int i=0; i<n; i++)
    {
        p=G.NodeArray[i].link;
        while(p!=nullptr)
        {
            out<<"("<<G.getName(i)<<","<<p->node<<","<<G.getWeight(i,p->node)<<")"<<endl;
        }
    }
    return out;
}
template <typename T, typename E>
void GraphList<T, E>::ReadFile(char filename[],GraphList<T, E> &G)
{
    ifstream fin;
    fin.open(filename);
    if(fin.fail())
    {
        cerr<<"打开文件失败！！！"<<endl;
        return;
    }
    fin>>G;
}
template <typename T, typename E>
void GraphList<T,E>::SaveFile(char filename[], GraphList<T, E> &G)
{
    ofstream fout;
    fout.open(filename);
    if(fout.fail())
    {
        cerr<<"打开文件失败！！！"<<endl;
        return;
    }
    fout<<G;
}
