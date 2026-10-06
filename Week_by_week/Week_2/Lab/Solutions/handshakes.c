#include <stdio.h>

int main(void){
    int n = 4;
    int total = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            printf("%d %d\n", i, j);
            total = total + 1;
        }
    }
    printf("Total: %d\n", total);
    // The input size is n.
    // The inner loop body runs n * (n - 1) / 2 times.
    // The time complexity is O(n^2).
    // When n doubles, the amount of work is approximately four times larger.

    return 0;
}
