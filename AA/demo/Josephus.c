#include<stdio.h>
#include<math.h>
int crol (int n,int i)
{
    int a = 0;
    int temp = n;
    while(temp)
        temp/=2,a++;
    int t = 0;
    for(int j = 0 ; j < a; j++) {
        t += pow(2,j);
    }
    temp = n >> (a-i);
    n = n << i;
    n = n | temp;
    n = n & t;
    return n;
}
int main()
{
    int i;
    scanf("%d",&i);
    int n = 0;
    while(i--) {
        scanf("%d", &n);
        printf("%d\n",crol(n,1));
    }
    return 0 ;
}