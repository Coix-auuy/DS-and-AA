#include "Graph.h"
int visited[MAXV];
void DFS(AdjGraph *G, int v)
{
	ArcNode *p;
	printf("%d", v);
	visited[v] = 1;
	p = G->adjlist[v].firstarc;
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

void visitedIsZore()
{
	for (int i = 0; i < MAXV; i++)
		visited[i] = 0;
}

void DFS_stack(AdjGraph *G, int v)
{
	ArcNode *p;
	int St[MAXV];
	int top = -1;
	for (int i = 0; i < G->n; i++)
		visited[i] = 0;
	printf("%3d", v);
	visited[v] = 1;
	top++;
	St[top] = v;
	while (top > -1)
	{
		p = G->adjlist[St[top]].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%3d", p->adjvex);
				visited[p->adjvex] = 1;
				top++;
				St[top] = p->adjvex;
				break;
			}
			p = p->nextarc;
		}
		if (p == NULL)
			top--;
	}
	printf("\n");
}

void BFS(AdjGraph *G, int v)
{
	ArcNode *p;
	int queue[MAXV], front = 0, rear = 0;
	int visited[MAXV];
	for (int i = 0; i < G->n; i++)
		visited[i] = 0;
	printf("%3d", v);
	rear = (rear + 1) % MAXV;
	queue[rear] = v;
	while (front != rear)
	{
		front = (front + 1) % MAXV;
		// w = queue[front];
		p = G->adjlist[queue[front]].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%3d", p->adjvex);
				visited[p->adjvex] = 1;
				rear = (rear + 1) % MAXV;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}
