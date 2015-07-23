#include <stdio.h>
#include <math.h>

int main(){


int i;
char w[100];

printf("what is your name?");
scanf("%s", w);

i=0;
while(w[i]!=0){
i=i+1;
}

printf("good morning, %s, your name has %d letters\n", w, i);
}


