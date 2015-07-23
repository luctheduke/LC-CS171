#include <stdio.h>
#include <math.h>

int main(){

double x, y, z, a, b;

printf("please enter two numbers");

scanf("%lf", &x);
scanf("%lf", &y);

 a=1;b=0;

 z=x+y;
z=fabs(z);

 while(a<=1000000){
 
 if(z/a>=1){b=b+1;}
 a=10*a;

 }

printf("%lf", b);

}