/* Write program to copy its input to its output, replacing each tab with \t, each backspace with \b, and each backslash with \\.*/

#include <stdio.h>

int main() {
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }

    return 0;
}
