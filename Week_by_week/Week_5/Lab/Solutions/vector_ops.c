#include <stdio.h>
#include <stdlib.h>

void print_array(const double values[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%.2f ", values[i]);
    }
    printf("\n");
}

double dot(const double u[], const double v[], int length)
{
    double total = 0.0;

    for (int i = 0; i < length; i++) {
        total = total + u[i] * v[i];
    }

    return total;
}

int main(void)
{
    int length = 3;
    double *u;
    double *v;

    u = malloc(length * sizeof(double));
    v = malloc(length * sizeof(double));

    for (int i = 0; i < length; i++) {
        u[i] = i + 1.0;
        v[i] = i + 4.0;
    }

    printf("u: ");
    print_array(u, length);
    printf("v: ");
    print_array(v, length);
    printf("dot product: %.2f\n", dot(u, v, length));

    free(u);
    free(v);

    return 0;
}
