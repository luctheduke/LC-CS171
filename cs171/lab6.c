
#include <stdio.h>
#include <math.h>

int main()
{

  double total,x,n,i;
  printf("enter a number for factors of root 2\n");
  scanf("%lf",&n);

  total=2;
  x=sqrt(2);
 i=0;

  while(i<n){
    total=total*2/x;
    x=(sqrt(2+x));
    i=i+1;
  }
 
 
  printf("%lf",total);
}
