typedef int ElemType;
//交换 测试
void swap(ElemType *x, ElemType *y)
{
    ElemType t;
    t = *x;
    *x = *y;
    *y = t;
}
//插入排序
void insertionSort(int A[], int N)
{
    int j, i;

    int Tmp;
    for (i = 1; i < N; i++)
    {
        Tmp = A[i];
        for (j = i; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
    }
}