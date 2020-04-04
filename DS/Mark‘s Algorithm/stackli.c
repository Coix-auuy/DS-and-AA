#include "fatal.h"
#include "stackli.h"
//如果.c中的函数也需要调用同个.c中的其它函数，那么这个.c往往会include同名的.h，这样就不需要为声明和调用顺序而发愁了
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void) //使用哑元来区分
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S == NULL)
        FatalError("Out of space!!!");
    S->Next == NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if (S == NULL)
        Error("Must use CreateStack first");
    else
        while (!IsEmpty(S))
            Pop(S);
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FatalError("Out of space!!!");
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    Error("Empty stack");
    return 0; //Return value used to avoid warning
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if (IsEmpty(S))
        Error("Empty stack");
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}
