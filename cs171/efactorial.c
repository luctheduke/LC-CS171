//e by factorials (e=1+1/1!+1/2!+1/3!+1/4!+...+1/n!)
#include <stdio.h>
#include <math.h>

int main()
{
  double p,e,f,n,i,x;

  printf("please enter two numbers to approximate e");
  scanf("%lf %lf", &x &n);

  p=1;
  f=1;
  e=1;
  i=1;

  while(i<=n){
    p=p*x;
    f=f*i;
e=e+(p/f);
    i=i+1;
  }

  printf("%lf\n", e);
  
}
