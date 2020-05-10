#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
struct item
{
    int w;
    int v;
} item[10];
//二维数组
// int r[10][10];
//     for (int i = 0; i <= pW; i++)
//         r[0][i] = 0;
// for (int i = 1; i <= n; i++)
// {
//     for (int j = 0; j <= pW; j++)
//         if (j - item[i].w >= 0)
//             r[i][j] = MAX(r[i - 1][j], item[i].v + r[i - 1][j - item[i].w]);
//         else
//             r[i][j] = r[i - 1][j];
// }
// for (int i = 0; i <= n; i++)
// {
//     for (int j = 0; j <= pW; j++)
//     {
//         printf("%3d",r[i][j]);
//     }
//     putchar('\n');
// }
//一维数组
// int r[10] = {0};
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = pW; j >= item[i].w; j--)
//             r[j] = MAX(r[j], item[i].v + r[j - item[i].w]);
//         for (int k = 0; k <= pW; k++)
//             printf("%3d", r[k]);
//         putchar('\n');
//     }
int main()
{
    int pW, n;
    scanf("%d%d", &n, &pW); //物品数量，背包容量
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &item[i].w, &item[i].v); //每件物品的重量以及价值
    int r[10];
    r[0] = 0;
    for(int i = 1; i <= pW;i++)
        r[i] = -1000;
    for (int i = 1; i <= n; i++)
    {
        for (int j = pW; j >= item[i].w; j--)
            r[j] = MAX(r[j], item[i].v + r[j - item[i].w]);
        for (int k = 0; k <= pW; k++)
            printf("%5d", r[k]);
        putchar('\n');
    }
    return 0;
}