#include "const.cpp"
#define MAXQSIZE 100
typedef int QElemType;
typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQueue;
Status InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXQSIZE];
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}
int QueueLengh(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}
Status DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.rear == Q.front)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}
QElemType GetHead(SqQueue Q)
{
    if(Q.rear != Q.front)
        return Q.base[Q.front];
    return ERROR;
}
int main(int argc, char const *argv[])
{
    SqQueue Q;

    if (InitQueue(Q))
        cout << "Init Success!" << endl;
    for (int i = 0; i < 10; i++)
        EnQueue(Q, i);
    QElemType e;
    cout<<GetHead(Q)<<endl;
    for (int i = 0; i < 10; i++)
    {
        DeQueue(Q,e);
        cout<<e<<' ';
    }
    cout<<endl;
    
    return 0;
}
