#include "const.cpp"
typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;
Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    return OK;
}
Status EnQueue(LinkQueue &Q, QElemType e)
{
    QNode *p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.rear == Q.front)
        return ERROR;
    QNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    return OK;
}
QElemType GetHead(LinkQueue Q)
{
    if (Q.rear != Q.front)
        return Q.front->next->data;
    return ERROR;
}
int main(int argc, char const *argv[])
{
    LinkQueue Q;
    InitQueue(Q);
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
    for (int i = 0; i < 10; i++)
        EnQueue(Q, i);
    cout<<GetHead(Q)<<endl;
    for (int i = 0; i < 10; i++)
    {
        DeQueue(Q,e);
        cout<<e<<' ';
    }
    cout<<endl;
    return 0;
}
