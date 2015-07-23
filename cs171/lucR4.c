#include <stdio.h>
#include <math.h>

int main(){

double x[100],y[100],s,n;
int a,i,r;

for(i=1;i<100;i++){x[i]=0;y[i]=0;}

printf("enter a number");
scanf("%lf", &n);

i=1;r=1;
while(n!=0){
if(n>0){x[i]=n;i++;scanf("%lf", &n);}
else if(n<0){y[r]=n;r++;scanf("%lf",&n);}
}

a=0;
while(a<i&&a<r){
s=s+x[a]*y[a];
a++;
}

printf("%lf\n", s);

}