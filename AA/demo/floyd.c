// 任意两点最短路径

#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
#define INF 10000
#define MIN(x,y) ((x)<(y)?(x):(y))
void warshall(int (*a)[SIZE])
{
    int r[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            r[i][j] = a[i][j];
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (i == k)
                continue;
            for (int j = 0; j < SIZE; j++)
                r[i][j] = MIN(r[i][j],r[i][k] + r[k][j]);
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", r[i][j]);
        putchar('\n');
    }
}
int main()
{
    int n = 4;
    int a[SIZE][SIZE] = {{0, INF, 3, INF}, {2, 0, INF, 1}, {INF, 7, 0, 1}, {6, INF, INF, 0}};
    warshall(a);
    return 0;
}