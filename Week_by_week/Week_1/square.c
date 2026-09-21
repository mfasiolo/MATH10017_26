#include <stdio.h>

double square(double x) {
    x = x * x;
    return x;
}

int main(void) {
    double y = 2.0;
    double answer = square(y);

    printf("y = %.1f, answer = %.1f \n", y, answer);

    return 0;
}
