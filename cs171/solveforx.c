//slove for ax^2+bx+c=0 for x when given b,c;worked with Keziah;
#include <stdio.h>
#include <math.h>

int main()
{

  double a,b,c,x,y;
  printf("Please enter a,b,and c");
  scanf("%lf %lf %lf",&a,&b,&c);

 if((a==0)&&(b==0)){printf("no solution\n");}

 else if(a==0){x=-c/b;   
   if((b==0)&&(c!=0)){printf("no solution\n");}
else if((b==0)&&(c==0)){printf("Anything Goes\n");}
 else printf("x=%lf\n",x);}

 else if((a==0)&&(b==0)&&(c==0)){printf("anything works\n");}
 else if(((b*b)-(4*a*c))<0){printf("no real solution\n");}
 else {x = (((b*-1)+(sqrt((b*b)-(4*a*c))))/(2*a));
             y = (((b*-1)-(sqrt((b*b)-(4*a*c))))/(2*a));
             printf("x=%lf\nx=%lf\n",x,y);}

}

