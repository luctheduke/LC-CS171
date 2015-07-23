#include <stdio.h>
#include <math.h>

int main(){

int i,n;
char w[100], u[100], f[100];

printf("enter two words");
scanf("%s %s", w, u);

//null code ('\0') in all slots of f
i=0;
while(i<=100){f[i]='\0';i++;}



//extracting vowels from first word 'w'; 
//placing these values into a new;
//character 'f' in the even slots (0,2,4,6,8);
i=0;n=0;
while(w[i]!='\0'){
if(w[i]=='a'||w[i]=='e'||w[i]=='i'||w[i]=='o'||w[i]=='u'){
f[n]=w[i];n=n+2;}
i=i+1;
}

//extracting consonants from second word 'u'; 
//placing these values into a new;
//character 'f' in the odd slots (1,3,5,7);
i=0;n=1;
while(u[i]!='\0'){
if(u[i]!='a'&&u[i]!='e'&&u[i]!='i'&&u[i]!='o'&&u[i]!='u'){
f[n]=u[i];n=n+2;}
i=i+1;
}

//printing the new word character 'f';
printf("%s\n",f);

}





 




