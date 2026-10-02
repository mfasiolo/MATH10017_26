#include <stdio.h>

int sum_to(int n)
{
    printf("enter sum_to(%d)\n", n);

    if (n <= 0) {
        printf("leave sum_to(0), returning 0\n");
        return 0;
    }

    int smaller_sum = sum_to(n - 1);
    int result = n + smaller_sum;

    printf("leave sum_to(%d), returning %d\n", n, result);
    return result;
}

int main(void)
{
    int answer = sum_to(3);

    printf("sum_to(3) = %d\n", answer);

    return 0;
}
