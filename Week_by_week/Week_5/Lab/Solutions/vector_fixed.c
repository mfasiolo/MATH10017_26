#include <stdio.h>

struct vector {
    int length;
    double elements[3];
};

void print_vector(struct vector v)
{
    for (int i = 0; i < v.length; i++) {
        printf("%.2f ", v.elements[i]);
    }
    printf("\n");
}

double dot(struct vector u, struct vector v)
{
    double total = 0.0;

    for (int i = 0; i < u.length; i++) {
        total = total + u.elements[i] * v.elements[i];
    }

    return total;
}

int main(void)
{
    struct vector u;
    struct vector v;
    u.length = 3;
    v.length = 3;

    for (int i = 0; i < u.length; i++) {
        u.elements[i] = i + 1.0;
        v.elements[i] = i + 4.0;
    }

    printf("u: ");
    print_vector(u);
    printf("v: ");
    print_vector(v);
    printf("dot product: %.2f\n", dot(u, v));

    return 0;
}
