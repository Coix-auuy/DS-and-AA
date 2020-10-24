#include "BTree.cpp"
int main()
{
    BTNode *b = (BTNode *)malloc(sizeof(BTNode));
    scanf("%c", &b->data);
    b->lchild = b->rchild = NULL;
    change(b);
    PreOrder(b);
    return 0;
}
