#include <FPT.h>


int main()
{
  int i ;
  //  double i ;
  double x[10] ;

  i = 0 ;
  while (i < 10) {
    x[i] = 100 + i ;
    i++ ;
  }


  i = 0 ;
  while (i < 10) {
    cout << x[i] << "\n" ;
    // printf("%lf\n",x[i]) ;
    i++ ;
  }

}
