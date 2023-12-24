#include <stdio.h>

int main() {
    char c;
    long whitespace_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ')
            ++whitespace_count;
    }
    printf("Number of White Space chars: %ld", whitespace_count);
    return 0;
}