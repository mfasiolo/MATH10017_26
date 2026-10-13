#include <stdio.h>

int main(void)
{
    double x[ ] = {2.1, 1.8, 2.4, 2.0, 1.7};
    
    const int length = 5;

    double sum = 0.0;

    for (int i = 0; i < length; i = i + 1) {
        sum = sum + x[i];
    }

    double mean = sum / length;

    int count = 0;

    for (int i = 0; i < length; i = i + 1) {
        if (x[i] > 2.0) {
            count = count + 1;
        }
    }

    printf("Sum: %.2f\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Observations greater than 2.0: %d\n", count);

    return 0;
}
