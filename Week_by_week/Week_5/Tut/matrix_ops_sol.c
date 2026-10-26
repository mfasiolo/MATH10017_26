#include <stdio.h>
#include <stdlib.h>

struct matrix {
  int nrow;
  int ncol;
  int *elements;
};

struct entry {
  int row;
  int column;
  int value;
};

int get_elem(struct matrix M, int i, int j)
{
  return M.elements[i * M.ncol + j];
}

void print_matrix(struct matrix M)
{
  for (int i = 0; i < M.nrow; i++) {
    for (int j = 0; j < M.ncol; j++) {
      printf("%d ", get_elem(M, i, j));
    }
    printf("\n");
  }
}

void multiply(struct matrix A, struct matrix B, struct matrix C)
{
  for (int i = 0; i < A.nrow; i++) {
    for (int j = 0; j < B.ncol; j++) {
      int total = 0;
      
      for (int k = 0; k < A.ncol; k++) {
        total += get_elem(A, i, k) * get_elem(B, k, j);
      }
      
      C.elements[i * C.ncol + j] = total;
    }
  }
}

/*
 Allocate and calculate A raised to a non-negative power.
 
 On success, store the result in *result and return 1. matrix_power allocates
 result->elements, so the calling function must free it after use. Return 0 if
 the input is invalid.
 */
int matrix_power(struct matrix A, int power, struct matrix *result)
{
  if (A.elements == NULL || A.nrow <= 0 || A.nrow != A.ncol || power < 0) {
    return 0;
  }
  
  struct matrix current;
  current.nrow = A.nrow;
  current.ncol = A.ncol;
  current.elements = malloc(current.nrow * current.ncol * sizeof(int));
  
  for (int i = 0; i < current.nrow; i++) {
    for (int j = 0; j < current.ncol; j++) {
      current.elements[i * current.ncol + j] = (i == j);
    }
  }
  
  for (int p = 0; p < power; p++) {
    struct matrix next;
    next.nrow = A.nrow;
    next.ncol = A.ncol;
    next.elements = malloc(next.nrow * next.ncol * sizeof(int));
    
    multiply(current, A, next);
    
    free(current.elements);
    current = next;
  }
  
  *result = current;
  return 1;
}

/*
 Answers to the matrix-power question:
 
 Multiplying two n by n matrices takes O(n^3) time. matrix_power performs that
 multiplication power times, so its time complexity is O(power * n^3). The
 O(n^2) work used to initialise the identity matrix does not change this bound.
 */


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
  
  A.elements = malloc(A.nrow * A.ncol * sizeof(int));
  B.elements = malloc(B.nrow * B.ncol * sizeof(int));
  
  for (int i = 0; i < A.nrow * A.ncol; i++) {
    A.elements[i] = a_values[i];
  }
  
  for (int i = 0; i < B.nrow * B.ncol; i++) {
    B.elements[i] = b_values[i];
  }
  
  printf("A:\n");
  print_matrix(A);
  
  printf("\nB:\n");
  print_matrix(B);
  
  struct matrix C;
  C.nrow = A.nrow;
  C.ncol = B.ncol;
  C.elements = malloc(C.nrow * C.ncol * sizeof(int));
  
  multiply(A, B, C);
  
  printf("\nA x B:\n");
  print_matrix(C);
  
  // The next two lines might look odd. I am creating a local array q_values and 
  // passing it to the initialiser list of matrix Q. This will store a pointer to the
  // first element of q_values in Q.elements. Alternatively, I could have used malloc.
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
  
  free(A.elements);
  free(B.elements);
  free(C.elements);
  
  return 0;
}
