#include <stdio.h>

int main(void){

   for(int i = 1; i <= 10; i = i + 1){
        printf("%d\n", i);
   }

   // Same loop but initialising and updating "manually"
   int i = 1;
   for( ; i <= 10; ){
     printf("%d\n", i);
     i = i + 1;
   }

   // How to implement i <= 10 in the body of the for() loop?
   // Use a break statement!
   i = 1;
   for( ; ; ){
     if(i > 10) break;
     printf("%d\n", i);
     i = i + 1;
   }

   return 0;
}

