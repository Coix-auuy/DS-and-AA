#include <stdio.h>
#include <stdlib.h>
void Swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void InsertionSort(int A[], int N)
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

void QuickSort(int a[], int low, int high)
{
    if (low + 15 <= high)
    {
        int t = rand() % (high - low + 1) + low;
        // printf("%d ", t);
        // putchar('\n');
        int pivot = a[t];
        Swap(&a[high], &a[t]);
        int i = low;
        int j = high - 1;
        while (i < j)
        {
            while (a[i] < pivot)
            {
                i++;
            }
            // printf("%d ", i);
            while (a[j] > pivot)
            {
                j--;
            }
            // printf("%d", j);
            // putchar('\n');
            Swap(&a[i], &a[j]);
        }
        Swap(&a[i], &a[j]);
        Swap(&a[i], &a[high]);

        // for (int k = 0; k < n - 1; k++)
        //     printf("%d ", a[k]);
        // printf("%d\n", a[n - 1]);
        QuickSort(a, low, i - 1);
        QuickSort(a, i + 1, high);
    }
    else
        InsertionSort(a + low, high - low + 1);
}

// int a[100005];
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &a[i]);

//     QuickSort(a, 0, n - 1);
//     for (int i = 0; i < n - 1; i++)
//         printf("%d ", a[i]);
//     printf("%d\n", a[n - 1]);
//     return 0;
// }
int A[100005];
int main()
{
    int n;
    FILE *in = fopen("in.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (in == NULL || out == NULL)
    {
        return 0;
    }
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(in, "%d", &A[i]);

    QuickSort(A, 0, n - 1);

    for (int i = 0; i < n - 1; i++)
        fprintf(out, "%d ", A[i]);
    fprintf(out, "%d\n", A[n - 1]);
    fclose(in);
    fclose(out);
    return 0;
}