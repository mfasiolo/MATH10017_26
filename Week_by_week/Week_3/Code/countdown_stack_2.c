#include <stdio.h>

void countdown(int n)
{

    printf("enter countdown(%d)\n", n);

    if (n <= 0) {
        printf("base case\n");
    } else {
        printf("%d\n", n);

        // Watch the CALL STACK grow.
        countdown(n - 1);
    }

    // Watch frames disappear in the order 0, 1, 2, 3.
    printf("leave countdown(%d)\n", n);
}

int main(void)
{
    countdown(3);

    // All countdown frames are now gone. 
    return 0;
}

