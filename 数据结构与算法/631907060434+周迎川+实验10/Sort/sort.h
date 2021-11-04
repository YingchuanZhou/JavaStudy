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
    void resetsize(int newsize =2*defaultsize);//ÿ����չΪԭ��������
public:
    SeqList(int size= defaultsize);//���캯��
    ~SeqList();//��������
    int Length() const;//���㳤��
    bool IsFull() const;//����
    bool IsEmpty() const;//�п�
    bool Push_back(const T x);//��β������
    T &operator[](int i)
    {
        return data[i];
    }
    void Display();//��ʾ
};
#endif // SORT_H
