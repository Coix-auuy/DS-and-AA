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
                i++;
            else
                j = nextTable[j - 1] + 1;
        }
    }
}
int main()
{
    char *p = "abaabbabaab";
    char *t = "baabaabbabaaabaabbabaabbaabaabbabaaabaabbabaab";
    search(t,p);
    return 0;
}