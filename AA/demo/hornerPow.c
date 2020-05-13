//霍纳法则从左至右求x的幂
#include <stdio.h>
int binary(int n, int arr[])
{
    int i = 0;
    while (n)
    {
        arr[i++] = n % 2;
        n = n >> 1;
    }
    return i;
}
int power(int x, int n)
{
    int arr[1000];
    int len = binary(n, arr); //二进制 低->高
    int r = x;
    for (int i = len - 2; i >= 0; i--)
    {
        r *= r;
        if (arr[i])
            r *= x;
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