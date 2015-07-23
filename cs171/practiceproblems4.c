// practiceproblems4.c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

double x[1000],s,b;
int n,i,r;

printf("please enter a number");
scanf("%d", &n);

i=0;
while(n>=0){
x[i]=n;
i++;
scanf("%d", &n);
}



s=0;b=0;i=i-1;
while(i>=0){
if(s>x[i]){b++;break;}
s=x[i]+s;
i=i-1;
}



if(b==1){printf("no\n");}
else{printf("yes\n");}
}
