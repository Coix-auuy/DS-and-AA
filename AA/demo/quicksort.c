#include <stdio.h>
typedef int ElemType;
// #define Swap(ElemType (*x), ElemType *y) ()
void Swap(ElemType *x, ElemType *y)
{
    ElemType t;
    t = *x;
    *x = *y;
    *y = t;
}

void InsertionSort(ElemType A[], int N)
{
    int j, P;

    ElemType Tmp;
    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--)
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

#define Cutoff (3) //Avoid error
void Qsort(ElemType A[], int Left, int Right)
{
    int i, j;
    ElemType Pivot;

    if (Left + Cutoff <= Right)
    {
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

void Quicksort(ElemType A[], int N)
{
    Qsort(A, 0, N - 1);
}

int main()
{
    ElemType A[6] = {6, 3, 9, 2, 0, 7};
    Quicksort(A, 6);
    for (int i = 0; i < 6; i++)
        printf("%d", A[i]);
}
