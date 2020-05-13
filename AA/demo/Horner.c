#include <stdio.h>
int main()
{
    int n; //最高次幂
    scanf("%d", &n);
    int arr[10]; //系数数组 低次幂->高次幂
    for (int i = 0; i <= n; i++)
        scanf("%d", &arr[i]);
    int x = 2; //未知数值
    // scanf("%d", &x);
    int r = arr[n];
    for (int i = n - 1; i >= 0; i--)
        r = r * x + arr[i];
    printf("%d", r);
    return 0;
}