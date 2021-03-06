#include <stdio.h>
void power(long long int a[], int n)
{
    if (n == 0)
        return;
    if (n == 1)
        return;
    long long int temp[4];
    if (n == 2)
    {
        temp[0] = a[0] * 1 + a[1] * 1;
        temp[1] = a[0] * 1;
        temp[2] = a[2] * 1 + a[3] * 1;
        temp[3] = a[2] * 1;
        for (int i = 0; i < 4; i++)
            a[i] = temp[i];
        return;
    }
    power(a, n >> 1);
    if (n & 1)
    {
        temp[0] = a[0] * a[0] + a[1] * a[2];
        temp[1] = a[0] * a[1] + a[1] * a[3];
        temp[2] = a[2] * a[0] + a[3] * a[2];
        temp[3] = a[2] * a[1] + a[3] * a[3];
        a[0] = temp[0] * 1 + temp[1] * 1;
        a[1] = temp[0] * 1;
        a[2] = temp[2] * 1 + temp[3] * 1;
        a[3] = temp[2] * 1;
        return;
    }
    else
    {
        temp[0] = a[0] * a[0] + a[1] * a[2];
        temp[1] = a[0] * a[1] + a[1] * a[3];
        temp[2] = a[2] * a[0] + a[3] * a[2];
        temp[3] = a[2] * a[1] + a[3] * a[3];
        for (int i = 0; i < 4; i++)
            a[i] = temp[i];
    }
}
int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        if(n == 0)
        {
            printf("0\n");
            continue;
        }
            
        long long int a[4] = {1, 1, 1, 0};
        power(a, n);
        printf("%lld\n", a[1]);
    }
    return 0;
}