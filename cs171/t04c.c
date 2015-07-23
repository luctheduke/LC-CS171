
#include <FPT.h>   

int main()
{
  double swidth, sheight ;
  double x0,x1,y0,y1,xm,ym,xa,ya,i,n,t;
  double z[2];
  printf("eneter a number");
  scanf("%lf", &n);


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


  G_rgb(0.5,0.5,0.5);
  G_line(x0,y0,x1,y1);
 

  i=0;t=0;
  while(i<=n){
    t=i/n;
    G_rgb(1,0,0);
    xa=x0+t*(x1-x0);
    ya=y0+t*(y1-y0);
    G_fill_circle(xa,ya,5);
    G_wait_key();
    i++;
  }

 G_wait_key();
  
}
