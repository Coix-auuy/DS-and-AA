#include <stdio.h>
typedef int ElemType;
int x_power(ElemType x, int n)
{
    if (n == 1)
        return x;
    ElemType temp = x_power(x, n >> 1);
    if (n & 1)
        return temp * temp * x;
    else
        return temp * temp;
}
int main()
{
    ElemType x;
    int n;
    scanf("%d%d", &x, &n);
    printf("%d", x_power(x, n));
    return 0;
}