#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>
#define DefaultSize 20
using namespace std;
template <typename T, typename E>
struct Edge
{
    int node;//����һ���ڵ���±�
    E weight;//Ȩֵ
    Edge<T, E> *next;//�����������ָ��
    Edge()
    {

    }
    Edge(int num,E weight)//���캯��
    {
        node=num;this->weight=weight;next=nullptr;
    }
    bool operator==(Edge<T, E> &X)//�жϱ����
    {
        return (X.node==node) ? true : false;
    }
    bool operator!=(Edge<T, E> &X)//�жϱ߲����
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
    T name;//�������
    Edge<T,E> *link;//���нڵ�������������
    Vertex(T name)//���캯��
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
    Vertex<T, E> *NodeArray;//�������
    int maxVertex;//����������
    int numVertex;//��ǰ�����
    int numEdge;//��ǰ����
    bool reSize(int size);//ͼ����չ
public:
    GraphList(int size=DefaultSize);//ͼ�Ĺ��캯��
    ~GraphList();//ͼ����������
    int NumberOfEdge();//�ߵ�����
    int NumberOfVertex();//��������
    int getVertexIndex(const T &vertex);//��ȡ��������
    bool IsFull() const;//�ж�ͼ�Ƿ��Ѿ�����
    T getName(int v);//��ȡ�ڵ�����
    E getWeight(int v1, int v2);//��ȡ�ߵ�Ȩֵ
    bool IsExistVertex(T &v);//�ж�v�����Ƿ����
    bool InsertVertex(T &x);//��ӽڵ�
    bool InsertEdge(int v1, int v2, E weight);//��ӱ�
    bool RemoveVertex(T &x);//ɾ�����
    bool RemoveEdge(int v1, int v2);//ɾ����
    int DegOfVertex(int v);//����ָ������Ķ�
    int getFirstNode(int v);//��ȡ��һ��һ���ڽӵ�
    int getNextNode(int v, int w);//��ȡv�ڽӱ���w��һ������
    void DFS(GraphList<T, E> &G, T &v);//ͼ�������������
    void DFS(GraphList<T, E> &G, int index, bool visit[]);//��������������ӹ���
    void BFS(GraphList<T, E> &G, T &v);//ͼ�Ĺ����������
    friend istream& operator>>(istream& in,GraphList<T, E> &G);//����>>
    friend ostream& operator<<(ostream& out,GraphList<T, E> &G);//����<<
    void ReadFile(char filename[], GraphList<T, E> &G);//���ļ�
    void SaveFile(char filename[], GraphList<T, E> &G);//�����ļ�
};
#endif // GRAPHLIST_H
