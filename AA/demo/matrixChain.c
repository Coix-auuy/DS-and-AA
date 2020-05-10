#include <stdio.h>
void matrixChain(int p[], int n)
{
    int m[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    int s[n + 1][n + 1];
    for (int r = 2; r <= n; r++) //r为链长
    {
        for (int i = 1; i <= n - r + 1; i++) //i为左边界
        {
            int j = i + r - 1;                              //j为右边界
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j]; //k = i的划分
            s[i][j] = i;                                    //记录k
            for (int k = i + 1; k <= j - 1; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         printf("%6d ", m[i][j]);
    //     putchar('\n');
    // }
    printf("%d\n", m[1][n]);
}
int main()
{
    int n;
    scanf("%d", &n); //n为矩阵个数
    int p[n + 1];    //p为矩阵链 第i个矩阵的行数和列数分别为p[i - 1], p[i]
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    matrixChain(p, n);
    return 0;
}