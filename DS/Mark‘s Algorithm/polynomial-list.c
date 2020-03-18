typedef struct Node *PtrToNode;

struct Node
{
    int Cofficient;
    int Exponent;
    PtrToNode Next;
};

typedef PtrToNode Polynomial;
