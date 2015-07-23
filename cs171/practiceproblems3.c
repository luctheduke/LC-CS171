#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

double x[100],s,y;
int n,i,r,a;


n=0;
while(n<=100){
x[n]=0;
n++;
}


printf("enter a number");
scanf("%d", &n);

i=0;
while(n>=0){
x[i]=n;
i++;
scanf("%d", &n);
}


s=0;r=floor(i/2);
while(i>=r){
s=s+x[i];
i=i-1;
}
printf("%lf\n", s);


i=0;y=0;
while(i<r){
y=y+x[i];
i++;
}
printf("%lf\n", y);


if(y>s){printf("first half");}
else if(s>y){printf("second half");}


}







