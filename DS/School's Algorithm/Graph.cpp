#include <stdio.h>
#include <stdlib.h>
#define INF -1
#define MAXV 100
typedef char InfoType;
//�ڽӾ���
typedef struct
{
	int no; //������
	InfoType info;
} VertexType; //����
typedef struct
{
	int edges[MAXV][MAXV];
	int n, e; //������������
	VertexType vexs[MAXV];
} MatGraph;

void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e)
{
	g.n = n;
	g.e = e;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g.edges[i][j] = A[i][j];
}

void DispMat(MatGraph &g)
{
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			if (g.edges[i][j] != INF)
				printf("%4d", g.edges[i][j]);
			else
				printf("%4s", "��");
		}
		printf("\n");
	}
}

//�ڽӱ�
typedef struct ANode
{
	int adjvex;			   //�ñߵ��ڽӵ���
	struct ANode *nextarc; //��һ����
	int weight;			   //Ȩֵ
} ArcNode;				   //�߽��?
typedef struct Vnode
{
	InfoType info;	   //������Ϣ
	int count;		   //�������?
	ArcNode *firstarc; //��һ����
} VNode;			   //ͷ���?
typedef struct
{
	VNode adjlist[MAXV];
	int n, e;
} AdjGraph;

void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	G->n = n;
	G->e = e;
	for (int i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j >= 0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j; //�ڽӵ��ĵ�
				p->weight = A[i][j];
				//ͷ��
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
}

void DispAdj(AdjGraph *G)
{
	ArcNode *p;
	for (int i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d", i);
		while (p != NULL)
		{
			printf("%3d[%3d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}

void DestroyAdj(AdjGraph *&G)
{
	ArcNode *pre, *p;
	for (int i = 0; i < G->n; i++)
	{
		pre = G->adjlist[i].firstarc;
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}
