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
    cout<<"����A��B��C��D"<<endl;
    GL.InsertVertex(x);
    x='B';
    GL.InsertVertex(x);
    x='C';
    GL.InsertVertex(x);
    x='D';
    GL.InsertVertex(x);
    cout<<"����A-B��ȨֵΪ5.2������A-D��ȨֵΪ3"<<endl;
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
    cout<<"��������"<<GL.NumberOfVertex()<<endl;
    cout<<"�ߵ�����"<<GL.NumberOfEdge()<<endl;
    cout<<"A�Ķ���"<<GL.DegOfVertex(0)<<endl;
    cout<<"������ȱ�����"<<endl;
    x='A';
    GL.DFS(GL,x);
    cout<<"\n������ȱ�����"<<endl;
    GL.BFS(GL,x);
    cout<<"\nKruskal��С��������"<<endl;
    Kruskal(GL,MSTk);
    MSTk.Dispaly(MSTk);
    cout<<"\nPrim��С��������"<<endl;
    Prim(GL,'A',MSTp);
    MSTp.Dispaly(MSTp);
    return 0;
}
