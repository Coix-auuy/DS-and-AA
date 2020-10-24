#include "const.cpp"
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStack;
Status InitStack(LinkStack &S)
{
	S = NULL;
	return OK;
}
Status Push(LinkStack &S, SElemType e)
{
	StackNode *p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack &S,SElemType &e)
{
	if(S == NULL)
		return ERROR;
	e = S->data;
	StackNode *p = S;
	S = S->next;
	delete p;
	return OK;
}
//SElemType GetTop(LinkStack S)
//{
//	if(S!= NULL)
//		return S->data;
//}
