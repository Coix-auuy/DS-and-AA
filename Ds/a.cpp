#include"btree.h"
int main() {
    char str[100] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    DispBTree(b);
    return 0;
}