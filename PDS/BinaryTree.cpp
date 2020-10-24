#include "const.cpp"
#include <stack>
#include<queue>

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
    if(T == NULL)
    {
        NewT = NULL;
        return;
    }else
    {
        NewT = new BiTNode ;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }
}
//计算二叉树的深度

int main() {
    setbuf(stdout, NULL);
    freopen("in.txt", "r", stdin);
    BiTree T;
    CreateBiTree(T);
    LevelOrderTraverse(T);
    BiTree NewT;
    Copy(T,NewT);
    LevelOrderTraverse(NewT);
    return 0;
}
