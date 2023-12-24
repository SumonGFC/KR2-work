#include <stdio.h>

// Write program that counts the characters in input
int main() {
    long char_count = 0;
    for (char_count; getchar() != EOF; ++char_count)
        /*prefix -- updates and returns modified value
        postfix -- updates variable and returns old value*/
        ; 
        /*Notice empty for loop body. C grammar requires a non-empty loop body,
        so we place just a semi-colon -- this is called a "null statement"*/
    printf("Number of Characters: %ld", char_count);
    return 0;
}