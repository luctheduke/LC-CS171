//write a program that finds the point closest to the origin from the graph y=x^3-2x^2+1; use loops and arrays...
#include <stdio.h>
#include <math.h>

int main(){

double c[100000],d[10000],x,y,e[10000],closest,a;
int i,n;

x=1;
i=0;

while(x>(-1)){
c[i]=x;
printf("x=%lf\n",c[i]);
x=(x-.01);
y=(x*x*x)-(2*(x*x))+1;
d[i]=y;
printf("y=%lf\n",d[i]);
i++;
}


n=i;
i=0;
while(i<n){
e[i]=sqrt((c[i]*c[i])+(d[i]*d[i]));
i++;
}



i=0;
closest=e[i];
while(i<n){
i++;
if(e[i]<closest){closest=e[i];}
}

printf("%lf", closest);
}