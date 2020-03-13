#include "list.h"
#include <stdlib.h>
#include "fatal.h"
#include "list.c"
int main()
{
    List a;
    a = malloc(sizeof(List));
    a->Next = NULL;
    printf("%d", IsEmpty(a));
}
