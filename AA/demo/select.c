#include <stdio.h>
typedef int ElemType;
#define MAX 100
void Swap(ElemType *x, ElemType *y)
{
    ElemType t;
    t = *x;
    *x = *y;
    *y = t;
    // (*x) ^= (*y) ^= (*x) = (*y);
    //异或交换用不了 还未找出原因
}
int partion(ElemType a[], int l, int r)
{
    int i = l + 1;
    int j = r;
    while (1)
    {
        while (a[j] > a[l] && i < j)
            j--;
        while (a[i] < a[l] && i < j)
            i++;
        if (i < j)
            Swap(&a[i], &a[j]);
        else
            break;
    }
    Swap(&a[l], &a[j]);
    return j;
}
ElemType select(ElemType a[], int k, int l, int r)
{
    int i;
    while (l <= r)
    {
        i = partion(a, l, r);
        // for (int j = l; j <= r; j++)
        //     printf("%d ", a[j]);
        // printf("%d", i);
        // putchar('\n');
        if (i < k - 1)
            l = i + 1;
        else if (i > k - 1)
            r = i - 1;
        else
            return a[k - 1];
        // printf("%d   %d  %d\n", i, l, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int k;
    scanf("%d", &k);
    printf("%d", select(a, k, 0, n - 1));
    return 0;
}