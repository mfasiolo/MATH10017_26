#include <stdio.h>

int max(int a, int b, int c){
    if(a < b){
        if(c > b){
            return c;
        }else{
            return b;
        }
    }else{
        if(c > a){
            return c;
        }else{
            return a;
        }
    }
}

int main(void){
    // change the line below with different values of a, b and c
    // to test your program.
    int a = 5, b = 2, c = 0;
    printf("the maximum among %d, %d, %d is %d \n", a, b, c, max(a,b,c));
    return 0;
}
