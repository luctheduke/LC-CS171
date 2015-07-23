//lab 3. Due tuesday September 30th, 2014; worked with Hannah DeBois


#include <stdio.h>
#include <math.h>

int main()
{

  double x,y,z;
  printf("please enter two numbers");
  scanf("%lf %lf", &x, &y);
  z=x;

  while(fmod(x,y)!=0){
   x=z+x;
  }

  if(fmod(x,y)==0)
{printf("%lf",x);}

}
