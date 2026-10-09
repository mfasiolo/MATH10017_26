#include <stdio.h>

void increment(int *p)
{
    // p is local, but *p refers to the caller's integer.
    *p = *p + 1;
}

void swap(int *left, int *right)
{
    // Inspect left, right, *left and *right before stepping.
    int temporary = *left;
    *left = *right;
    *right = temporary;
}

int main(void)
{
    /*--------------      PART I     -------------------*/ 
    int x = 10;
    int *p = &x;

    // Compare p with &x, then x with *p.
    printf("address in p: %p\n", (void *)p);
    printf("address of x: %p\n", (void *)&x);
    printf("x = %d, *p = %d\n", x, *p);

    // x changes because x and *p name one object.
    *p = 25;
    printf("after *p = 25, x = %d\n", x);

    x = 10;
    printf("after x = 10, *p = %d\n", *p);

     /*--------------      PART II     ------------------*/
    // The address of x is copied into parameter p.
    increment(&x);
    printf("after increment, x = %d\n", x);

    int a = 3;
    int b = 7;

    // The caller's a and b exchange values.
    swap(&a, &b);
    printf("after swap, a = %d, b = %d\n", a, b);

    // NULL deliberately points to no object. Never dereference it.
    int *not_pointing = NULL;
    printf("null pointer: %p\n", (void *)not_pointing);

    return 0;
}

