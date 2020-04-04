#include "queue.h"
#include "fatal.h"

#define MinQueueSize (5)

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q;
    if (MaxElements < MinQueueSize)
        Error("Queue sieze is too small");
    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!!");

    Q->Array = malloc(sizeof(ElementType) * MaxElements);

    if (Q->Array == NULL)
        FatalError("Out of space!!!");
    Q->Capacity = MaxElements;

    MakeEmpty(Q);
    return Q;
}
void DisposeQueue(Queue Q)
{
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}
void MakeEmpty(Queue Q)
{
    Q->Front = 1;
    Q->Rear = 0;
    Q->Size = 0;
}
static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}
void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        Error("Full queue");
    Q->Size++;
    Q->Rear = Succ(Q->Rear, Q);
    Q->Array[Q->Rear] = X;
}
ElementType Front(Queue Q)
{
    if (!IsEmpty(Q))
        return Q->Array[Q->Front];
    Error("Empty queue");
    return 0;
}
void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue");
    Q->Size--;
    Q->Front = Succ(Q->Front, Q);
}
ElementType FrontAndDequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue");
    Q->Size--;
    ElementType X = Q->Array[Q->Front];
    Q->Front = Succ(Q->Front, Q);
    return X;
}