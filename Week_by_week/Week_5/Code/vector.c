#include <stdio.h>

struct vector {
    int length;   // Note that int length = 3 does not work in C!
    double elements[3];
};

void print_vector(struct vector v)
{
    for (int i = 0; i < v.length; i++) {
        printf("%.2f ", v.elements[i]);
    }
    printf("\n");
}

void modify_elements(struct vector v)
{
    v.elements[0] = 99.0;
}

void modify_elements_pointer(struct vector *v)
{
    v->elements[0] = 99.0;
}

int main(void)
{
    struct vector x;
    x.length = 3;

    for (int i = 0; i < x.length; i++) {
        x.elements[i] = i + 1.0;
    }

    print_vector(x);

    modify_elements(x);

    print_vector(x);

    modify_elements_pointer(&x);

    print_vector(x);

    return 0;
}
