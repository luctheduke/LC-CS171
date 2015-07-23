#include <stdio.h>
#include <math.h>

int main(){

double b;
int i;
char w[100],u[100];

printf("enter two words");
scanf("%s %s", w, u);


i=0;
while(w[i]!='\0'){
if(('A'<=w[i])&&(w[i]<='Z')){w[i]=w[i]+'a'-'A';}
}

i=0;
while(u[i]!='\0'){
if(('A'<=u[i])&&(u[i]<='Z')){u[i]=u[i]+'a'-'A';}
}

i=0;b=0;
while((u!=0)||(w!=0)){
if(w[i]<u[i]){b=1;break;}
else if(u[i]<w[i]){b=2;break;}
else{i=i+1;}
}

if(b==0){printf("same");}
else if(b==1){printf("first word is first in dictionary");}
else{printf("second word is first in dictionary");}

}