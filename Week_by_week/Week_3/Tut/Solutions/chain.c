#include <stdio.h>
#include <math.h>

// Compile with: gcc chain.c -o chain -lm

double f(double x)
{
    return sin(x);
}

double df(double x)
{
    return cos(x);
}

double g(double x, int n)
{
    if (n <= 0) {
        return x;
    }

    return f(g(x, n - 1));
}

double dg(double x, int n)
{
    if (n <= 0) {
        return 1.0;
    }

    return df(g(x, n - 1)) * dg(x, n - 1);
}

int main(void)
{
    double x = 0.4321;
    int n = 2;

    printf("g(%.4f, %d) = %.6f\n", x, n, g(x, n));
    printf("dg(%.4f, %d) = %.6f\n", x, n, dg(x, n));

    return 0;
}
