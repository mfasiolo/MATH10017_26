#include <stdio.h>

int main(void){

    int x = 1;
    int y = 2;

    if(y = x){
     printf("y = %d \n", y);
    }

  return 0;
}

// Here we assign the value of `x` to `y`. 
// The assignment expression evaluates to y (or "returns" the value of y).
// A hard-to-track bug!
