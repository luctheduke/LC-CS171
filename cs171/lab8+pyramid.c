#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

int n,r,c,a,x,m;

printf("enter a numbers");
scanf("%d", &n);



r=1;x=1;m=n;
while(r<=n){

	

c=1;		
while(c<m){	
printf(" ");
c++;
}


a=0;
while(a<x){
printf("+");
a++;
}


printf("\n");

x=x+2;

m=m-1;
r++;
}


}