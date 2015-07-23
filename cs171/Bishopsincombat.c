#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

double x,x1,y,y1,p,b,r;

b=0;r=0;
while(r<1000000){
x=floor(8*drand48())+1;
x1=floor(8*drand48())+1;
y=floor(8*drand48())+1;
y1=floor(8*drand48())+1;
if(fabs((y-y1)/(x-x1))==1){
b++;
}
r++;
}

p=b/r;
printf("%lf\n", p);




}