#include <bits/stdc++.h>
using namespace std;
#include <ctime>
#define min(x, y) (x < y) ? x : y
#define Max 100000
struct Node
{
    double x, y;
} node[Max];
Node tem[Max];
bool cmpX(Node a, Node b) { return a.x < b.x; }
bool cmpY(Node a, Node b) { return a.y < b.y; }

double distance(Node node1, Node node2)
{
    double t;
    t = (node1.x - node2.x) * (node1.x - node2.x) + (node1.y - node2.y) * (node1.y - node2.y);
    return sqrt(t);
}

double MinDis(Node s[], int left, int right)
{
    if (right - left == 1)
    {
        return distance(s[right], s[left]);
    }
    if (right - left == 2)
    {
        double d1 = distance(s[right], s[left]);
        double d2 = distance(s[right], s[left + 1]);
        double d3 = distance(s[left + 1], s[left]);
        d2 = min(d1, d2);
        d3 = min(d2, d3);
        return d3;
    }

    int m = (right + left) / 2;
    double d1 = MinDis(s, left, m);
    double d2 = MinDis(s, m + 1, right);
    double d = min(d1, d2);
    int tot = 0;
    for (int i = left; i <= right; i++)
    {
        if (fabs(node[i].x - node[m].x <= d))
            tem[tot++] = node[i];
    }
    sort(tem, tem + tot, cmpY);
    for (int i = 0; i < tot; i++)
    {
        for (int j = i + 1; j < i + 6 && j < tot; j++)
        {
            d = min(d, distance(tem[i], tem[j]));
        }
    }
    return d;
}

int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        node[i].x = rand();
        node[i].y = rand();
    }
    sort(node, node + n, cmpX);
    printf("%lf", MinDis(node, 0, n - 1));
}