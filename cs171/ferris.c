#include <FPT.h>

int main(){

double x[100],y[100],t;
int i,a,j,n;

//code for the blue parts of the ferris wheel
G_init_graphics(600,600);

j=0;
while(j<120){

G_rgb(0,0,0);
G_fill_rectangle(275,275,50,50);

G_rgb(0,0,1);
G_fill_rectangle(280,280,40,40);

G_rgb(0,0,0);
G_fill_rectangle(240,20,120,20);

G_rgb(0,0,1);
G_fill_rectangle(245,25,110,10);

G_rgb(0,0,0);
G_line(275,275,240,40);
G_line(325,275,360,40);

 i=0;t=0;
  while(i<16){
    t=i*2*M_PI/16;
    x[i]=240*cos(t+j)+300;
    y[i]=240*sin(t+j)+300;
    i++;
  }

  G_fill_circle(300,300,10);


i=0;a=1;
while(i<16){
G_line(x[i],y[i],x[a],y[a]);
i++;
a++;	
if(a==16){a=0;}
}
 
 i=0;t=0;
  while(i<16){
    t=i*2*M_PI/16;
    x[i]=240*cos(t+j)+300;
    y[i]=240*sin(t+j)+300;
    G_rgb(0,0,0);
    G_line(300,300,x[i],y[i]);
    G_rgb(0,0,0);
    G_line(300,300,x[i],y[i]);
    G_rgb(0,0,0);
    G_fill_rectangle(x[i]-20,y[i]-15,40,30);
    G_rgb(drand48(),drand48(),drand48());
    G_fill_rectangle(x[i]-15,y[i]-10,30,20);
    G_rgb(0,0,0);
    G_fill_circle(x[i],y[i],5);
    i++;
}
G_wait_key();
G_rgb(1,1,1);
G_clear();

j++;

}

G_wait_key();
}






