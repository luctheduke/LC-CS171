//hundredsdigit
#include <stdio.h>
#include <math.h>
int main()
{

  double x,y,z,a,b;
  printf("type a number");
  scanf("%lf", &x);
  y=fabs(x);
  z=y/100;
  a= floor(z);
 b= fmod(a,10);
  printf("%lf", b);
}
