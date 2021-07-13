#include "const.cpp"
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
//��ʼ��
Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}
//ȡֵ
Status GetElem(LinkList L, int i, ElemType &e)
{
    LNode *p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}
//��ֵ����
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}
//����
Status ListInsert(LinkList &L, int i, ElemType e)
{
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i - 1)
        return ERROR;
    LNode *q = new LNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}
//��ӡ����
void Print(LinkList L)
{
    LNode *p = L->next;
    while (p->next)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << p->data << endl;
}
//ɾ��
Status ListDelet(LinkList &L, int i)
{
    LNode *p = L;
    int j = 0;
    while (p->next && j < i - 1) //p->next
    {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i - 1)
        return ERROR;
    LNode *q = p->next;
    p->next = p->next->next;
    delete q;
    return OK;
}
//ͷ�巨
void CreateList_H(LinkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    for (int i = 0; i < n; ++i)
    {
        LNode *p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}
void CreateList_R(LinkList &L, int n)
{
    L = new LNode;
    L->next;
    LNode * r = L;
    for(int i = 0; i < n; i++)
    {
        LNode *p = new LNode;
        cin>>p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
int main()
{
    LinkList L;
    // InitList(L);
    // for (int i = 1; i <= 5; i++)
    //     ListInsert(L, i, i);
    // Print(L);
    // ListDelet(L, 5);
    freopen("in.txt", "r", stdin);
    CreateList_R(L, 5);
    Print(L);
    return 0;
}
