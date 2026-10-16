#include <stdio.h>
#include <stdlib.h>

struct matrix {
    int nrow;
    int ncol;
    int *elements;
};

int get_elem(struct matrix M, int i, int j)
{
    // TODO 3: return the element in row i and column j.
    return 0;
}

void print_matrix(struct matrix M)
{
    // TODO 4: print M using two nested loops and get_elem.
}

void multiply(struct matrix A, struct matrix B, struct matrix C)
{
    for (int i = 0; i < A.nrow; i++) {
        for (int j = 0; j < B.ncol; j++) {
            int total = 0;

            // TODO 5: use a loop over k to compute entry (i, j).

            C.elements[i * C.ncol + j] = total;
        }
    }
}

int main(void)
{
    int a_values[] = {1, 2, 3, 4, 5, 6};
    int b_values[] = {7, 8, 9, 10, 11, 12};

    struct matrix A;
    A.nrow = 2;
    A.ncol = 3;

    struct matrix B;
    B.nrow = 3;
    B.ncol = 2;

    // TODO 1: allocate the element arrays for A and B.

    // TODO 2: copy a_values and b_values into the allocated arrays.

    printf("A:\n");
    print_matrix(A);

    printf("\nB:\n");
    print_matrix(B);

    struct matrix C;
    C.nrow = A.nrow;
    C.ncol = B.ncol;

    // TODO 6: allocate C.elements, call multiply and print C.

    // TODO 7: release all three dynamically allocated arrays.

    return 0;
}
