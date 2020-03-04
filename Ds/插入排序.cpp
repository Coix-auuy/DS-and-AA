#include "List.h"
//void Qsort(Node* &N) {
//	Node *p = N->next->next;
//	N->next->next = NULL;
//	Node* q;
//	Node* temp;
//	while(p != NULL) {
//		q = N;
//		temp = p->next;
//		while(q->next != NULL && p->data > q->next->data) 
//			q = q->next;
//		p->next = q->next;
//		q->next = p;
//		p = temp;
//	
//	}
//		 
//}
int main()
{
	ElemType a[10] = {1, 5, 3, 4, 6, 2, 8, 9, 10, 7};
	Node* N;
	Init(N);
	CreateR(N, a, 10);
	DownSort(N);
	Print(N);
	DestroyList(N);
	return 0;
}
