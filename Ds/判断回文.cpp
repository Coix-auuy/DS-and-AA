#include"sqstack.h"
#include<string.h>
int main()
{
	char str[MaxSize];
	SqStack* sq;
	InitStack(sq);
	ElemType  e;
	int flag;
	while(scanf("%s",str) != 0) {
		flag = 1;
		for(int i = 0; i < strlen(str); i++)
			Push(sq, (ElemType)str[i]);
		for(int i = 0; i < strlen(str); i++){
			Pop(sq, e);
			if(str[i] != e) {
				flag = 0;
				break;
			}
		}
		flag?printf("Yes\n"):printf("No\n");
	}
	return 0;
}
