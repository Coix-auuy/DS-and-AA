#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define NULLKEY -1
#define DELKEY -2
typedef int KeyType;
typedef char InfoType;
typedef struct{
	KeyType key;
	InfoType data;
	int count;
}HashTable;
//m->哈希表长度,n->现存储数,p->除数,k->关键字 
void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k) {
	int adr = k % p, i; 
	if(ha[adr].key == NULLKEY || ha[adr].key == DELKEY) {
		ha[adr].key = k;
		ha[adr].count = 1;
	}else {
		i = 1;
		do { 
			adr = (adr + 1) % m;
			i++;
		}while(ha[adr].key != NULLKEY && ha[adr].key != DELKEY);
		ha[adr].key = k;
		ha[adr].count = i;
	}
	n++;
}

void CreateHT(HashTable ha[], KeyType x[], int n, int m, int p) {
	int n1 = 0;
	for(int i = 0; i < m; i++) {
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}
	for(int i = 0; i < n; i++) {
		InsertHT(ha, n1, m, p, x[i]);
	}
} 

int SearchHT(HashTable ha[], int m, int p, KeyType k) {
	int adr = k % p;
	while(ha[adr].key != NULLKEY && ha[adr].key != k) {
		adr = (adr + 1) % m;
	}
	if(ha[adr].key == k) return adr;
	return -1;
} 

int DeleteHT(HashTable ha[], int m, int p, int &n, int k) {
	int adr = SearchHT(ha, m, p, k);
	if(adr == -1)
	return 0;
	ha[adr].key = DELKEY;
	n--;
	return 1;
}

void DispHT(HashTable ha[], int n, int m) {
	float avg = 0;
	for(int i = 0; i < m; i++)
		printf("%-4d", i);
	printf("\n");
	for(int i = 0; i < m; i++) {
		if(ha[i].key == NULLKEY || ha[i].key == DELKEY)
			printf("    ");
		else
			printf("%-4d", ha[i].key);
	}
	printf("\n");
	for(int i = 0; i < m; i++) {
		if(ha[i].key == NULLKEY || ha[i].key == DELKEY)
			printf("    ");
		else
			printf("%-4d", ha[i].count);
	}
	printf("\n");
	for(int i = 0; i < m; i++) {
		if(ha[i].key != NULLKEY && ha[i].key != DELKEY)
			avg += ha[i].count;
	}
	printf("%f", avg/n);
}















