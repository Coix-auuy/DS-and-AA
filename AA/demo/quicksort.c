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
// 当所需排序数在5~20时插入排序更高效,这也可以避免数组小于3时出现的运行错误.
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
// Return median of Left, Right and Center
// Order these and hide the pivot
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

#define Cutoff (15) //Avoid error
void Qsort(ElemType A[], int Left, int Right)
{

    if (Left + Cutoff <= Right)
    {
        int i, j;
        ElemType Pivot;
        Pivot = Median3(A, Left, Right);
        i = Left;
        j = Right - 1;
        for (;;)
        {
            while (A[++i] < Pivot)
            {
            }
            while (A[--j] > Pivot)
            {
            }
            if (i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        Swap(&A[i], &A[Right - 1]); //Restore pivot

        Qsort(A, Left, i - 1);
        Qsort(A, i + 1, Right);
    }
    else
        InsertionSort(A + Left, Right - Left + 1);
}

void Quicksort(ElemType A[], long long int N)

{
    Qsort(A, 0, N - 1);
}

ElemType A[1000000];
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    Quicksort(A, N);
    for (int i = 0; i < N - 1; i++)
        printf("%d ", A[i]);
    printf("%d\n", A[N - 1]);
    return 0;
}
// int main()
// {
//     int n;
//     FILE *in = fopen("in.txt", "r");
//     FILE *out = fopen("output.txt", "w");

//     if (in == NULL || out == NULL)
//     {
//         return 0;
//     }
//     fscanf(in, "%d", &n);
//     for (int i = 0; i < n; i++)
//         fscanf(in, "%d", &A[i]);

//     Quicksort(A, n);

//     for (int i = 0; i < n - 1; i++)
//         fprintf(out, "%d ", A[i]);
//     fprintf(out, "%d\n", A[n - 1]);
//     fclose(in);
//     fclose(out);
//     return 0;
// }
