#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *getNext(char pattern[])
{
    int m = strlen(pattern);
    int *next = (int *)malloc((m + 1) * sizeof(int));
    next[0] = -1;
    for (int i = 0, j = -1; i < m + 1;)
    {
        if (j == -1 || pattern[i] == pattern[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
    return next;
}
void search(char text[], char pattern[])
{
    int *next = getNext(pattern);
    int n = strlen(text);
    int m = strlen(pattern);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (j == -1 || text[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                printf("%d ", (i - m));
                j = next[j];
            }
        }
        else
            j = next[j];
    }
}
int main()
{
    char *p = (char *)"abaabbabaab";
    char *t = (char *)"baabaabbabaaabaabbabaababaabbabaabaaabaabbabaab";
    search(t,p);
    return 0;
}