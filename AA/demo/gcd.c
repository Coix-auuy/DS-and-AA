#include <stdio.h>
int gcd(int m, int n, int *x, int *y)
{

    if (!n)
    {
        *x = 1;
        *y = 0;
        return m;
    }
    int r = gcd(n, m % n, x, y);

    int t = *x;
    *x = *y;
    *y = t - (m / n) * (*y);
    return r;
}
int main()
{
    int x = 0, y = 0;
    printf("%d\n", gcd(10, 4, &x, &y));
    printf("%d %d\n", x, y);
    return 0;
}