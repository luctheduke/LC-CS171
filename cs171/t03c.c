
#include <FPT.h>   

int main()
{
  double swidth, sheight ;
  double i,x,y,n,t ;
  double z[2] ;

  swidth = 600 ; sheight = 600 ;
  G_init_graphics(swidth, sheight);
  
 i=0;
  while(i<=300){
G_circle (300, 300, i);
     i=i+10;       
}

  i=0;t=0;
  while(i<36){
    t=i*2*M_PI/36;
    x=300*cos(t)+300;
    y=300*sin(t)+300;
    G_line(300,300,x,y);
    i++;
  }


 
  G_wait_key();
}
