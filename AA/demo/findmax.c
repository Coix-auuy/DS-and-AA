#include <stdio.h>
typedef int ElemType;
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
ElemType FindMax(ElemType A[], int Left, int Right, int N)
{
    if (N == 1)
        return A[Left];
    int Center = (Left + Right) / 2;
    return MAX(FindMax(A, Left, Center, Center - Left + 1), FindMax(A, Center + 1, Right, Right - Center));
}

int main()
{
    int a[6] = {6, 3, 7, 0, 9, 1};
    printf("%d", FindMax(a, 0, 5, 6));
}