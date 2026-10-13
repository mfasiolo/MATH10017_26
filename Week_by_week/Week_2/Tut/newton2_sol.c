#include <stdio.h>

double sqrt_iter(double x, double a){
    return x / 2 + a / (2 * x);
}

int main(void){
    double a = 2;
    double guess = 1;
    double epsilon = 0.000001;
    int iterations = 0;

    while(guess * guess < a - epsilon || guess * guess > a + epsilon){
        guess = sqrt_iter(guess, a);
        iterations = iterations + 1;
    }

    printf("sqrt(%.2f) = %.10f after %d iterations\n",
           a, guess, iterations);
    return 0;
}

// A while loop is natural because we do not know in advance
// how many iterations will be needed.
//
// If guess is zero, sqrt_iter attempts to divide by zero,
// so the algorithm cannot proceed correctly.
