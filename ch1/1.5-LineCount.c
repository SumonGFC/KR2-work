#include <stdio.h>

int main() {
    long line_count = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == 10) // equiv to: if (c == '/n')
        /*SINGLE-QUOTES: represent an INTEGER value equal to the numeric 
        (decimal) value of the character in the machine's character set*/
            ++line_count;
    }
    printf("Number of lines: %ld", line_count);
    return 0;
}

/*
Important:
'/n' -- represents the value of the character constant (i.e. 10 in ascii) in the currnet character set
"/n" -- represents the actual newline character, to be interpreted as a newline when processed
*/