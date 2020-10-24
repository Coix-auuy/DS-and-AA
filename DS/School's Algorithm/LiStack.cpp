#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct linknode {
	ElemType data;
	struct linknode *next;
	
}LinkStNode;
void InitStack(LinkStNode *&s) {
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
} 
void DestroyStack(LinkStNode *&s) {
	LinkStNode *p = s, *pre;
	while(p != NULL) {
		pre = p;
		p = p->next;
		free(pre);
	}
}
bool StackEmpty(LinkStNode *s) {
	return s->next == NULL;
}
void Push(LinkStNode *&s, ElemType e) {
	LinkStNode *p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
bool Pop(LinkStNode *&s, ElemType &e) {
	if(s->next == NULL)
		return false;
	e = s->next->data;
	LinkStNode *p = s->next;
	free(p);
	s->next = s->next->next; 
	return true;
}
bool GetTop(LinkStNode *&s, ElemType &e) {
	if(s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}

