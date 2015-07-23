//Does the first number show up again?

#include <stdio.h>
#include <math.h>

int main()
{
  double a,x,b;
  printf("enter number");
  scanf("%lf",&x);
  a=0;
  b=0;
  while(a>=0)
{scanf("%lf",&a);
    if(x==a)
      {b=b+1;
      }
 }
  if(b>0){printf("yes\n");
  }
  else{printf("no\n");
  }
}
