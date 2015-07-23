//binary
#include <stdio.h>
#include <math.h>

int main()
{
  int x,r[1000], n, t;
  printf("enter decimal number");
  scanf("%d", &x);
  n=0;
while(x>0){
  r[n]=fmod(x,2);
  x=x/2;
  n=n+1;
 }

 while(n>0){
   n=n-1;
   t=r[n];
   printf("%d", t);
}
}
