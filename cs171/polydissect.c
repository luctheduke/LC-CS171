#include <FPT.h>
int main(){

double x[100],y[100],t,j;
int i,a,n;
printf("please enter a number");
scanf("%d",&n);

G_init_graphics(600,600);

j=0;
while(j<100){
 i=0;t=0;
  while(i<n){
    t=i*2*M_PI/n;
    x[i]=300*cos(t+j)+300;
    y[i]=300*sin(t+j)+300;
    G_line(300,300,x[i],y[i]);
    i++;
  }

i=0;a=1;
while(i<n){
G_line(x[i],y[i],x[a],y[a]);
i++;
a++;	
if(a==n){a=0;}
}

i=0;a=1; 
while(i<n){
	if(i==0){G_rgb(0,0,0);}
	else if(i==1){G_rgb(.7,.7,.7);}
	else{G_rgb(pow(i,-1),pow(i,-1),pow(i,-1));}
G_fill_triangle(300,300,x[i],y[i],x[a],y[a]);
a++;
i++;
if(a==n){a=0;}
}
G_wait_key();
G_rgb(1,1,1);
G_clear();
j++;
}
G_wait_key();
}