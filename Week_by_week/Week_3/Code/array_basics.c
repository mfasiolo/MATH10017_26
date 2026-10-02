#include <stdio.h>

int main(void)
{
    
    double a[ ] = {1.0, 2.0, 3.0};
    double b[ ] = {2.0, 3.0, 4.0};
    double c[ ] = {0.0, 0.0, 0.0};

    int length = 3; // Use a constant to represent the length of the array.

    // An array has one name but several indexed elements.
    // In the debugger, expand a, b and c in the Variables panel.

    for (int i = 0; i < length; i = i + 1) {
        // Step Over and watch one element of c change on each iteration.
        c[i] = a[i] + b[i];
    }

    for (int i = 0; i < length; i = i + 1) {
        printf("c[%d] = %.1f\n", i, c[i]);
    }

    // c now contains 3, 5, 7. 
    return 0;
}

