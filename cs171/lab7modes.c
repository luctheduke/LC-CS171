//lab7 worked with Lars;

#include <stdio.h>
#include <math.h>

int main(){

double x[1001],max;
int i,n;


i=0;

while(i<=1000){
	x[i]=0;
	i=i+1;
}

printf("Enter numberrrr");
scanf("%d", &n);

while(n>0){
x[n]= x[n]+1;
scanf("%d", &n);
}

i=0;
max=x[i];

while(i<=1000){
	if(x[i]>max){
		max=x[i];
	}
	i++;
}

i=0;
while(i<=1000){
	if(max==x[i]){printf("%d\n", i);}
	i++;
}

}