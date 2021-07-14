#include "const.cpp"

typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//先序遍历创建二叉树(字符型)
void CreateBiTree(BiTree &T) {
    TElemType ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// void InOrderTraverse(BiTree T)
// {
//     if(T)
//     {
//         InOrderTraverse(T->lchild);
//         cout<<T->data;
//         InOrderTraverse(T->rchild);
//     }
// }
void InOrderTraverse(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    BiTNode *q;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        } else {
            q = s.top();
            s.pop();
            cout << q->data << ' ';
            p = q->rchild;
        }
    }
}

void PreOrderTraverse(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    BiTNode *q;
    while (p || !s.empty()) {
        if (p) {
            cout << p->data << ' ';
            s.push(p);
            p = p->lchild;
        } else {
            q = s.top();
            s.pop();
            p = q->rchild;
        }
    }
}

void PostOrderTraverse(BiTree T) {
    stack<BiTNode *> s;
    BiTNode *p = T;
    BiTNode *q;
    if (p) {
        do {
            while (p) {
                s.push(p);
                p = p->lchild;
            }
            q = NULL;
            bool flag = true;
            while (!s.empty() && flag) {
                p = s.top();
                if (p->rchild == q) {
                    cout << p->data << ' ';
                    s.pop();
                    q = p;
                } else {
                    p = p->rchild;
                    flag = false;
                }
            }
        } while (!s.empty());
    }
}

void LevelOrderTraverse(BiTree T) {
    queue<BiTNode *> Q;
    BiTNode *p = T;
    Q.push(p);
    while (!Q.empty()) {
        p = Q.front();
        cout << p->data << ' ';
        Q.pop();
        if (p->lchild)
            Q.push(p->lchild);
        if (p->rchild)
            Q.push(p->rchild);
    }
    cout << endl;
}

//复制一颗和T完全相同的二叉树
void Copy(BiTree T, BiTree &NewT) {
    if (T == NULL) {
        NewT = NULL;
        return;
    } else {
        NewT = new BiTNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}

//计算二叉树的深度
int Depth(BiTree T) {
    if (T)
        return max(Depth(T->lchild), Depth(T->rchild)) + 1;
    return 0;
}

//计算二叉树中的节点个数
int NodeCount(BiTree T) {
    if (T)
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    return 0;

}

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    int LTag, RTag;
} BiThrNode, *BiThrTree;

//先序遍历创建二叉线索树(字符型)
void CreateBiThrTree(BiThrTree &T) {
    TElemType ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else {
        T = new BiThrNode;
        T->data = ch;
        CreateBiThrTree(T->lchild);
        CreateBiThrTree(T->rchild);
    }
}

// 中序线索二叉树thread--线索
BiThrNode *pre;

void InTreading(BiThrTree p) {
    if (p) {
        InTreading(p->lchild);
        if (!p->lchild) {
            p->LTag = 1;
            p->lchild = pre;
        } else p->LTag = 0;
        if (!pre->rchild) {
            pre->RTag = 1;
            pre->rchild = p;
        } else pre->RTag = 0;
        pre = p;
        InTreading(p->rchild);
    }
}

void InOrderThreading(BiThrTree &Thrt, BiThrTree T) {
    Thrt = new BiThrNode;
    Thrt->LTag = 0;
    Thrt->RTag = 1;
    Thrt->rchild = Thrt;
    if (!T) Thrt->lchild = Thrt;
    else {
        Thrt->lchild = T;
        pre = Thrt;
        InTreading(T);
        pre->rchild = Thrt;
        pre->RTag = 1;
        Thrt->rchild = pre;
    }
}

//遍历中序线索树
void InOrderTraverse_Thr(BiThrTree T) {
    BiThrNode *p = T->lchild;
    while (p != T) {
        while (p->LTag == 0) p = p->lchild;
        cout << p->data << ' ';
        while (p->RTag == 1 && p->rchild != T) {
            p = p->rchild;
            cout << p->data << ' ';
        }
        p = p->rchild;
    }
}

int main() {
    setbuf(stdout, NULL);
    freopen("in.txt", "r", stdin);
    BiThrTree T;
    CreateBiThrTree(T);
    BiThrTree Thrt;
    InOrderThreading(Thrt, T);
    InOrderTraverse_Thr(Thrt);
    return 0;
}
