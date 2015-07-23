#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){


double x,y,z,d,p,incylinder,incone;
int i;

i=0;incylinder=incone=0;

while(i<1000000){
x=2*drand48()-1;
y=2*drand48()-1;
z=2*drand48();



d=sqrt(x*x+y*y);
if(d<1){incylinder++;
if(z/d>2){incone++;
}
}
//(z/d) simulates the slope of a line; and the slope of the outside line of the cylinder is 10

i++;
}

p=incylinder/incone;
printf("%lf\n", p);







}
