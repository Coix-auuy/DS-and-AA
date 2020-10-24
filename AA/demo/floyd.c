// 任意两点最短路径
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
#define INF 10000
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int path[SIZE][SIZE];
void floyd(int (*map)[SIZE])
{
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (i == k)
                continue;
            for (int j = 0; j < SIZE; j++)
            {
                if (map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    // for (int i = 0; i < SIZE; i++)
    // {
    //     for (int j = 0; j < SIZE; j++)
    //         printf("%d ", r[i][j]);
    //     putchar('\n');
    // }
}
int main()
{
    int map[SIZE][SIZE] = {{0, INF, 3, INF}, {2, 0, INF, INF}, {INF, 7, 0, 1}, {6, INF, INF, 0}};
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            path[i][j] = j;
    floyd(map);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(i == j)
                continue;
            printf("%c->%c:  ", i + 'a', j + 'a');
            int start = i;
            int e = j;
            while (start != e)
            {
                printf("%c ", start + 'a');
                start = path[start][e];
            }
            printf("%c %d\n", start + 'a',map[i][j]);
        }
    }
    return 0;
}