#include <stdio.h>
#include <math.h>
int x[100];
int place(int k)
{
    int i = 0;
    while (i < k)
    {
        if (x[i] == x[k] || fabs(i - k) == fabs(x[i] - x[k]))
            return 0;
        i++;
    }
    return 1;
}
void nQueen(int n)
{
    x[0] = 0; //为了与 * 保持一致
    int k = 0;
    while (k >= 0)
    {
        x[k] = x[k] + 1; //此语句在回溯到 k-1 和找到一个解后有大用处  *
        while (x[k] <= n && !place(k))
            x[k] = x[k] + 1;
        if (x[k] <= n)
        {
            if (k == n - 1)
            {
                for (int i = 0; i < n; i++)
                    printf("%3d", x[i]);
                putchar('\n');
            }
            else
            {
                k = k + 1;
                x[k] = 0;  //为了与 * 保持一致
            }
        }
        else
            k = k - 1;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    nQueen(n);
    return 0;
}