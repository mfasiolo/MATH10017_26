#include <stdio.h>
#include <math.h> // This is needed for using the sin/cos function

// Compile with: gcc composite_funcs_sol.c -o composite_funcs_sol -lm

double f(double a, double b, double x)
{
    return sin(a*x + b);
}

double g(double outer_a, double outer_b,
         double inner_a, double inner_b, double x)
{
    double inner_value = f(inner_a, inner_b, x);
    return f(outer_a, outer_b, inner_value);
}

double f_derivative(double a, double b, double x)
{
    return a * cos(a*x + b);
}

double g_derivative(double outer_a, double outer_b,
                    double inner_a, double inner_b, double x)
{
    double inner_value = f(inner_a, inner_b, x);
    double outer_derivative = f_derivative(outer_a, outer_b, inner_value);
    double inner_derivative = f_derivative(inner_a, inner_b, x);

    return outer_derivative * inner_derivative;
}

int main(void)
{
    double outer_a = 1.0;
    double outer_b = 0.5;
    double inner_a = 0.5;
    double inner_b = 0.1;
    double x = 1.5;

    double g_value = g(outer_a, outer_b, inner_a, inner_b, x);
    double derivative_value = g_derivative(outer_a, outer_b,
                                           inner_a, inner_b, x);

    printf("g(%.1f) = %.6f\n", x, g_value);
    printf("g'(%.1f) = %.6f\n", x, derivative_value);

    return 0;
}
