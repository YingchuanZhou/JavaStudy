
#include <iostream>
#define DefaultNum 50
class UFSets
{
private:
    int *parents;//��ż��ϸ�Ԫ��
    //int num;//����Ԫ�ظ���
public:
    UFSets(int size=DefaultNum);//���캯��
    ~UFSets();//��������
    int Find(int x);//����x�ĸ�Ԫ��
    void Union(int root1, int root2);//��root2���ϺͲ���root1
    //void WeightUnion(int root1, int root2);//��Ȩֵ��root2�ϲ���root1
    //int CollapsingFind(int x);//ѹ��������x�ĸ�Ԫ��
};
UFSets::UFSets(int size)
{
    parents = new int[size];
    for(int i=0; i<size; i++)
        parents[i]=-1;//ÿ��Ԫ�ض���Ԫ��
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
