
#include<stdio.h>
#include<time.h>


int main(void)
{   
    clock_t start = clock();
    int n = 5000, num_primes = 0; 
    for(int i = 2; i<= n; i++){
        int num_factors = 0;
        for(int j = 1; j <= i; j++){
            if (i % j ==0){
                num_factors ++; 
            }
        }
        if (num_factors == 2){
            // printf("%d\n", i);
            num_primes ++; 
        }
    }

    printf("total num of primes: %d\n", num_primes);
    clock_t end = clock();
    clock_t t = end-start; 
    printf ("It took me %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    
    return 0;
}
