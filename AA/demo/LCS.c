#include <stdio.h>
#include <string.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int main()
{
    char *a = "advantage";
    char *b = "didactical";
    int n = strlen(a);
    int m = strlen(b);
    int A[101][101] = {0};
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
                A[i][j] = A[i - 1][j - 1] + 1;
            else
                A[i][j] = MAX(A[i - 1][j], A[i][j - 1]);
        }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
            printf("%d ", A[i][j]);
        putchar('\n');
    }
    return 0;
}