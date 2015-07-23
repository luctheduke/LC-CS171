//low mid high; square root(10/3/14); WRONG...

#include <stdio.h>
#include <math.h>

int main()
{
  double x,low,mid,high;

  printf("please enter a number to be square rooted");
  scanf("%lf", &x);

  low=0;
  high=x+1;

  while((mid*mid)<(x-.000000001)||(
	mid*mid)>(x+.0000000001)){
	mid=(low+high)/2;

	  if((mid*mid)>x ){high=mid;}
      else{low=mid;}
	
       
    }
  printf("%lf", mid);

  
}
