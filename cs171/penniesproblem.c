//get pennies in other form of change
#include <stdio.h>
#include <math.h>

int main()
{
  double p,d, q,i, n, c,x;
  x=p;
  printf("how many pennies do you have?");
  scanf("%lf", &p);

 d= floor(p/100);
p= fmod(p,100);

 q=floor(p/25);
 p= fmod(p,25);

i= floor(p/10);
 p=fmod(p,10);


 n=floor(p/5);
 p=fmod(p,5);

 c=floor(p/1);
 p=fmod(p,1);

 printf("%lf pennies will get you %lf dollars, %lf quarters,  %lf dimes,  %lf nickels, %lf pennies\n",x,d,q,i,n,c); 



}
