//fibonaccinumbers 10/1/14

#include <stdio.h>
#include <math.h>

int main()
{

  double n1,a,b,n,f;
  printf("Enter a positive whole number");
  scanf("%lf",&n);
  a=0;
  b=1;
  n1=1;
  
  while(n>n1)
  {f=a+b;
    a=b;
    b=f;
    n1=n1+1;
}

{printf("%lf",f);}
}
