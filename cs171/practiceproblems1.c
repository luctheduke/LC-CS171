#include <stdio.h>
#include <math.h>

int main(){

double thing, n, sign;


n=1000;thing=1;sign=1;

while(n>1){

thing=(n-1)+(sign*n/thing);

sign=-sign;
n=n-1;
}

printf("%lf\n", thing);

}