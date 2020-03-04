#include "HashTable.h"
int main() 
{
	int a[11] = {16,74,60,43,54,90,46,31,29,88,77};
	HashTable ha[MaxSize];
	int n = 11;
	int m = 13;
	CreateHT(ha, a, n, m, 13);
	DispHT(ha, n, m);
	printf("%d", SearchHT(ha,m,13,31));
	InsertHT(ha, n, m, 13, 100);
	DispHT(ha, n, m);
	DeleteHT(ha, m, 13, n, 100);
	DispHT(ha, n, m);
}
