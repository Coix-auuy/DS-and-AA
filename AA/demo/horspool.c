#include <stdio.h>
#include <string.h>
void shiftTable(char *p, int *table)
{
    int m = strlen(p);
    for (int i = 0; i < 26; i++)
        table[i] = m;
    for (int i = 0; i < m - 1; i++)
        table[p[i] - 65] = m - 1 - i;
}

int horspoolMatching(char *p, char *t)
{
    //建立移动表
    int table[26];
    shiftTable(p, table);
    //开始搜索
    int m = strlen(p);
    int n = strlen(t);
    for (int i = m - 1; i < n; i = i + table[t[i] - 65])
    {
        int k = 0;
        while (p[m - 1 - k] == t[i - k] && k < m)
            k++;
        if (k == m)
            return i - m + 1;
    }
    return -1;
}
int main()
{
    char *p = "HELLO";
    char *t = "ABCDWFTPCOXYZHELLO";
    printf("%d", horspoolMatching(p, t));
    return 0;
}