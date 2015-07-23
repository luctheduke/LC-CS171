// midtermretake problem 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

double numerator, denominator, n, a, harmonicsum, sign;

printf("please enter a number");
scanf("%lf", &n);

sign=1;
numerator=0;
denominator=0;
harmonicsum=0;
a=1;

while(a<=n){
numerator=numerator+sign*1/a;
denominator=denominator+1/a;
harmonicsum=harmonicsum+sign*numerator/denominator;
sign=-sign;
a++;
}
printf("%lf\n", harmonicsum);

}

