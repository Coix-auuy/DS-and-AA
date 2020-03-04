#include "List.h"
void Merge(Node *L1, Node *L2, Node *&L3) {
	Node *p1 = L1->next;
	Node *p2 = L2->next;
	Node *p = L3;
	while(p1 != NULL && p2 != NULL) {
			p->next = p1; p = p1; p1 = p1->next;
			p->next = p2; p = p2; p2 = p2->next;
	}
	if(p2 != NULL) 
		p1 = p2;
	p->next = p1;
}
int main()
{
	Node *L1, *L2, *L3;
	Init(L1);
	Init(L2);
	Init(L3);
	ElemType a1[5] = {2, 4, 6, 8, 10};
	ElemType a2[6] = {1, 3, 5, 7, 9, 11};
	CreateR(L1, a2, 6);
	CreateR(L2, a1, 5);
	Merge(L1, L2 ,L3);	
	print(L3);
	DestroyList(L1);
	DestroyList(L2);
	return 0;
}
