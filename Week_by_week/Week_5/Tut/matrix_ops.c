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

/*
Optional challenge: allocate and calculate A raised to a non-negative power.

On success, store the result in *result and return 1. matrix_power allocates
result->elements, so the calling function must free it after use. Return 0 if
the input is invalid or an allocation fails.
*/
int matrix_power(struct matrix A, int power, struct matrix *result)
{
    // TODO 8: check that result is valid, A is square and power is non-negative.

    // TODO 9: allocate and initialise current as an identity matrix.

    // TODO 10: repeatedly allocate next, multiply, and release the old current.

    // TODO 11: store current in *result and return success.
    return 0;
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

    /*
    Optional challenge: after completing matrix_power, remove these comment
    markers to test it.

    int q_values[] = {1, 1, 1, 0};
    struct matrix Q = {2, 2, q_values};
    struct matrix Q5;

    if (matrix_power(Q, 5, &Q5)) {
        printf("\nQ to the power 5:\n");
        print_matrix(Q5);
        free(Q5.elements);
    } else {
        printf("Could not calculate the matrix power.\n");
    }
    */

    return 0;
}
