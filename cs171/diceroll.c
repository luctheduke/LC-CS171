#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
double i,r,a,b,c,d,e,f;
i=1;
a=b=c=d=e=f=0;

while(i<=6000000){
r=floor(6*drand48())+1;
i++;
if(r==1){a++;}
else if(r==2){b++;}
else if(r==3){c++;}
else if(r==4){d++;}
else if(r==5){e++;}
else {f++;}
}

printf("%lf\n", a);
printf("%lf\n", b);
printf("%lf\n", c);
printf("%lf\n", d);
printf("%lf\n", e);
printf("%lf\n", f);

}
