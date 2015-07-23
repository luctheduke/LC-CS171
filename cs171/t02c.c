
#include <FPT.h>   

int main()
{
  double swidth, sheight ;
  double i,x,y ;
  double z[2] ;

  swidth = 600 ; sheight = 600 ;
  G_init_graphics(swidth, sheight);


  i = 0;
  while(i<600){
  G_rgb(0,0,1) ;
  G_line (i, 0, i, 599) ;
  G_line(0,i,599,i) ;
  i=i+10 ;
  }

  i=0;
  while(i<10){
  G_wait_click(z) ;
  x = z[0] ; y = z[1] ;
  x=x-fmod(x,10);
  y=y-fmod(y,10);
  G_fill_rectangle(x, y ,10,10);
  i++;
}

  G_wait_key();
}
