#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100
#define MAX(x, y) ((x) > (y) ? (x) : (y))
typedef char ElemType;
//初始化树（孩子兄弟表示法）
typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
} BTNode; //binary tree
//孩子兄弟表示法将一般树转换为二叉树
void change(BTNode *t)
{
	//建树时，首先输入根值，接着再输入其所有孩子的值，以0结束
	ElemType x;
	//开始输入第一个孩子
	getchar();
	scanf("%c", &x);
	if (x != '0')
	{
		t->lchild = (BTNode *)malloc(sizeof(BTNode));
		t->lchild->data = x;
		t->lchild->lchild = t->lchild->rchild = NULL;
	}
	else
	{
		//根节点没有孩子直接返回
		t->lchild =  NULL;
		return;
	}
	//输入第一个孩子的兄弟
	BTNode *temp = t->lchild;
	getchar();
	scanf("%c", &x);
	while (x != '0')
	{
		temp->rchild = (BTNode *)malloc(sizeof(BTNode));
		temp->rchild->data = x;
		temp = temp->rchild;
		temp->lchild = temp->rchild = NULL;
		getchar();
		scanf("%c",&x);
	}
	//递归每一个孩子子树
	temp = t->lchild;
	while (temp)
	{
		change(temp);
		temp = temp->rchild;
	}
}
// 根据括号表示法建立二叉树
void CreateBTree(BTNode *&b, char str[])
{
	BTNode *st[MaxSize];
	BTNode *p;
	int top = -1, k;
	b = NULL;
	for (int i = 0; i < strlen(str); i++)
	{
		switch (str[i])
		{
		case '(':
			top++;
			st[top] = p;
			k = 0;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 1;
			break;
		default:
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data = str[i];
			p->lchild = NULL;
			p->rchild = NULL;
			if (b == NULL)
				b = p;
			else
			{
				if (k)
					st[top]->rchild = p;
				else
					st[top]->lchild = p;
			}
		}
	}
}
// 删除二叉树
void DestroyBTree(BTNode *&b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
// 查找节点
BTNode *FindNode(BTNode *b, ElemType x)
{
	BTNode *p;
	if (b == NULL)
		return NULL;
	if (b->data == x)
		return b;
	p = FindNode(b->lchild, x);
	if (p != NULL)
		return p;
	return FindNode(b->rchild, x);
}
// 树高
int BTHeight(BTNode *b)
{
	int lchild, rchild;
	if (b == NULL)
		return 0;
	lchild = BTHeight(b->lchild);
	rchild = BTHeight(b->rchild);
	return MAX(lchild, rchild) + 1;
}
// 以括号表达式的方式输出二叉树
void DispBTree(BTNode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL)
				printf(",");
			DispBTree(b->rchild);
			printf(")");
		}
	}
}
// 先序递归
void PreOrder(BTNode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
	return;
}
// 中序递归
void InOrder(BTNode *b)
{
	if (b != NULL)
	{
		PreOrder(b->lchild);
		printf("%c", b->data);
		PreOrder(b->rchild);
	}
}
// 后序递归
void PostOrder(BTNode *b)
{
	if (b != NULL)
	{
		PreOrder(b->lchild);
		PreOrder(b->rchild);
		printf("%c", b->data);
	}
}
// 先序非递归
void PreOrderSt(BTNode *b)
{
	BTNode *St[MaxSize], *p;
	int top = -1;
	if (b != NULL)
	{
		top++;
		St[top] = b;
		while (top > -1)
		{
			p = St[top];
			top--;
			printf("%c", p->data);
			if (p->rchild != NULL)
			{
				top++;
				St[top] = p->rchild;
			}
			if (p->lchild != NULL)
			{
				top++;
				St[top] = p->lchild;
			}
		}
		printf("\n");
	}
}
// 中序非递归
void InOrderSt(BTNode *b)
{
	BTNode *St[MaxSize], *p;
	int top = -1;
	if (b != NULL)
	{
		p = b;
		while (top > -1 || p != NULL)
		{
			while (p != NULL)
			{
				top++;
				St[top] = p;
				p = p->lchild;
			}
			if (top > -1)
			{
				p = St[top];
				top--;
				printf("%c", p->data);
				p = p->rchild;
			}
		}
		printf("\n");
	}
}
// 后序非递归
void PostOrderSt(BTNode *b)
{
	BTNode *St[MaxSize];
	BTNode *p;
	int top = -1;
	int flag; //bool
	if (b != NULL)
	{
		do
		{
			while (b != NULL)
			{
				top++;
				St[top] = b;
				b = b->lchild;
			}
			p = NULL;
			flag = true;
			while (top != -1 && flag)
			{
				b = St[top];
				if (b->rchild == p)
				{
					printf("%c", b->data);
					top--;
					p = b;
				}
				else
				{
					b = b->rchild;
					flag = false;
				}
			}
		} while (top != -1);
		printf("\n");
	}
}
// 层次遍历
void TravLevel(BTNode *b)
{
	BTNode *Qu[MaxSize];
	int front, rear;
	front = rear = 0;
	if (b != NULL)
		printf("%c", b->data);
	rear++;
	Qu[rear] = b;
	while (rear != front)
	{
		front = (front + 1) % MaxSize;
		b = Qu[front];
		if (b->lchild != NULL)
		{
			printf("%c", b->lchild->data);
			rear = (rear + 1) % MaxSize;
			Qu[rear] = b->lchild;
		}
		if (b->rchild != NULL)
		{
			printf("%c", b->rchild->data);
			rear = (rear + 1) % MaxSize;
			Qu[rear] = b->rchild;
		}
	}
	printf("\n");
}

