#include <stdio.h>

int main(void)
{
    double measurements[ ] = {18.5, 20.0, 19.5};

    int length = 3;

    for (int i = 0; i < length; i = i + 1) {
        printf("measurements[%d] = %.1f\n", i, measurements[i]);
    }

    int index = length;

    printf("measurements[%d] = %.1f\n", index, measurements[index]);

    return 0;
}

