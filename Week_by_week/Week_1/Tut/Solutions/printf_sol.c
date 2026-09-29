
#include <stdio.h>

int main(void)
{
    printf("My name is Matteo Fasiolo. \n");
    printf("I am from Italy. \n");
    printf("My student ID is mf1202. \n");
    printf("My favourite food is pasta carbonara. \n");


    printf("My Student ID %s.\n", "mf1202");
    printf("My Student ID %s%d.\n", "mf", 1202);
    printf("The outcome of 1/3 is %.3f\n", 1.0/3.0);
    // this does not work, why?
    //printf("The outcome of 1/3 is %.3f", 1/3);

    printf("|\\\n");
    printf("| \\\n");
    printf("|  \\\n");
    printf("|   \\\n");
    printf("|____\\\n");

    return 0;
}

