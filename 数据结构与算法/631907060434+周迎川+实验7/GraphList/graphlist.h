#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>
#define DefaultSize 20
using namespace std;
template <typename T, typename E>
struct Edge
{
    int node;//另外一个节点的下标
    E weight;//权值
    Edge<T, E> *next;//边链表的连接指针
    Edge()
    {

    }
    Edge(int num,E weight)//构造函数
    {
        node=num;this->weight=weight;next=nullptr;
    }
    bool operator==(Edge<T, E> &X)//判断边相等
    {
        return (X.node==node) ? true : false;
    }
    bool operator!=(Edge<T, E> &X)//判断边不想等
    {
        return (X.node!=node) ? true : false;
    }
    bool operator>(Edge<T,E> &edge)
    {
        if(edge.weight<weight)
            return true;
        return false;
    }
};
template <typename T, typename E>
struct Vertex
{
    T name;//结点名字
    Edge<T,E> *link;//所有节点与边链表的连接
    Vertex(T name)//构造函数
    {
        this->name=name; link=nullptr;
    }
    Vertex()
    {

    }
};
template <typename T, typename E>
class GraphList
{
private:
    Vertex<T, E> *NodeArray;//结点数组
    int maxVertex;//最大数量结点
    int numVertex;//当前结点数
    int numEdge;//当前边数
    bool reSize(int size);//图的扩展
public:
    GraphList(int size=DefaultSize);//图的构造函数
    ~GraphList();//图的析构函数
    int NumberOfEdge();//边的数量
    int NumberOfVertex();//结点的数量
    int getVertexIndex(const T &vertex);//获取结点的索引
    bool IsFull() const;//判断图是否已经满了
    T getName(int v);//获取节点名字
    E getWeight(int v1, int v2);//获取边的权值
    bool IsExistVertex(T &v);//判断v顶点是否存在
    bool InsertVertex(T &x);//添加节点
    bool InsertEdge(int v1, int v2, E weight);//添加边
    bool RemoveVertex(T &x);//删除结点
    bool RemoveEdge(int v1, int v2);//删除边
    int DegOfVertex(int v);//计算指定顶点的度
    int getFirstNode(int v);//获取第一个一个邻接点
    int getNextNode(int v, int w);//获取v邻接表中w下一个顶点
    void DFS(GraphList<T, E> &G, T &v);//图的深度优先搜索
    void DFS(GraphList<T, E> &G, int index, bool visit[]);//深度优先搜索的子过程
    void BFS(GraphList<T, E> &G, T &v);//图的广度优先搜索
    friend istream& operator>>(istream& in,GraphList<T, E> &G);//重载>>
    friend ostream& operator<<(ostream& out,GraphList<T, E> &G);//重载<<
    void ReadFile(char filename[], GraphList<T, E> &G);//读文件
    void SaveFile(char filename[], GraphList<T, E> &G);//保存文件
};
#endif // GRAPHLIST_H
