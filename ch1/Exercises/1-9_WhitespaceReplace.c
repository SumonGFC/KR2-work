#include <stdio.h>

/* Since the only control flow statement introduced up to this point was the 
'if' statement, nor any logical connectives, I thought it appropriate to only
use ifs and some nesting*/


//Replace any string of contiguous spaces with just a single space
int main() {
    char c, prev_c;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        if (c == ' ') 
            if (prev_c != ' ')
                putchar(c);
        if (c == ' ')
            if (prev_c == ' ')
                ;
        prev_c = c;
    }
    return 0;
}