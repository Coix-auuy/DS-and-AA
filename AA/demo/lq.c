#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MaxSize 100
void GetNext(char *t,int next[])
{
   int tlength=strlen(t);
   int j=0,k=-1;
   next[0]=-1;
   while(j<tlength-1)
   {
      if(k == -1 || t[j] == t[k])
      {
         j++;k++;
         next[j]=k;
      }
      else k = next[k];
   }
}
int KMP(char *s,char *t)
{
   int slength=strlen(s);
   int tlength=strlen(t);
   int next[MaxSize],i=0,j=0;
   GetNext(t,next);
   while(i<slength&&j<tlength)
   {
      if(j==-1 || s[i]==t[j])
      {
         i++;
         j++;
      }
      else j=next[j];               
   }
   if(j>=tlength)
       return (i-tlength);         
   else
      return (-1);                 
}
int main()
{
    char a[] = "ababaca";
    char b[] = "bacbababadababacambabacaddababacasdsd";
    printf("%d",KMP(b, a));
    return 0;
}