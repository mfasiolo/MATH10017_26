#include <stdio.h>

struct student {
    int id;
    int year;
    double mark;
};

void change_mark(struct student s)
{
    s.mark = 99.0;
    printf("Inside the function: %.1f\n", s.mark);
}

int main(void)
{
    struct student matteo = {1024, 1, 70.0};

    printf("Before the function call: %.1f\n", matteo.mark);
    change_mark(matteo);
    printf("After the function call:  %.1f\n", matteo.mark);

    return 0;
}
