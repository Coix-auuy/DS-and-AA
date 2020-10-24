#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    string text = "abc    aa  cc  d   ";
    char *p;
    const char *d = " *";
    char str[1010];
    for (int i = 0; i < text.length(); i++)
        str[i] = text[i];
    str[text.length()] = '\0';
    p = strtok(str, d);
    while (p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL,d);
    }
    return 0;
}