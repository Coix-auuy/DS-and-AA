#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *getNextTable(char *pattern)
{
    int n = strlen(pattern);
    int *nextTable = (int *)malloc(n * sizeof(int));
    nextTable[0] = -1;
    for (int i = 1; i < n; i++)
    {
        int j = nextTable[i - 1];
        while (pattern[j + 1] != pattern[i] && j >= 0)
            j = nextTable[j];
        if (pattern[j + 1] == pattern[i])
            nextTable[i] = j + 1;
        else
            nextTable[i] = -1;
    }
    //此处求出的nextTable[i]实际上是pattern[0~i]中最长相等前后缀的前缀的最后一个字符的索引。
    //所以pattern[0~i]中最长的前后缀字符数实际为nextTable[i]+1;
    return nextTable;
}
void search(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int *nextTable = getNextTable(pattern);
    for (int i = 0, j = 0; i < n;)
    {
        if (text[i] == pattern[j])
        {
            i++, j++;
            if (j == m)
            {
                printf("%d ", i - m);
                j = nextTable[j - 1] + 1;
            }
        }
        else
        {
            if (j == 0)
                i++; //无前缀,所以text移动,开始下一次从头比较
            else
                j = nextTable[j - 1] + 1; //前缀的下一个字符开始比较
        }
    }
}
int main()
{
    char *p = "abaabbabaab";
    char *t = "baabaabbabaaabaabbabaabbaabaabbabaaabaabbabaab";
    search(t, p);
    return 0;
}