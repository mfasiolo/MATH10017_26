#include <stdio.h>

struct student {
    int id;
    int year;
    double mark;
};

void print_student(struct student s)
{
    printf("Student %d: year %d, mark %.1f\n",
           s.id, s.year, s.mark);
}

int main(void)
{
    struct student matteo;
    matteo.id = 1024;
    matteo.year = 1;
    matteo.mark = 70.0;

    struct student ada = {2048, 2, 64.5};

    print_student(matteo);
    print_student(ada);

    return 0;
}
