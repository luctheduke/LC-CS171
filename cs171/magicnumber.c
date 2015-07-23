//lab due Mon Nov 25, 2014
//this code catches the error, early, so if it is not a magic sqaure, the square will not be printed

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

double x[100],sumrow[100],sumcolumn[100];
int a[10][10],n,row,column,i,s,b;

b=0;

i=1;
while(i<100){sumrow[i]=0;sumcolumn[i]=0;i++;}

scanf("%d", &n);

i=1;
while(i<=n*n){x[i]=0;i++;}


row=0;i=0;
while(row<n){
column=0;
while(column<n){
scanf("%d", &a[row][column]);
s=a[row][column];
x[s]=x[s]+1;
if(x[s]>1){b++;}
sumrow[i]=sumrow[i]+s;	
column++;
}
if(sumrow[i]!=sumrow[0]){b++;}
i++;
row++;
}


row=0;
while(row<n){
column=0;
while(column<n){
printf("%4d", a[row][column]);
column++;
}
printf("\n");
row++;
}


column=0;i=0;
while(column<n){
row=0;
while(row<n){
sumcolumn[i]=sumcolumn[i]+a[row][column];
row++;
}
if(sumcolumn[i]!=sumcolumn[0]){b++;}
i++;
column++;
}

if(b>0){printf("not a magic square\n");}

else{printf("this is a magic square\n");}



}

