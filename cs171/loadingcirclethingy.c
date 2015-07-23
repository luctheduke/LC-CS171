#include <FPT.h>



int main(){

double x[100],y[100],t;
int i,a,j;

G_init_graphics(600,600);


j=0;
while(j<100){
i=0;t=0;
  while(i<16){
    t=i*2*M_PI/16;
    x[i]=40*cos(t+j)+300;
    y[i]=40*sin(t+j)+300;
    i++;
    G_rgb(drand48(),drand48(),drand48());
	G_fill_circle(x[i],y[i],5);
  }
  G_wait_key();
  G_rgb(1,1,1);
  G_clear();
j++;
}
}
