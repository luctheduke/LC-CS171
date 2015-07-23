#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
double probs,success;
int a,b,s,d,i;


success=0;
i=0;
while(i<1000000){	
a=floor(6*drand48())+1;
b=floor(6*drand48())+1;
s=a+b;
if((s==7)||(s==11)){success++;}
i++;
}

probs=success/(i);

printf("%lf\n",probs);

}