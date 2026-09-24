#include <stdio.h>

double square(double a){
    return a*a;
}

int main(void){

  double a = 2; 
  printf("%f \n", square(square(a))); 
           
  return 0;
}