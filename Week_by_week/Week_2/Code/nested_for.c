#include <stdio.h>

int main(void){
    for (int i = 1; i <= 4; i=i+1){
        for (int j = 1; j <= 4; j=j+1){
            printf("*");
        }
        printf("\n");
    }

    return 0;

}
