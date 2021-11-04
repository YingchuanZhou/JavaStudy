#ifndef MINHEAP_H
#define MINHEAP_H
#define DefaultSize 100
template <typename T>
class MinHeap
{
private:
    T *heap;//小分堆
    int maxSize;//最大储存
    int currentSize;//当前储存
    void ShiftDown(int start,int end);//从star->end调整成最小堆
    void ShiftUp(int postion);//从postion->0下往上调整成为最小堆
public:
    MinHeap(int n=DefaultSize);//构造最小堆
    MinHeap(T arr[],int n);//用数组构造最小堆
    ~MinHeap();//析构最小堆
    bool IsEmpty();//判空
    bool IsFull();//判满
    bool Insert(T &n);//在最小堆中插入元素
    bool RemoveMin(T &n);//在最小堆中移出最小的，即是优先级最高的
    void print();//输出最小堆
};
#endif // MINHEAP_H
