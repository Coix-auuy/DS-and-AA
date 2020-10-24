#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
struct item
{
    int w;
    int v;
} item[10];

int main()
{
    int pW, n;
    scanf("%d%d", &n, &pW); //物品数量，背包容量
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &item[i].w, &item[i].v); //每件物品的重量以及价值
    int f[100] = {0};
    for(int i = 1; i <= n; i++)
    {
        for(int j = pW; j >= item[i].w; j-- )
        {
            
            f[j] = MAX(f[j], f[j - item[i].w] + item[i].v);
        }
    }
        printf("%d\n",f[pW]);
    return 0;
}