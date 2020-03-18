#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define MAX 200
int arry[MAX], n;
struct Point
{
	double x, y;
} point[MAX];

double dis(int i, int j)
{
	return sqrt((point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y) * (point[i].y - point[j].y));
}

bool comx(Point a, Point b)
{
	return a.x < b.x;
}

bool comy(int a, int b)
{
	return a < b;
}

double min(double m, double n)
{
	return m < n ? m : n;
}

double Mincom(double left, double right)
{
	if (right - left == 1)
		return dis(left, right);
	if (right - left == 2)
		return min(min(dis(right, right - 1), dis(right - 1, left)), dis(right, left));

	int mid = (left + right) / 2;

	double d = min(dis(left, mid), dis(mid + 1, right));
	int i, j, k = 0;
	for (i = left; i <= right; i++)
		if (fabs(point[mid].x - point[i].x) <= d)
			arry[k++] = i;

	sort(arry, arry + k, comy);
	for (i = 0; i < k; i++)
	{
		for (j = i + 1; point[arry[j]].y - point[arry[i]].y < d && j < k; j++)
			d = min(d, dis(i, j));
	}
	return d;
}

void write(int n, Point X[])
{
	FILE *out = fopen("output.txt", "w");
	fprintf(out, "%d ", n);
	for (int i = 1; i <= n; i++)
	{
		fprintf(out, "%lf ", X[i - 1].x);
		fprintf(out, "%lf ", X[i - 1].y);
	}
}

int main()
{
	double distance;
	scanf("%d", &n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		point[i].x = rand();
		point[i].y = rand();
		printf("(%lf,%lf)\n", point[i].x, point[i].y);
	}
	write(n, point);
	sort(point, point + n, comx);
	distance = Mincom(0, n - 1);
	printf("%lf", distance);
	return 0;
}