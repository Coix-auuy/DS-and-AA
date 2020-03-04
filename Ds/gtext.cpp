#include"travsal.h"
int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV] = {{0,1,4,INF,INF,INF},{1,0,2,7,5,INF},{4,2,0,INF,1,INF},{INF,7,INF,0,3,2},{INF,5,1,3,0,6},{INF,INF,INF,2,6,0}};
	// int A[MAXV][MAXV] = {{0,1,4,-1,-1,-1},{1,0,2,7,5,-1},{4,2,0,-1,1,-1},{-1,7,-1,0,3,2},{-1,5,1,3,0,6},{-1,-1,-1,2,6,0}};
	int n = 6, e = 9;
	CreateAdj(G, A, n, e);
	DispAdj(G);
//	DFS(G,1);
//	printf("\n\n");
	DFS_stack(G, 1);
	BFS(G, 1);
	DestroyAdj(G);
	return 0;
	
}
