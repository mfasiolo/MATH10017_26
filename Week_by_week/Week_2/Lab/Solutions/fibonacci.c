#include <stdio.h>

int main(void){
    int n = 10;
    int previous = 0;
    int current = 1;

    printf("%d %d ", previous, current);

    for(int i = 2; i <= n; i++){
        int next = previous + current;
        printf("%d ", next);

        previous = current;
        current = next;
    }

    printf("\n");

    // The input size is n
    // The loop runs n - 1 times.
    // Its time complexity is O(n).

    return 0;
}
