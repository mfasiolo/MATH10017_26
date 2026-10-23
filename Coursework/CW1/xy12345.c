/* MATH10017 Assessed Coursework 1 (2026/27) -- TEMPLATE SOLUTION FILE
 *
 * Rename this file using your UoB username, e.g. ab12345.c
 *
 * Compile with:   gcc -Wall -o cw1 xy12345.c
 * Run with:       ./cw1
 *
 * Keep the file "image_data.h" in the same folder as this file.
 * It defines NROW, NCOL and the array IMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

#include "image_data.h"

/* ------------------------------------------------------------------ */
/* Part I                                                             */
/* ------------------------------------------------------------------ */

/* Task 1 */
int idx(int i, int j, int ncol){
    /* YOUR CODE HERE */
}

/* Task 2 */
char pixel_char(int v){
    /* YOUR CODE HERE */
}

/* Task 3 */
void print_image(int img[], int nrow, int ncol){
    /* YOUR CODE HERE */
}

/* ------------------------------------------------------------------ */
/* Part II                                                            */
/* ------------------------------------------------------------------ */

/* Task 4 */
void minmax(int img[], int n, int *mn, int *mx){
    /* YOUR CODE HERE */
}

/* Task 5a */
void invert(int img[], int n){
    /* YOUR CODE HERE */
}

/* Task 5b */
void flip_h(int img[], int nrow, int ncol){
    /* YOUR CODE HERE */
}

/* ------------------------------------------------------------------ */
/* Part III                                                           */
/* ------------------------------------------------------------------ */

/* Task 6 */
int *blur(int img[], int nrow, int ncol){
    /* YOUR CODE HERE */
}

/* Task 7 */
int *blur_k(int img[], int nrow, int ncol, int k){
    /* YOUR CODE HERE */
}

/* ------------------------------------------------------------------ */
/* main                                                               */
/* ------------------------------------------------------------------ */

int main(void){

    /* YOUR CODE HERE
     *
     * Use main to demonstrate that each of your functions works, in the
     * order in which the tasks are listed in the coursework sheet.
     * Print a short heading before each result, so that your output is
     * easy to read, for example:
     *
     *     printf("=== Task 4: minmax ===\n");
     *
     */

    return 0;
}
