//从右至左求x的幂
#include <stdio.h>
int power(int x, int n)
{
    int r = 1;
    while (n)
    {
        if (n % 2)
            r *= x;
        n = n >> 1;
        x *= x;
    }
    return r;
}
int main()
{
    int x;
    scanf("%d", &x);
    int n;
    scanf("%d", &n);
    printf("%d\n", power(x, n));
    return 0;
}