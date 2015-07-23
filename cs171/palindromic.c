
#include <stdio.h>
#include <math.h>

int main()
{

  double y,x[10000],belief;
    int n,i,k;
  printf("enter a number");
  scanf("%lf",&y);
  n=0;

  while(y>=0){
    x[n]=y;
    n=n+1;    
    scanf("%lf", &y);
  }
  i=0;
  k=n-1;
  belief=1;


  while(i<k){
    if (x[i]!=x[k]){belief=0;}
      i=i+1;
      k=k-1;
  }
  if(belief=1){printf("yes");}
  else {printf("no");}
 
}

