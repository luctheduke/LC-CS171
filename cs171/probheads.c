#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

double y,numsuccesses,numheads,prob;
int i,r;

i=0; numsuccesses=0;
while(i<1000000){
r=1;numheads=0;
while(r<=25){
y=floor(2*drand48());
if(y==1){numheads++;}
r++;
}
if(numheads>=10){numsuccesses++;}
i++;
}
prob=numsuccesses/i;
printf("%lf\n", prob);

}