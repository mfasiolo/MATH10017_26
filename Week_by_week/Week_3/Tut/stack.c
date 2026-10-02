#include <stdio.h>
int addtwo(int a) {
    a = a + 2;
    return a;
}

int multiplytwo(int a){
    return a * 2;
}

int main(void) {
    int a = 0;
    printf("a: %d\n", a);

    addtwo(a);
    printf("a: %d\n", a);

    a = addtwo(a);
    printf("a: %d\n", a);

    a = multiplytwo(addtwo(a));
    printf("a: %d\n", a);

    a = multiplytwo(addtwo(a) / addtwo(a));
    printf("a: %d\n", a);
    return 0;
}
