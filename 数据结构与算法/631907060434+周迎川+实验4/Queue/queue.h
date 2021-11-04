#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
class Queue
{
public:
    Queue(){}//构造
    ~Queue(){}//析构
    virtual void EnQueue(T &x)=0;//入队
    virtual bool DeQueue(T &x)=0;//出队
    virtual bool getFront(T &x)=0;//获取队头元素
    virtual bool IsEmpty()=0;//判空
    virtual int getSize()=0;//获取队列长度
};
template <typename T>
struct ListNode
{
    T data;
    ListNode<T> *next;
    ListNode()
    {
        next=nullptr;
    }
    ListNode(T &x)
    {
        data=x;
        next=nullptr;
    }
};

template <typename T>
class ListQueue : public Queue<T>
{
private:
    ListNode<T> *front,*last;
public:
    ListQueue();
    ~ListQueue();
    void EnQueue(T &x);
    bool DeQueue(T &x);
    bool getFront(T &x);
    bool IsEmpty();
    int getSize();
    bool makeEmpty();
    ListNode<T> *returnFront();
};
#endif // QUEUE_H
