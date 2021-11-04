#ifndef SEQLIST_H
#define SEQLIST_H
const int defaultsize = 100;
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
    int Search(T& x) const;//搜索x
    T& Get(int i);//得到i的对象
    bool Push_back(const T& x);//在尾部插入
    bool Insert(int i, const T& x);//在指定位置插入
    bool Remove(T& x);//删除指定元素
    bool RemovePos(int pos);//删除指定位置元素
    void Display(int begin, int end);//显示整个表
    bool SaveFile(const char FileName[]);//保存文件
    bool ReadFile(const char FileName[]);//读取文件
    int Getnum();//获取表中的元素个数
    bool BinSearch(T &x);//二叉搜索
    void Sort();//排序
};

#endif // SEQLIST_H
