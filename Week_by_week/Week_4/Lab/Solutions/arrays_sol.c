#include <stdio.h>

double maximum(const double values[], int length)
{
    double largest = values[0];

    for (int i = 1; i < length; i = i + 1) {
        if (values[i] > largest) {
            largest = values[i];
        }
    }

    return largest;
}

void swap_first_two(double values[], int length)
{
    if (length >= 2) {
        double temporary = values[0];
        values[0] = values[1];
        values[1] = temporary;
    }
}

void print_matrix(const int values[], int nrow, int ncol)
{
    for (int i = 0; i < nrow; i = i + 1) {
        for (int j = 0; j < ncol; j = j + 1) {
            printf("%d ", values[i * ncol + j]);
        }
        printf("\n");
    }
}

int main(void)
{
    double values[] = {2.0, 1.0, 3.0, 4.0, 3.0};
    printf("Maximum: %.1f\n", maximum(values, 5));

    double pair[] = {1987.0, 10.0};
    swap_first_two(pair, 2);
    printf("After swapping: %.1f %.1f\n", pair[0], pair[1]);

    int matrix[] = {1, 2, 3, 4, 5, 6};
    print_matrix(matrix, 3, 2);

    return 0;
}
