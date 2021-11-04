#ifndef SORT_H
#define SORT_H
#define defaultsize 100
template <typename T>
class SeqList
{
private:
    T *data;
    int maxsize;
    int num;
    void resetsize(int newsize =2*defaultsize);//每次扩展为原来的两倍
public:
    SeqList(int size= defaultsize);//构造函数
    ~SeqList();//析构函数
    int Length() const;//计算长度
    bool IsFull() const;//判满
    bool IsEmpty() const;//判空
    bool Push_back(const T x);//在尾部插入
    T &operator[](int i)
    {
        return data[i];
    }
    void Display();//显示
};
#endif // SORT_H
