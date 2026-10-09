#include <stdio.h>

int get_row_major(const int values[], int i, int j, int ncol)
{
    int index = i * ncol + j;

    return values[index];
}

int get_column_major(const int values[], int i, int j, int nrow)
{
    int index = j * nrow + i;

    return values[index];
}

void print_row_major(const int values[], int nrow, int ncol)
{
    for (int i = 0; i < nrow; i = i + 1) {
        for (int j = 0; j < ncol; j = j + 1) {
            printf("%d ", get_row_major(values, i, j, ncol));
        }
        printf("\n");
    }
}

int main(void)
{
    int nrow = 2;
    int ncol = 3;

    int row_major[] = {1, 2, 3, 4, 5, 6};
    int column_major[] = {1, 4, 2, 5, 3, 6};

    int from_rows = get_row_major(row_major, 1, 0, ncol);
    int from_columns = get_column_major(column_major, 1, 0, nrow);
    
    // Both answers are 4, but the flat indices differ.
    printf("A[1,2] from row-major storage = %d\n", from_rows);
    printf("A[1,2] from column-major storage = %d\n", from_columns);

    // Both arrays represent the same 2 by 3 matrix.
    print_row_major(row_major, nrow, ncol);

    return 0;
}
