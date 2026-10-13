#include <stdio.h>

/*
 * Print F_index, F_(index + 1), ..., F_n.
 * previous is F_index and current is F_(index + 1).
 */
void print_fibonacci(int previous, int current, int index, int n)
{
    if (index > n) {
        return;
    }

    printf("%d ", previous);

    print_fibonacci(current, previous + current, index + 1, n);
}

int main(void)
{
    int n = 10;

    print_fibonacci(0, 1, 0, n);
    printf("\n");

    /*
     * The function prints n + 1 values.
     * Its time complexity is O(n) and its call stack uses O(n) space.
     */

    return 0;
}
