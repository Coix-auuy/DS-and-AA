// 有向图的传递闭包

#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
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
                r[i][j] = (r[i][j] || (r[i][k] && r[k][j]));
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
    int a[SIZE][SIZE] = {{0, 0, 1, 0}, {1, 0, 0, 1}, {0, 0, 0, 0}, {0, 1, 0, 0}};
    warshall(a);
    return 0;
}