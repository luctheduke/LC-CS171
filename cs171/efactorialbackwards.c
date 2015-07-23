//e by factorials (e=1+1/1!+1/2!+1/3!+1/4!+...+1/n!)
#include <stdio.h>
#include <math.h>

int main()
{
  double a,f,n;

  printf("please enter a number to approximate e");
  scanf("%lf", &n);

  f=1;
  a=1/f;

  while(n>=1){
    f=f*n;
    printf("%lf",f);
    a=(1/f)+a;
 
  }

  printf("%lf", a);
  
}
