#include <stdio.h>
#include <math.h>

int main()
{

  double smallest,largest,midrange,x;
  printf("enter a number");
  scanf("%lf",&x);
  largest=x;smallest=x;
  while(x>=0){
    if(x>largest){largest=x;}
    if(x<smallest){smallest=x;}
    scanf("%lf",&x);}
  midrange=(smallest+largest)/2;
  printf("midrange");

}
