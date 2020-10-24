#include <stdio.h>
#include <stdlib.h>
#define INF 100
#define SIZE 100
#define MIN(x, y) ((x) > (y) ? (y) : (x))
//带权矩阵
struct graph
{
    int matrix[SIZE][SIZE];
    int n;
} g;
//一维数组中找最小值返回下标
int min(int a[], int n, int flag[])
{
    int min = INF;
    int index;
    for (int i = 0; i < n; i++)
        if (flag[i] == 0 && min > a[i])
            min = a[i], index = i;
    return index;
}
int main()
{
    scanf("%d", &g.n);
    for (int i = 0; i < g.n; i++)
        for (int j = 0; j < g.n; j++)
            scanf("%d", &g.matrix[i][j]);
    int v; //起始点
    scanf("%d", &v);
    int flag[SIZE]; //标记此点是否被确定
    int dist[SIZE]; //起始点到此点的距离
    //初始化
    for (int i = 0; i < g.n; i++)
    {
        flag[i] = 0;
        dist[i] = g.matrix[v][i];
    }
    flag[v] = 1;
    dist[v] = 0;
    for (int i = 0; i < g.n - 1; i++) //n - 1个点需要确定
    {
        int u = min(dist, g.n, flag); //当前到达起始点距离最短的点
        flag[u] = 1;
        // 更新
        for (int j = 0; j < g.n; j++)
            if (flag[j] == 0)
                dist[j] = MIN(dist[j], dist[u] + g.matrix[u][j]);
    }
    for (int i = 0; i < g.n; i++)
    {
        if (i == v)
            continue;
        printf("%c->%c: %3d\n", v + 'a', i + 'a', dist[i]);
    }

    return 0;
}
