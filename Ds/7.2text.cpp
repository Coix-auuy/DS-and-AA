#include<stdio.h>
#include "btree.h"
struct{
	int n;
}a;
int main()
{
	char c[199] = "a(b(c,d),e(f))";
	a.n = 11;
	printf("%d",a.n);
		
}
