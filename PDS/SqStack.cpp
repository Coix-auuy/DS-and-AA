#include "const.cpp"
using namespace std;
#define MAXSIZE 10
typedef int SElemType ;
typedef struct 
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S)
{
	S.base = new SElemType[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack &S, SElemType e)
{
	if(S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack &S, SElemType &e)
{
	if(S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
SElemType GetTop(SqStack S)
{
	if(S.top != S.base)
		return *(S.top - 1);
}
int main()
{
	SqStack S;
	if(InitStack(S))
		cout<<"Init Success!"<<endl;
	for(int i = 0; i < 10; i++)
		Push(S, i);
	if(!Push(S,11))
		cout<<"Push Fail!"<<endl;
	SElemType e;
	cout<<GetTop(S)<<endl;
	for(int i = 0; i < 10; i++) {
		Pop(S, e);
		cout<<e<<' ';
	}
	return 0;
}
