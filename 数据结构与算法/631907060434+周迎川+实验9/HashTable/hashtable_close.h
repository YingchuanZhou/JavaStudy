#ifndef HASHTABLE_CLOSE_H
#define HASHTABLE_CLOSE_H
#define Defaultsize 100
#include <string>
using namespace std;
enum status{Active,Deleted,Empty};
template <typename T>
struct Node
{
    T data;
    string name;
    string address;
    bool operator==(Node<T> &n)
    {
        if(data==n.data)
            return true;
        else
            return false;
    }
};
template <typename T>
class HashTable_C
{
private:
    long long divisor;//除数
    Node<T> *ht;//散列表数组
    status *info;//状态信息
    int tablesize;//散列表大小
    int cursize;//当前大小
    int FindPos(T elem);//找到位置信息
    bool operator==(T elem);//判断相等
    bool operator!=(T elem);//判断不相等
public:
    HashTable_C(long long d,int size=Defaultsize);//构造函数
    ~HashTable_C()
    {
        delete [] ht;delete [] info;
    }
    bool Insert(T elem,string n,string a);//增加
    bool Remove(T elem);//删除
    bool Search(T elem);//查找
    void Display();//显示
};
#endif // HASHTABLE_CLOSE_H
