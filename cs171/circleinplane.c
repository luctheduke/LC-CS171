#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

double x,y,z,d,b,a,t;
int i;

i=0;b=0;
while(i<1000000){
x=2*drand48()-1;
y=2*drand48()-1;
z=2*drand48()-1;
t=2*drand48()-1;
d=sqrt(x*x+y*y+z*z+t*t);
if(d<=1){b=b+1;}
i++;
}

a=b/i;
printf("%lf\n",a);




//it has four dimensions right now, it could easily have more or less
//If I wanted I could do a nested loop to determine how many dimensions

}	



