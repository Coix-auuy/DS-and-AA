#include <stdio.h>
#include <math.h>
int main()
{
    int n; //样本容量
    scanf("%d", &n);
    double a[10000]; //一组样本
    double sum = 0;
    for (int i = 0; i < n; i++)
        scanf("%lf", &a[i]), sum += a[i];
    double ave = sum / n; //样本均值

    double var = 0; //样本方差
    for (int i = 0; i < n; i++)
        var += pow(a[i] - ave, 2) / (n - 1);

    printf("%lf   %lf\n", ave, var);
    return 0;
}