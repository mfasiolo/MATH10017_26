#include <stdio.h>

/*
 * Return the account balance after the requested number of years.
 * The initial deposit (year 0) is 900 pounds.
 */
double balance(int year)
{
    // Base case
    if (year <= 0) {
        return 900.0;
    }

    // Recursive call and progress toward base case
    double previous_balance = balance(year - 1);
    double interest;

    // Actual work to be done by this function
    if (previous_balance <= 1000.0) {
        interest = previous_balance * 0.05;
    } else {
        interest = 1000.0 * 0.05
                 + (previous_balance - 1000.0) * 0.02;
    }

    return previous_balance + interest;
}

int main(void)
{
    printf("Balance after 10 years: £%.2f\n", balance(10));
    return 0;
}
