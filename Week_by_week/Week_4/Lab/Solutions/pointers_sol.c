#include <stdio.h>

int range(const double values[], int length,
          double *minp, double *maxp)
{
    if (values == NULL || minp == NULL || maxp == NULL || length <= 0) {
      return 0;
    }


    double smallest = values[0];
    double largest = values[0];

    for (int i = 1; i < length; i = i + 1) {
        if (values[i] < smallest) {
            smallest = values[i];
        }
        if (values[i] > largest) {
            largest = values[i];
        }
    }

    // Dereferencing the output pointers updates the caller's variables.
    *minp = smallest;
    *maxp = largest;

    return 1;
}

void swap_min_max(double values[], int length)
{
    if (values == NULL || length < 2) {
        return;
    }

    double *minp = values; // or &values[0]
    double *maxp = values;
    double *current = values;

    for (int i = 1; i < length; i = i + 1) {
       current = current + i; // or &values[i]

        if (*current < *minp) {
            minp = current;
        }
        if (*current > *maxp) {
            maxp = current;
        }
    }

    // These pointers identify elements in the caller's array.
    double temporary = *minp;
    *minp = *maxp;
    *maxp = temporary;
}

void print_array(const double values[], int length)
{
    for (int i = 0; i < length; i = i + 1) {
        printf("%.2f ", values[i]);
    }
    printf("\n");
}

void swap(double *left, double *right)
{
    double temporary = *left;
    *left = *right;
    *right = temporary;
}

void bubble_sort(double values[], int length)
{
    if (values == NULL || length < 2) {
        return;
    }

    for (int pass = 0; pass < length - 1; pass = pass + 1) {
        for (int i = 0; i < length - 1; i = i + 1) {
            if (values[i] > values[i + 1]) {      
                swap(&values[i], &values[i + 1]); // or swap(values+i, values+i+1);
            }
        }
    }
}

int main(void)
{
    double observations[] = {4.2, -1.0, 3.8, 7.1, 2.4};
    int length = 5;

    double minimum;
    double maximum;

    int success = range(observations, length, &minimum, &maximum);
    
    // Question, what is the point of checking success == 1? 
    // Answer: if success == 1 then the function ran correctly and we can print
    // minimum and maximum, otherwise they are uninitialise
    if ( success == 1) {
        printf("Minimum: %.2f\n", minimum);
        printf("Maximum: %.2f\n", maximum);
    } else {
        printf("The range could not be calculated.\n");
    }

    printf("Before: ");
    print_array(observations, length);

    swap_min_max(observations, length);

    printf("After:  ");
    print_array(observations, length);

    bubble_sort(observations, length);

    printf("Sorted: ");
    print_array(observations, length);

    return 0;
}
