//Sum= 1+2+3+...+n
#include <stdio.h>
#include <math.h>

int main()
{

  double n,i,s;
  printf("enter a positive whole number");
  scanf("%lf",&n);
  i=1; s=0;
  while(i<=n){;
    s=s+i;
    i=i+1;
}
  printf("%lf\n",s);

}
