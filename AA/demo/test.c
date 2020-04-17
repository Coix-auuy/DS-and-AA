#include <stdio.h>
#include <string.h>
void Next(char *T, int *next)
{
    int i = 0;
    next[0] = -1;
    int j = -1;
    while (i < strlen(T))
    {
        if (j == -1 || T[i] == T[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
int KMP(char *S, char *T)
{
    int next[100];
    Next(T, next);
    int i = 0;
    int j = 0;
    while (i < strlen(S))
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            if (next[j] == -1)
                i++;
            else
                j = next[j];
        }
    }
    if (j == strlen(T))
            return i -strlen(T);
    return -1;
}
int main()
{
    int i = KMP("baabaabbabaaabaabbabaabbaabaabbabaaabaabbabaab", "abaabbabaab");
    printf("%d", i);
    return 0;
}