// 节点数
int Nodes(BTNode *b)
{
	int num1, num2;
	if (b == NULL)
		return 0;
	else if (b->lchild == NULL && b->rchild == NULL)
		return 1;
	else
	{
		num1 = Nodes(b->lchild);
		num2 = Nodes(b->rchild);
		return num1 + num2 + 1;
	}
}

// 叶子节点数
int LeafNodes(BTNode *b)
{
	int num1, num2;
	if (b == NULL)
		return 0;
	else if (b->lchild == NULL && b->rchild == NULL)
		return 1;
	else
	{
		num1 = LeafNodes(b->lchild);
		num2 = LeafNodes(b->rchild);
		return num1 + num2;
	}
}
// 某一节点所属层
int Level(BTNode *b, ElemType x, int h)
{
	int l;
	if (b == NULL)
		return 0;
	else if (b->data == x)
		return h;
	else
	{
		l = Level(b->lchild, x, h + 1);
		if (l != 0)
			return l;
		else
			return Level(b->rchild, x, h + 1);
	}
}

// 树宽
int BTWidth(BTNode *b)
{
	struct
	{
		int lno;
		BTNode *p;
	} Qu[MaxSize];
	int front, rear;
	int lnum, max, i, n;
	front = rear = -1;
	if (b != NULL)
	{
		rear++;
		Qu[rear].p = b;
		Qu[rear].lno = 1;
		while (rear != front)
		{
			front++;
			b = Qu[front].p;
			lnum = Qu[front].lno;
			if (b->lchild != NULL)
			{
				rear++;
				Qu[rear].p = b->lchild;
				Qu[rear].lno = lnum + 1;
			}
			if (b->rchild != NULL)
			{
				rear++;
				Qu[rear].p = b->rchild;
				Qu[rear].lno = lnum + 1;
			}
		}
		max = 0;
		lnum = 1;
		i = 0;
		while (i <= rear)
		{
			n = 0;
			while (i <= rear && Qu[i].lno == lnum)
			{
				n++;
				i++;
			}
			lnum = Qu[i].lno;
			if (n > max)
				max = n;
		}
		return max;
	}
	else
		return 0;
}
