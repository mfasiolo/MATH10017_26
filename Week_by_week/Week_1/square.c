#include <stdio.h>

double square(double x) {
    x = x * x;
    return x;
}

int main(void) {
    double value = 2.0;
    double answer = square(value);

    printf("value = %.1f, answer = %.1f \n", value, answer);

    return 0;
}