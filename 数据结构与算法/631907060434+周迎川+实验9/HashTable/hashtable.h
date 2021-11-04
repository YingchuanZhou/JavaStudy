#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using namespace std;
#define DefaultSize 10
template <typename T>
struct ChainNode
{
    T data;
    string name;
    string address;
    ChainNode<T> *next;
    ChainNode(T e,string n,string a)
    {
        data=e;name=n;address=a;next=nullptr;
    }
    ChainNode()
    {
        next=nullptr;
    }
};
template <typename T>
class HashTable
{
private:
    ChainNode<T> **head;//散列表的头指针数组
    ChainNode<T> *FindPos(T elem);//查找元素的的头指针位置
    int TableSize;//散列表的大小
    int divisor;//除数
public:
    HashTable(long long  d, int size=DefaultSize);//构造函数
    ~HashTable()//析构函数
    {
        delete [] head;
    }
    bool Search(T elem);//查询元素
    bool Insert(T elem,string n,string a);//插入元素
    bool Remove(T elem);//删除元素
    void Display();//显示所有元素
};
#endif // HASHTABLE_H
