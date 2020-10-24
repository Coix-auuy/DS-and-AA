#include "const.cpp"
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
} SqList;

Status InitList(SqList &L)
{ //构造一个空的顺序表L
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
Status GetElem(SqList L, int i, ElemType &e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;
	return 0;
}

//插入
Status ListInsert(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1)
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}
//打印顺序表
void Print(SqList L)
{
	for (int i = 0; i < L.length; i++)
		cout << L.elem[i] << ' ';
	cout << endl;
}

//删除
Status ListDelete(SqList &L, int i)
{
	if (i < 1 || i > L.length)
		return ERROR;
	for (int j = i; j < L.length; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return OK;
}

int main()
{
	freopen("in.txt", "r", stdin);
	SqList L;
	InitList(L);
	for (int i = 0; i < 5; i++)
		cin >> L.elem[i];
	L.length = 5;
	ElemType e;
	if (GetElem(L, 2, e))
		cout << e << endl;
	ListInsert(L, 3, 3);
	Print(L);
	ListDelete(L, 3);
	Print(L);
	return 0;
}
