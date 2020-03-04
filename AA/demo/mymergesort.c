#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

void merge(ElemType A[], int Lpos, int Rpos, int Rightend)
{
    int N = Rightend - Lpos + 1;
    ElemType *B = malloc(6 * sizeof(ElemType));
    int Leftend = Rpos - 1;
    int Bpos = Lpos;
    while(Lpos <= Leftend && Rpos <= Rightend)
        if(A[Lpos] < A[Rpos])
            B[Bpos++] = A[Lpos++];
        else
            B[Bpos++] = A[Rpos++];
    while(Lpos <= Leftend)
        B[Bpos++] = A[Lpos++];
    while(Rpos <= Rightend)
        B[Bpos++] = A[Rpos++];
    for(int i = 0; i < N; i++, Rightend--)
        A[Rightend] = B[Rightend];

}

void sort(ElemType A[], int Left, int Right)
{
    if(Left < Right){
        int Center = (Left + Right) / 2;
        sort(A, Left, Center);
        sort(A, Center + 1, Right);
        merge(A, Left, Center + 1, Right);
    }
    
}

int main()
{
    int a[6] = {1,7,3,0,5,4};
    sort(a, 0, 5);
    for(int i = 0; i < 6; i++)
        printf("%d ", a[i]);
    return 0;
}