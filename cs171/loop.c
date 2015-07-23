#include <stdio.h>
#include <math.h>

int main()
{

  double x,y,a,b;
  printf("enter two numbers");
  scanf("%lf %lf",&a,&b);
  x=0;y=0;
  while(y<fabs(a)){
    x=x+b;
      y=y+1;
  } 	  
if(a<0){x=-x;}
  printf("%lf\n",x);
}
