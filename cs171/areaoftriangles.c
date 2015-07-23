//inclass assignment 9/24/14 #2
#include <stdio.h>
#include <math.h>

int main()
{

  double n,a,b,c,x,A;
  printf("enter a number of triangles");
  scanf("%lf",&n);
  x=1;
  a=100;
  b=30;
  A=0;
  while(x<=n){;
    A=A+((a*b)/2);
    b=sqrt(a*a+b*b);
    x=x+1;
  }
  printf("%lf is the total area\n", A);



}
