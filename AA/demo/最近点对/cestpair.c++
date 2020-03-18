#include <bits/stdc++.h>
#define INIT(a, b) memset(a, b, sizeof(a))
#define LL long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 7;
const int mod = 1e9 + 7;

struct Node
{
    double x, y;
} node[maxn];

Node tem[maxn];

bool cmpX(Node a, Node b)
{
    return a.x < b.x;
}

bool cmpY(Node a, Node b)
{
    return a.y < b.y;
}

double Dis(Node a, Node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double MinDis(int l, int r)
{
    int len = r - l + 1;
    if (len == 2)
        return Dis(node[l], node[r]);
    if (len == 3)
        return min(min(Dis(node[l], node[l + 1]), Dis(node[l + 1], node[r])), Dis(node[l], node[r]));
    int mid = (l + r) >> 1;
    double d = min(MinDis(l, mid), MinDis(mid + 1, r));
    int tot = 0;
    for (int i = l; i <= r; i++)
        if (fabs(node[i].x - node[mid].x <= d))
            tem[tot++] = node[i];

    sort(tem, tem + tot, cmpY);

    for (int i = 0; i < tot; i++)
        for (int j = i + 1; j < i + 6 && j < tot; j++)
            d = min(d, Dis(tem[i], tem[j]));
    return d;
}
int main()
{
    int n;
    FILE *in = fopen("output.txt", "r");
    //读入数据
    fscanf(in, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fscanf(in, "%lf", &node[i].x);
        fscanf(in, "%lf", &node[i].y);
    }

    sort(node + 1, node + 1 + n, cmpX);
    printf("%lf\n", MinDis(1, n));
    return 0;
}