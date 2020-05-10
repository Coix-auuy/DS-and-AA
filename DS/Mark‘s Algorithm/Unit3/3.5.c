#include "../list.c"
int main()
{
    List l1, l2;
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    l1 = RCreateList(arr1, 6);
    int arr2[6] = {3, 4, 5, 6, 7, 8};
    l2 = RCreateList(arr2, 6);
    DisplayList(l1);
    DisplayList(l2);
    List lr = malloc(sizeof(PtrToNode));
    lr->Next = NULL;
    Position p = First(l1), q = First(l2), r = lr;
    while (p != NULL && q != NULL)
    {
        if (p->Element < q->Element)
        {
            Insert(p->Element, lr, r);
            r = r->Next;
            p = p->Next;
        }
        else if (p->Element > q->Element)
        {
            Insert(q->Element, lr, r);
            r = r->Next;
            q = q->Next;
        }
        else
        {
            Insert(q->Element, lr, r);
            r = r->Next;
            p = p->Next;
            q = q->Next;
        }
    }
    while (p != NULL)
    {
        Insert(p->Element, lr, r);
        r = r->Next;
        p = p->Next;
    }
    while (q != NULL)
    {
        Insert(q->Element, lr, r);
        r = r->Next;
        q = q->Next;
    }
    DisplayList(lr);
    return 0;
}