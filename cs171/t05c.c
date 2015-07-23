
#include <FPT.h>   

int main()
{
  double swidth, sheight ;
  double x0,x1,y0,y1,xm,ym,xa,ya,t,a,b,x[4],y[4],d,numpoints;
  double z[2];
  int i,n;

  swidth = 600 ; sheight = 600 ;
  G_init_graphics(swidth, sheight);

  G_rgb (1,0,0);
  G_wait_click(z);
  x0 = z[0] ; y0 = z[1] ;
  G_fill_circle (x0,y0,5);

  G_rgb(1,0,0);
  G_wait_click(z);
  x1 = z[0] ; y1 = z[1];
  G_fill_circle(x1,y1,5);


  a=y1-y0;
  b=x1-x0;
 G_fill_rectangle(x1,y0,a,a);
 G_fill_rectangle(x0,y0-b,b,b);
 
  x[0] = x0 ; y[0] = y0 ; 
  x[1] = x1 ; y[1] = y1 ;
  x[2] = x1-a ; y[2] = y1+b;
  x[3] = x0-a ; y[3] = y0+b ;
  numpoints = 4;
 G_fill_polygon(x,y,numpoints );
 
 G_wait_key();
  
}
