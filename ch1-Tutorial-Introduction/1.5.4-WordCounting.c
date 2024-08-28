// Count lines, words, and characters in input
#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    int c, num_lines, num_words, num_chars, state;
    
    state = OUT;
    num_lines = (num_words = (num_chars = 0));

    while ((c = getchar()) != EOF) {
        ++num_chars;
        if (c == '\n') {
           ++num_lines;
        }
        if (c == ' ' || c == '\n' || c == '\t')
           state = OUT;
        else if (state == OUT) {
            state = IN;
            ++num_words;
        }
    }
    
    printf("chars: %d, words: %d, lines: %d\n", num_chars, num_words, num_lines);
    return 0;
}
