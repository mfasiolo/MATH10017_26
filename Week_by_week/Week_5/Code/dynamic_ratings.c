#include <stdio.h>
#include <stdlib.h>

double *compute_ratings(int n){

 double *ratings = malloc(n * sizeof(double));
 
 for (int i = 0; i < n; i = i + 1) {
        
        ratings[i] = 2.5 + 0.5 * i;
        
        printf("ratings[%d] = %.1f\n", i, ratings[i]);

    }

 return ratings;

}

int main(void)
{
    int count;

    printf("How many ratings? ");
    scanf("%d", &count);
  
    // Notice that compute_ratings returns an address, and the dynamically
    // allocated array remains available in main.
    double *r = compute_ratings(count);

    double total = 0.0;
    for(int i = 0; i < count; i = i + 1){
     total = total + r[i];
    }

    printf("mean rating = %.2f\n", total / count);

    // The allocation is invalid immediately after this call.
    free(r);

    return 0;
}
