
#include <FPT.h>   

int main()
{
  double swidth, sheight ;
  double x[37],y[37],x1[37],y1[37],n,t,b;
 int i,a;

  swidth = 600 ; sheight = 600 ;
  G_init_graphics(swidth, sheight);

    

  i=0;t=0;
  while(i<36){
    t=i*2*M_PI/36;
    x[i]=200*cos(t)+300;
    y[i]=75*sin(t)+450;
    G_circle(x[i],y[i],2);
    i++;
  }

 i=0;t=0;
  while(i<36){
    t=i*2*M_PI/36;
    x1[i]=200*cos(t)+300;
    y1[i]=75*sin(t)+150;
    G_circle(x1[i],y1[i],2);
    i++;
  }

a=0;
while(a<36){
  i=0;
  while(i<36){
    G_rgb(drand48(),drand48(),drand48());
    G_line(x[i],y[i],x1[a],y1[a]);
    i++; 
    a++;
    if(a==36){a=0;}
  }
  G_wait_key();
  G_clear();
  a++;
}

  G_wait_key();
}
