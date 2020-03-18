#include <bits/stdc++.h>
using namespace std;
#include <ctime>
#define MAX 1001
//普通点
typedef struct
{
    double x, y;
} point;
//映射点
typedef struct
{
    int index;
    double x, y;
} point_m;

bool cmpX(point a, point b)
{
    return a.x < b.x;
}

bool cmpY(point_m a, point_m b)
{
    return a.y < b.y;
}

double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closestpair(point X[], point_m Y[], int l, int h)
{
    if (h - l == 1)
        return dis(X[l], X[h]);
    if (h - l == 2)
        return min(min(dis(X[l], X[l + 1]), dis(X[l + 1], X[h])), dis(X[l], X[h]));

    point_m sl[h - l + 1]; //左侧
    point_m sr[h - l + 1]; //右侧
    int mid = (h + l) >> 1;
    int j, k;
    j = k = 0;
    //将映射点分到对应数组，Y数组以y有序，故分到对应数组后依然有序
    for (int i = 0; i <= h - l; i++)
        if (Y[i].index <= mid)
            sl[j++] = Y[i];
        else
            sr[k++] = Y[i];
    //分治
    double d = min(closestpair(X, sl, l, mid), closestpair(X, sr, mid + 1, h));
    //检测带中区域
    point tem[h - l + 1];
    k = 0;
    for (int i = 0; i < h - l + 1; i++)
    {
        //距离比d小才有可能成为使得点对距离小于d的其中一点
        if (fabs(X[mid].x - Y[i].x) <= d)
        {
            tem[k].x = Y[i].x;
            tem[k].y = Y[i].y;
            k++;
        }
    }
    for (int i = 0; i < k; i++)
        // j < i + 6 个人认为此条件可以去除，只要程序没有逻辑错误，k必定小于或等于6
        for (int j = i + 1; j < k; j++)
        {
            //纵向距离如果比d大，则直接跳过,因为y是排序的，所以之后的点必定也大于d
            if (tem[j].y - tem[i].y >= d)
                break;
            d = min(d, dis(tem[i], tem[j]));
        }
    return d;
}
//获取随机点
void obtainPoint(int n, point X[])
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        X[i].x = rand();
        X[i].y = rand();
    }
}
//写入output.txt
void write(int n, point X[])
{
    FILE *out = fopen("output.txt", "w");
    fprintf(out, "%d ", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(out, "%lf ", X[i].x);
        fprintf(out, "%lf ", X[i].y);
    }
}
int main()
{
    int n;
    point X[MAX];
    point_m Y[MAX];
    scanf("%d", &n);
    obtainPoint(n, X);
    write(n, X);
    sort(X, X + n, cmpX);
    for (int i = 0; i < n; i++)
    {
        Y[i].x = X[i].x;
        Y[i].y = X[i].y;
        Y[i].index = i;
    }
    sort(Y, Y + n, cmpY);
    printf("%lf", closestpair(X, Y, 0, n - 1));
    return 0;
}