#include "List.h"
int main()
{
	Node* L;
	Init(L);
	ElemType a[9];
	for(int i = 0; i < 9; i++ )
		a[i] = i;
	CreateR(L, a, 9);
	
	printf("链表（删除前）:\n");
	Print(L);
	if(DeleteBackMax(L)) {
		printf("链表(删除后):\n");
		Print(L);
	}
		
	else
		printf("链表最大值后无元素.");
	return 0;
}
