// Write program that prints its input one word per line


#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    char state, c;
    
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else {
            state = IN;
            putchar(c);
        }
    }
    
    return 0;
}
