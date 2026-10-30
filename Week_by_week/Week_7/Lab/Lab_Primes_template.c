
#include<stdio.h>
#include<time.h>


void main(void)
{   
    time_t start = clock();
    int n = 5000, num_primes = 0;

    //TODO: write your own code here for 
    // counting the number of factors

    printf("total num of primes: %d\n", num_primes);
    time_t end = clock();
    time_t t = end-start; 
    printf ("It took me %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    
    return 0;
}
