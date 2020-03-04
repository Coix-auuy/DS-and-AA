#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	LinkNode* next;
}Node;
void Init(Node* &N) {
	N = (Node *)malloc(sizeof(Node));
	N->next = NULL;
}
void DestroyList(Node* &N) {
	Node* p = N->next;
	Node* q = N;
	while(p != NULL) {
		free(q);
		q = p;
		p = p->next;
	}
	free(p);
}
void CreateR(Node* &N, ElemType a[], int n) {//β�巨 
	Node *p = N;
	for(int i = 0; i < n; i++) {
		Node *s = (Node *)malloc(sizeof(Node));
		s->data = a[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;
}
void CreateF(Node* &N, ElemType a[], int n) {//ͷ�巨 
	for(int i = 0; i< n; i++) {
		Node *s = (Node *)malloc(sizeof(Node));
		s->data = a[i];
		s->next = N->next;
		N->next = s;
	}
}
void Print(Node* N){
	Node* p = N->next;
	while(p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
} 
int Length(Node* N) {
	int count = 0;
	Node* p = N->next;
	while(p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}
bool IsEmpty(Node* N) {
	return N->next == NULL;
}
bool GetElem(Node *N, ElemType &e, int i) {
	Node* p = N->next;
	i--;
	while(i--&&p != NULL) {
		p = p->next;
	}
	if(p == NULL)
		return false;
	e = p->data;
	return true;
}
int LocateElem(Node* N, ElemType e) {
	Node* p = N->next;
	int count = 1;
	while(p != NULL&&p->data != e) {
		count++;
		p = p->next;
	}	
	if(p == NULL)
		return 0;
	return count;
}
bool ListInsert(Node* &N, ElemType e, int i){
	Node* p = N;
	i--;
	while(i--&&p != NULL)
		p = p->next;
	if(p == NULL)
		return false;
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = p -> next;
	p->next = s;
	return true;
}
bool ListDelete(Node* &N, ElemType &e, int i) {
	i--;
	Node* p = N;
	while(i--&&p != NULL) 
		p = p->next;
	if(p == NULL)
		return false;
	Node* q = p->next;
	e = q->data;
	p->next = p->next->next;
	free(q);
	return true;
}
void UpSort(Node *&N) {
	Node *p = N->next->next, *q, *pre;
	N->next->next = NULL;
	while(p != NULL) {
		q = p->next;
		pre = N;
		while(pre->next != NULL && pre->next->data < p->data  )
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
void DownSort(Node *&N) {
	Node *p = N->next->next, *q, *pre;
	N->next->next = NULL;
	while(p != NULL) {
		q = p->next;
		pre = N;
		while(pre->next != NULL && pre->next->data > p->data  )
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
bool DeleteBackMax(Node* L) {
	Node *p = L->next;
	Node *max = L->next;
	while(p != NULL) {
		if(max->data <= p->data)
			max = p;
		p = p->next;
	}
	if(max->next == NULL)
		return false;
	p = max->next;
	max->next = max->next->next;
	free(p);
	return true;
}

