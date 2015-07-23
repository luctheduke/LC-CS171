// fmod test
// compile via :
// cc filename.c -lm

#include <stdio.h>
#include <math.h>     // notice this

int main()
{
  double a,b,f ;
  
  printf("Enter two numbers : ") ;
  scanf("%lf %lf",&a,&b) ;
  f = fmod(a,b) ;
  printf("fmod(%lf,%lf) = %lf\n",a,b,f) ;
}



