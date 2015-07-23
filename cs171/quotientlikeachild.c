//inclass assignment 9/24/14
#include <stdio.h>
#include <math.h>

int main()
{

  double a,b,q;
  printf("please enter two numbers");
  scanf("%lf %lf",&a,&b);
  q=0;
  while(a>=b){;
    a=a-b;
    q=q+1;
  };
  printf("%lf is the quotient, and %lf is the remainder",q,a);

}
