#include <stdio.h>
#include <stdlib.h>

struct vector2 {
    int length;
    double *elements;
};

void print_vector2(struct vector2 v)
{
    for (int i = 0; i < v.length; i++) {
        printf("%.2f ", v.elements[i]);
    }
    printf("\n");
}

void modify_elements(struct vector2 v)
{
    v.elements[0] = 99.0;
}

int main(void)
{
    int count;
    printf("Enter a small positive length: ");
    scanf("%d", &count);

    struct vector2 x2;
    x2.length = count;
    x2.elements = malloc(x2.length * sizeof(double));

    for (int i = 0; i < x2.length; i++) {
        x2.elements[i] = i + 1.0;
    }

    print_vector2(x2);

    modify_elements(x2);

    print_vector2(x2);

    free(x2.elements);

    return 0;
}
