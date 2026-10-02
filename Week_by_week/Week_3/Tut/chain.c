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
    // Base case: return g_0(x).

    // Recursive case: apply f to g_(n-1)(x).
}

double dg(double x, int n)
{
    // Base case: return the derivative of g_0(x) = x.

    // Recursive case: apply the chain-rule formula from the tutorial.
}

int main(void)
{
    double x = 0.4321;
    int n = 2;

    printf("g(%.4f, %d) = %.6f\n", x, n, g(x, n));
    printf("dg(%.4f, %d) = %.6f\n", x, n, dg(x, n));

    return 0;
}
