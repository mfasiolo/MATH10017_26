#include <stdio.h>

double sqrt_iter(double x, double a)
{
    return x/2 + a/(2*x);
}

int main(void){
    double a = 2;

    double guess = 1;

    for(int i = 0; i < 10; i++){
        guess = sqrt_iter(guess, a);

        // print the guess after each iteration
        printf("Iteration %d: sqrt(%.2f) = %.10f\n", i+1, a, guess);
    }

    return 0;
}
