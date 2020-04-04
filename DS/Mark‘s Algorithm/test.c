#include "list.c"
int main()
{
    ElementType Arr1[5] = {1, 2, 3, 4, 5};
    ElementType Arr2[3] = {1, 4, 5};
    List L = RCreateList(Arr1, 5);
    DisplayList(L);
    List P = RCreateList(Arr2, 3);
    DisplayList(P);
    PrintLots(L, P);
}