#include <stdio.h>
#include <math.h>

int main(){

	int n,i,thing;


n=1;thing=0;
for(i=0;i<10;i++){
thing=thing+n;
printf("thing= %d\n", thing);
n=n+n;
printf("n= %d\n", n);
}


}