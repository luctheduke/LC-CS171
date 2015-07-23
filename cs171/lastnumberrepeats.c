//Does the last number show up again?

#include <stdio.h>
#include <math.h>

int main()
{
  double x,m,c[1000];
  int n,i;
  printf("enter number");
  scanf("%lf",&x);
  n=0;

  while(x>=0)
{c[n]=x;   
scanf("%lf",&x);
 n=n+1;
    }

  i=0;m=0;
  while(i<n){
    if(c[i]==c[n-1]){m=m+1;}
    i=i+1;
  }
  if(m>1){printf("yes\n");}
  else{printf("no\n");}




  if(){printf("yes\n");
  }
  else{printf("no\n");
  }
}
