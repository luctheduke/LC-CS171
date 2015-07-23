//Does the first number show up again?

#include <stdio.h>
#include <math.h>

int main()
{
  double x,a;
  printf("enter number");
  scanf("%lf",&x);


  while(x>=0){
    scanf("%lf",a);
    if(x==a){printf("yes");}
      else{printf("no");}
    }
}
