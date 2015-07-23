// extract the hundreds digit from a number
#include <stdio.h>
#include <math.h>

int main()
{
  double n, h ;
  
  printf("Enter a number : ") ;
  scanf("%lf",&n) ;
  h = fabs(n) ; // see what goes wrong if you don't do this
  h = floor(h/100) ;
  h = fmod(h,10) ;
  printf("The hundreds digit of %lf is %lf\n",n,h) ;
}



