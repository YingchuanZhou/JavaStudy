#ifndef MINHEAP_H
#define MINHEAP_H
#define DefaultSize 100
template <typename T>
class MinHeap
{
private:
    T *heap;//С�ֶ�
    int maxSize;//��󴢴�
    int currentSize;//��ǰ����
    void ShiftDown(int start,int end);//��star->end��������С��
    void ShiftUp(int postion);//��postion->0�����ϵ�����Ϊ��С��
public:
    MinHeap(int n=DefaultSize);//������С��
    MinHeap(T arr[],int n);//�����鹹����С��
    ~MinHeap();//������С��
    bool IsEmpty();//�п�
    bool IsFull();//����
    bool Insert(T &n);//����С���в���Ԫ��
    bool RemoveMin(T &n);//����С�����Ƴ���С�ģ��������ȼ���ߵ�
    void print();//�����С��
};
#endif // MINHEAP_H
