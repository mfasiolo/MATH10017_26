#include <stdio.h>

int main(void){

 int i = 1;

 while(i < 10){
      if(i % 2 == 0){
          continue; 
      }
      printf("%d ", i);
      i = i + 1;
  }

 return 0;
}