#include "List.h"
int main()
{
	Node* L;
	Init(L);
	ElemType a[9];
	for(int i = 0; i < 9; i++ )
		a[i] = i;
	CreateR(L, a, 9);
	
	printf("����ɾ��ǰ��:\n");
	Print(L);
	if(DeleteBackMax(L)) {
		printf("����(ɾ����):\n");
		Print(L);
	}
		
	else
		printf("�������ֵ����Ԫ��.");
	return 0;
}
