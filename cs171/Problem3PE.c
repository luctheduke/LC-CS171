#include <stdio.h>
#include <math.h>

int main(){

double n,x[100];
int i,r;

for(i=0;i<100;i++){x[i]=0;}

printf("enter a number");
scanf("%lf", &n);


i=2;
while(i<n){
if(fmod(n,i)==0){
x[i]=x[i]+1; printf("%d\n", i);
}
i++;
}




}