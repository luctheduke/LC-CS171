//lab2; loops to get 
#include <stdio.h>
#include <math.h>

int main()
{

  double x,y,b;
  x=1000;
  y=0;
  while(y<240){;
    x=x+300 + (.05/12)*x;
    y=y+1;
  }
  printf("%lf\n",x);
  b=x-1000-(240*300);
  printf("%lf\n",b);
}
