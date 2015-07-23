#include <stdio.h>
#include <math.h>

int main()
{
  double x;
  printf("Please enter a positive whole integer");
  scanf("%lf",&x);

  if(x==1){printf("one\n");}
  else if(x==2){printf("two\n");}
  else if(x==3){printf("three\n");}
  else      {printf("big\n");}

  printf("bye\n");

}
