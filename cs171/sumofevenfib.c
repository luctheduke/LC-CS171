#include <stdio.h>
#include <math.h>

int main(){

double a,b,f,s,n,i;



a=0;
b=1;
f=0;
s=0;
i=0;

while(f<4000000){
f=a+b;
a=b;
b=f;
i++;
if(fmod(f,2)==0){s=s+f;}
}

printf("%lf\n", s);


}	