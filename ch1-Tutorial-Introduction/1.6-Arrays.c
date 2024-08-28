#include <stdio.h>

//Count digits, whitespace, others

int main() {
    char c;
    int i, num_white, num_other;
    int num_digits[10];
    
    num_white = num_other = 0;
    for (i = 0; i < 10; ++i) {
        num_digits[i] = 0;
    }

    while ((c = getchar()) != EOF)
        if (c == '\n' || c == '\t' || c == ' ')
            ++num_white;
        else if (c >= '0' && c <= '9')
            ++num_digits[c - '0'];  // The numeric value of the digit
        else
            ++num_other;

    printf("num_white: %d, num_other: %d \n", num_white, num_other);
    for (i = 0; i < 10; ++i)
        printf("%ds:%d, ", i, num_digits[i]);
    printf("\n");

    return 0;
}
