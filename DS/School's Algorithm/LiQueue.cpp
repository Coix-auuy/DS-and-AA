#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DataNode
{
	ElemType data;
	struct DataNode *next;
} DataNode;
typedef struct
{
	DataNode *front;
	DataNode *rear;
} LinkQuNode;
void InitQueue(LinkQuNode *&q)
{
	q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
void DestroyQueue(LinkQuNode *&q)
{
	DataNode *p = q->front, *r;
	if (p != NULL)
	{
		r = p->next;
		while (r != NULL)
		{
			free(p);
			p = r;
			r = r->next;
		}
	}
	free(p);
	free(q);
}
bool QueueEmpty(LinkQuNode *q)
{
	return q->rear == NULL;
}
void enQueue(LinkQuNode *&q, ElemType e)
{
	DataNode *p = (DataNode *)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
	{
		q->front = p;
		q->rear = p;
	}
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}
bool deQueue(LinkQuNode *&q, ElemType &e)
{
	if (q->rear == NULL)
		return false;
	DataNode *t;
	t = q->front;
	e = t->data;
	if (q->rear == q->front)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	free(t);
	return true;
}
