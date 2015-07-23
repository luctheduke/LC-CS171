//LAB 4; worked with Jeff and Tyler

#include <stdio.h>
#include <math.h>

int main()
{
  double a,total,x,y,z;
  printf("enter two numbers you want russian peasants to find the product of");
  scanf("%lf %lf", &x, &y);


  total=0;

while(y>0){
z=fmod(y,2);
	  
    y=floor(y/2);
    if(z!=0){total=total+x;}

    x=x*2;
  }
 printf("%lf", total);
       
  
}
