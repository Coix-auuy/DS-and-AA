#include <iostream>
#include <time.h>
using namespace std;
void fExchange(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}
int fPartition(int A[], int p, int r)
{
	srand(unsigned(time(0))); //选种子seed

	int ran1 = (rand() % (r - p + 1)) + p; //产生[p,r]范围的随机数,取三个随机数的中间数
	int ran2 = (rand() % (r - p + 1)) + p;
	int ran3 = (rand() % (r - p + 1)) + p;
	int ran;

	if (A[ran1] >= A[ran2] && A[ran1] <= A[ran3])
		ran = ran1;
	else if (A[ran2] >= A[ran1] && A[ran2] <= A[ran3])
		ran = ran2;
	else
		ran = ran3;

	int x = A[ran];
	fExchange(A[ran], A[r]); //将随机选出的数与A[r]交换
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			fExchange(A[i], A[j]);
		}
	}
	fExchange(A[i + 1], A[r]); //将x放在数组中的顺序位置
	return i + 1;
}
void fQuickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = fPartition(A, p, r);
		fQuickSort(A, p, q - 1);
		fQuickSort(A, q + 1, r);
	}
}

int main()
{
	int A[12] = {55, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	fQuickSort(A, 0, 11);
	for (int i = 0; i < 12; i++)
		printf("%d ", A[i]);
	return 0;
}