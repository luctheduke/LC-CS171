#include <stdio.h>
#include <math.h>

int main(){

double portland[150],seattle[150],p,s,a;
int i,r,n;

i=0;
while(i<=150){
portland[i]=0;
seattle[i]=0;
i++;
}
//why is it not moving to the next loop if I enter -1?
printf("enter Portland daily high temperatures");
scanf("%d", &n);

i=0;
while(n>=0){
portland[i]=n;
i++;
scanf("%d", &n);
}

printf("enter Seattle daily high temperatures");
scanf("%d", &n);

r=0;
while(n>=0){
seattle[r]=n;
r++;
scanf("%d",&n);
}

n=s=p=0;
while((n<=r)&&(n<=i)){
if(seattle[n]>portland[n]){s++;n++;}
else if(portland[n]>seattle[n]){p++;n++;}
else if(portland[n]==seattle[n]){n++;}	
}


if(p>s){printf("Portland\n");}
else if(s>p){printf("Seattle\n");}
else if(s==p){printf("Same\n");}
}	