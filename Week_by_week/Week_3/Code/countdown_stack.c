#include <stdio.h>

void countdown(int n)
{
    // Each call has its own value of n.
    printf("enter countdown(%d)\n", n);

    if (n <= 0) {
        printf("base case\n");
    } else {
        printf("%d\n", n);

        countdown(n - 1);
    }

    printf("leave countdown(%d)\n", n);
}

int main(void)
{
    countdown(3);

    return 0;
}

