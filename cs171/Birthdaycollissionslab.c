//lab due Wed Nov, 19 2016
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

double x[366],yes,collissions,probs,y;
int i,n,r;

i=1;
while(i<=365){
x[i]=0;
i++;
}

printf("input a number");
scanf("%lf", &y);

r=0;collissions=0;
while(r<=1000000){
i=1;yes=0;
while(i<=y){
n=floor(365*drand48()+1);
x[n]=x[n]+1;
if(x[n]>=2){yes++;break;}
i++;
}
if(yes>0){collissions++;}
i=1;
while(i<=365){
x[i]=0;
i++;
}
r++;
}

probs=collissions/r;

printf("%lf\n", probs);
}


