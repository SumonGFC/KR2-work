#include <stdio.h>

// print text-stream from (std) input to (std) output
int main() {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    printf("The value of EOF on this system: %d\n", EOF);
    printf("Type something to evaluate the expression getchar() != EOF ");
    printf("evaluates to: %d\n", getchar() != EOF);
    return 0;
}