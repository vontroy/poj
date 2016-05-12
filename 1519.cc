#include <stdio.h> 
 char a[10000];
int main() 
{ 
 long n; 
 int i; 
 while(gets(a) && a[0] != '0')
 { n=0;
  for(i=0;a[i]; ++i)
   n+=a[i]-'0';
  printf("%d\n",n%9==0?9:n%9); 
 } 
 return 0; 
}