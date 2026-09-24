#include <stdio.h>

int main(void){
    int n = 100;
    int checks = 0;

    printf("Algorithm 1: check every possible factor\n");
    printf("Primes: ");

    for(int i = 1; i <= n; i++){
        int numfactor = 0;

        for(int j = 1; j <= i; j++){
            checks = checks + 1;

            if(i % j == 0){
                numfactor = numfactor + 1;
            }
        }

        if(numfactor == 2){
            printf("%d ", i);
        }
    }

    printf("\nDivisibility checks: %d\n\n", checks);

    checks = 0;

    printf("Algorithm 2: stop after the third factor\n");
    printf("Primes: ");

    for(int i = 1; i <= n; i++){
        int numfactor = 0;

        for(int j = 1; j <= i; j++){
            checks = checks + 1;

            if(i % j == 0){
                numfactor = numfactor + 1;

                if(numfactor > 2){
                    break;
                }
            }
        }

        if(numfactor == 2){
            printf("%d ", i);
        }
    }

    printf("\nDivisibility checks: %d\n\n", checks);

    checks = 0;

    printf("Algorithm 3: check only up to the square root\n");
    printf("Primes: ");

    for(int i = 2; i <= n; i++){
        int is_prime = 1;

        for(int j = 2; j * j <= i; j++){
            checks = checks + 1;

            if(i % j == 0){
                is_prime = 0;
                break;
            }
        }

        if(is_prime == 1){
            printf("%d ", i);
        }
    }

    printf("\nDivisibility checks: %d\n", checks);

    return 0;
}
