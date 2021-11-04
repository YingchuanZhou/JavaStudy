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
    void resetsize(int newsize =2*defaultsize);//ÿ����չΪԭ��������
public:
    SeqList(int size= defaultsize);//���캯��
    ~SeqList();//��������
    int Length() const;//���㳤��
    bool IsFull() const;//����
    bool IsEmpty() const;//�п�
    int Search(T& x) const;//����x
    T& Get(int i);//�õ�i�Ķ���
    bool Push_back(const T& x);//��β������
    bool Insert(int i, const T& x);//��ָ��λ�ò���
    bool Remove(T& x);//ɾ��ָ��Ԫ��
    bool RemovePos(int pos);//ɾ��ָ��λ��Ԫ��
    void Display(int begin, int end);//��ʾ������
    bool SaveFile(const char FileName[]);//�����ļ�
    bool ReadFile(const char FileName[]);//��ȡ�ļ�
    int Getnum();//��ȡ���е�Ԫ�ظ���
    bool BinSearch(T &x);//��������
    void Sort();//����
};

#endif // SEQLIST_H
