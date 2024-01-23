/*Write a program "detab" that replaces tabs in the input with the proper 
 * number of blanks to space to the next tab stop. Assume a fixed set of tab 
 * stops, say every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

/* obv, n should be a symbolic parameter. argc and *argv[] have not been introduced 
 * yet, so it is more prudent to use #defines.*/

#define TABSTOP 4       
#define SPACES "$$$$"

int main() {
    int c;      //store char in here
    
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("%s", SPACES);
        else
            putchar(c);
    }
    return 0;
}
