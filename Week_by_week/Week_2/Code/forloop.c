#include <stdio.h>

int main(void){

    // [C]
    for(int i = 1; i <= 10; i = i + 1){ // [A]
        printf("%d\n", i);
    }

    // [B]
    printf("the end\n");

    return 0;
}

/* [A] This also works

   int i = 1;
   for( ; i <= 10; ){
     printf("%d\n", i);
     i = i + 1;
    }

 How to implement i <= 10 in the body of the for() loop?
 See the next lecture!
*/

/* [B] Note "i" does not exist here! It's local to the loop.
    Try adding int k = 7 after printf("%d\n", i);
*/

/*  [C] Variables declared before the loop are available within the loop.
    Try to declare a variable before the loop and modify it within the loop.
*/
