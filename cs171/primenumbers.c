//inclass assignment 9/26/14 #1; prime numbers; copy of Jeff's way
#include <stdio.h>
#include <math.h>

int main()
{

  double n,d,r,f;
  printf("please enter a positive intiger");
  scanf("%lf", &n);
  d=2;
  f=0;
  while(d<n)&&(n==0){
    r=fmod(n,d);
    if(r==0){f=1;}
    d=d+1;
  }
  if(f==0){printf("yes\n");}
  else{printf("no\n");}

}
