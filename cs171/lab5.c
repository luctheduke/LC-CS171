
#include <stdio.h>
#include <math.h>

int main()
{

  double k,thing, n;
  printf("enter an odd number");
  scanf("%lf",&n);
  thing=1;
  while(n>=3){
    thing=2+(n*n)/thing;
    n=n-2;
}
  k=4/(1+1/thing);
  printf("%lf",k);
}
