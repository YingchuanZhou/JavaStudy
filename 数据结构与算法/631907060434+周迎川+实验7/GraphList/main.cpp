#include <iostream>
#include <cstdlib>
#include "graphlist.h"
#include "graphlist.cpp"
#include "minspantree.h"
#include "minspantree.cpp"
using namespace std;

int main()
{
    GraphList<char, double> GL;
    MinSpanTree<char, double>MSTk;
    MinSpanTree<char, double>MSTp;
//    cin>>GL;
//    cout<<GL;
    char x='A';
    cout<<"插入A、B、C、D"<<endl;
    GL.InsertVertex(x);
    x='B';
    GL.InsertVertex(x);
    x='C';
    GL.InsertVertex(x);
    x='D';
    GL.InsertVertex(x);
    cout<<"插入A-B边权值为5.2，插入A-D边权值为3"<<endl;
    x='E';
    GL.InsertVertex(x);
    x='F';
    GL.InsertVertex(x);
    x='G';
    GL.InsertVertex(x);
    x='H';
    GL.InsertVertex(x);
    x='I';
    GL.InsertVertex(x);
    GL.InsertEdge(0,1,5.2);
    GL.InsertEdge(0,2,3);
    GL.InsertEdge(0,3,5);
    GL.InsertEdge(1,4,7);
    GL.InsertEdge(4,6,8);
    GL.InsertEdge(1,2,1);
    GL.InsertEdge(3,5,2);
    GL.InsertEdge(2,5,5.3);
    GL.InsertEdge(5,7,9);
    GL.InsertEdge(7,8,6);
    cout<<"A-B:"<<GL.getWeight(0,1)<<endl;
    cout<<"D-A:"<<GL.getWeight(3,0)<<endl;
    cout<<"顶点数量"<<GL.NumberOfVertex()<<endl;
    cout<<"边的数量"<<GL.NumberOfEdge()<<endl;
    cout<<"A的度数"<<GL.DegOfVertex(0)<<endl;
    cout<<"深度优先遍历："<<endl;
    x='A';
    GL.DFS(GL,x);
    cout<<"\n广度优先遍历："<<endl;
    GL.BFS(GL,x);
    cout<<"\nKruskal最小生成树："<<endl;
    Kruskal(GL,MSTk);
    MSTk.Dispaly(MSTk);
    cout<<"\nPrim最小生成树："<<endl;
    Prim(GL,'A',MSTp);
    MSTp.Dispaly(MSTp);
    return 0;
}
