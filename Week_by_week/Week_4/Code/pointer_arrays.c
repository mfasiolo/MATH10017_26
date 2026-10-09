#include <stdio.h>

int main(void)
{
    int values[ ] = {2, 3, 4};
    int *p = values;

    int length = 3;

    // In this expression, values becomes &values[0].
    printf("values:     %p\n", (void *)values);
    printf("&values[0]: %p\n", (void *)&values[0]);
    printf("p:          %p\n", (void *)p);

    for (int i = 0; i < length; i = i + 1) {
        // Compare all three value expressions.
        printf("i = %d: values[i] = %d, p[i] = %d, *(p+i) = %d\n",
               i, values[i], p[i], *(p + i));

        // p + i and &values[i] are the same address.
        printf("        p+i = %p, &values[i] = %p\n",
               (void *)(p + i), (void *)&values[i]);
    }

    // The pointer advances by one int element, not one byte.

    return 0;
}

