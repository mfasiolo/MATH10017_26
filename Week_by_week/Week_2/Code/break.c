#include <stdio.h>

int main(void){

int a = 1;

 while(1){

  if(a*a + a > 321){
   
    printf("%d\n", a);

    break; // exit the while loop immediately.
   }

  a = a + 1;

 }

return 0;

}