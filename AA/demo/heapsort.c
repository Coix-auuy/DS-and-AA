#include <stdio.h>
#include "common.c"
typedef int ElemType;
#define LCHILD(i) (2 * (i) + 1)
void sift(ElemType a[], int i, int n)
{
    int child;
    ElemType temp;

    for (temp = a[i]; LCHILD(i) < n; i = child)
    {
        child = LCHILD(i);
        if (child != n - 1 && a[child + 1] > a[child])
            child++;
        if (temp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = temp;
}

void heapSort(ElemType a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        sift(a, i, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        sift(a, 0, i);
    }
}

int main()
{
    int n;
    ElemType a[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    heapSort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
    return 0;
}