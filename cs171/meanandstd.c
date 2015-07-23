
#include <stdio.h>
#include <math.h>

int main()
{

  double x,c[1000],total,mean,stdtotal,std;
  int n,i;
  printf("enter a number");
  scanf("%lf",&x);

  total = 0 ;
  stdtotal=0;
  n = 0 ;

  while(x>=0){
    c[n]=x;
    total=c[n]+total;
    n=n+1;
    scanf("%lf",&x);
  }

  mean=(total/n);
  printf("%lf\n",mean);

  i = n ;
  while(i >= 1){
    i = i - 1 ;
    c[i]=mean-c[i];
    stdtotal=(c[i]*c[i])+stdtotal;
  }
  std= sqrt(stdtotal/n);
  printf("%lf\n",std);
}
