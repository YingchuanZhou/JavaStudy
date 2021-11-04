
#include <iostream>
#define DefaultNum 50
class UFSets
{
private:
    int *parents;//存放集合父元素
    //int num;//集合元素个数
public:
    UFSets(int size=DefaultNum);//构造函数
    ~UFSets();//析构函数
    int Find(int x);//搜索x的父元素
    void Union(int root1, int root2);//将root2集合和并到root1
    //void WeightUnion(int root1, int root2);//带权值的root2合并到root1
    //int CollapsingFind(int x);//压缩的搜索x的父元素
};
UFSets::UFSets(int size)
{
    parents = new int[size];
    for(int i=0; i<size; i++)
        parents[i]=-1;//每个元素都父元素
}
UFSets::~UFSets()
{
    delete [] parents;
}
int UFSets::Find(int x)
{
    while(parents[x]>-1)
        x=parents[x];
    return x;
    /*
     * if(parents[x]<0)
     * return x;
     * else
     * return Find(parents[x]);
     */
}
void UFSets::Union(int root1, int root2)
{
    parents[root1]+=parents[root2];
    parents[root2]=root1;
}
