#include <stdio.h>

double square(double x)
{
    // x is a copy. Changing it cannot change main's scalar.
    x = x * x;
    return x;
}

void add_one(double values[], int length)
{
    for (int i = 0; i < length; i = i + 1) {
        values[i] = values[i] + 1.0;
    }
}

double dot(const double a[], const double b[], int length)
{
    double total = 0.0;

    for (int i = 0; i < length; i = i + 1) {
        total = total + a[i] * b[i];
    }

    return total;
}

void vector_add(const double a[], const double b[], double output[], int length)
{
    for (int i = 0; i < length; i = i + 1) {
        output[i] = a[i] + b[i];
    }
}

int main(void)
{
    double scalar = 2.0;

    // Step into square, then check that scalar remains 2.
    double squared = square(scalar);
    printf("scalar = %.1f, squared = %.1f\n", scalar, squared);

    double a[] = {1.0, 2.0, 3.0};
    double b[] = {2.0, 3.0, 4.0};
    double c[] = {0.0, 0.0, 0.0};

    int length = 3;

    // Step into add_one and watch "a" change in both stack frames (main and add_one).
    add_one(a, length);

    // Can we modify the input arrays here?
    double product = dot(a, b, length);

    // And what about here?
    vector_add(a, b, c, length);

    printf("dot product = %.1f\n", product);
    printf("sum = %.1f %.1f %.1f\n", c[0], c[1], c[2]);

    return 0;
}
