#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
// Lpos = left's start, Rpos = right's start, RightEnd = right's end; 后面的变量意思同此处
void Merge(ElemType A[], ElemType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
    int  LeftEnd, numElements, TmpPos;
    
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    numElements = RightEnd - Lpos + 1;//此次合并的数组长度

    while (Lpos <= LeftEnd && Rpos <= RightEnd)
    {
        if(A[Lpos] <= A[Rpos])
            TmpArray[TmpPos++] = A[Lpos++];
        else
            TmpArray[TmpPos++] = A[Rpos++];
    }
    while(Lpos <= LeftEnd)
        TmpArray[TmpPos++] = A[Lpos++];
    while(Rpos <= RightEnd)
        TmpArray[TmpPos++] = A[Rpos++];

    for(int i = 0; i < numElements; i++ ,RightEnd--)//恢复到原数组中
        A[RightEnd] = TmpArray[RightEnd];    

}

void Msort(ElemType A[], ElemType TmpArray[], int Left, int Right)
{
    int Center;
    if(Left < Right)
    {
        //递归分解问题
        {
            Center = (Left + Right) / 2;
            Msort(A, TmpArray, Left, Center);
            Msort(A, TmpArray, Center + 1, Right);
            Merge(A, TmpArray, Left, Center + 1, Right);
        }
    }
}

void Mergesort(ElemType A[], int N)
{
    ElemType *TmpArray = NULL;//用于合并
        TmpArray = malloc(N * sizeof(ElemType));
    if(TmpArray != NULL)
    {
        Msort(A, TmpArray, 0, N - 1);
        for (int i = 0; i < N; i++)
        {
            printf("%d ",A[i]);
        }
        free(TmpArray);
    }
    else
    {
            printf("error");
    }
    
}

int main()
{
    int a[6] = {6,3,7,0,9,1};
    Mergesort(a,6);
    
    return 0;
    
}