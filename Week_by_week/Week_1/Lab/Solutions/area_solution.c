#include <stdio.h>

//write the calculate_area function below
double calculate_area(double radius){
    return 3.1415926*radius*radius;
}

//write the main function below
int main(void)
{
    printf("The area of the given circle is %.7f.\n", calculate_area(1.5));
    return 0;
}