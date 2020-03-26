#include <stdio.h>
typedef int ElemType;
void Swap(ElemType *x, ElemType *y)
{
    ElemType t;
    t = *x;
    *x = *y;
    *y = t;
    // (*x) ^= (*y) ^= (*x) = (*y);
    //异或交换用不了 还未找出原因
}
void InsertionSort(ElemType A[], int N)
{
    int j, i;

    ElemType Tmp;
    for (i = 1; i < N; i++)
    {
        Tmp = A[i];
        for (j = i; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
    }
}
ElemType Median3(ElemType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    if (A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if (A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if (A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);
    //A[left] <= A[Center] <= A[Right]
    Swap(&A[Center], &A[Right - 1]); //Hide pivot
    return A[Right - 1];             //Return pivot
}
void quickSelect(ElemType a[], int k, int left, int right)
{
    if (right - left + 1 > 2)
    {
        int i, j;
        ElemType pivot = Median3(a, left, right);
        i = left;
        j = right - 1;
        while (1)
        {
            while (a[++i] < pivot)
            {
            };
            while (a[--j] > pivot)
            {
            };
            if (i < j)
                Swap(&a[i], &a[j]);
            else
                break;
        }
        Swap(&a[i], &a[right - 1]);
        // for (int i = 0; i < 6; i++)
        //     printf("%d", a[i]);
        // printf("\n");
        if (k < i)
            quickSelect(a, k, left, i - 1);
        else if (k > i)
            quickSelect(a, k, i + 1, right);
        else
            return;
    }
    else
        InsertionSort(a + left, right - left + 1);
}
int main()
{
    ElemType a[10];
    int k;
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);
    quickSelect(a, k - 1, 0, 9);
    printf("%d", a[k - 1]);
}