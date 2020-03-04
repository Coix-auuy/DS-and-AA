#include "List.h"
#include<stdio.h>
void Splist(Node*& N, ElemType x) {
	Node *s, *p = N->next, *q;
	N->next = NULL;
	s = N;
	while(p != NULL) {
		if(p->data < x) {
			q = p->next;
			p->next = N->next;
			N->next = p;	
			if(p->next == NULL)
				s = p;
			p = q;
		}
		else {
			s->next = p;
			s = p;
			p = p->next;
		}
	}
	s->next = NULL;
}
int main()
{
	Node* N;
	Init(N);
	CreateF(N);
	Splist(N, 6);
	Print(N);
	DestroyList(N);
}

