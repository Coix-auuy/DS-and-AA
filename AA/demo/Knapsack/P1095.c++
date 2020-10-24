#include <cstdio>
#include <cmath>
using namespace std;
#define MAX(x, y) ((x) > (y) ? (x) : (y))
struct dP
{
    int far;
    int nl;
    int tapfar;
} dp[300004];

int main()
{
    int m, s, t;
    scanf("%d%d%d", &m, &s, &t);
    dp[0].nl = m;
    for (int i = 1; i <= t; i++)
    {
        if(dp[i - 1].nl >= 10)
        {
            dp[i].nl = dp[i - 1].nl - 10;
            dp[i].tapfar = dp[i - 1].tapfar + 60;
        }
        else
        {
            dp[i].nl = dp[i - 1].nl + 4;
            dp[i].tapfar = dp[i - 1].tapfar;
        }
        dp[i].far = MAX(dp[i - 1].far + 17, dp[i].tapfar);
    }
    if (dp[t].far < s)
        printf("No\n%d\n", dp[t].far);
    else
    {
        int i;
        for (i = 1; i <= t; i++)
            if (dp[i].far >= s)
                break;
        printf("Yes\n%d\n", i);
    }
    return 0;
}