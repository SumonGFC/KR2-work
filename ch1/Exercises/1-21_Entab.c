/* Write a program 'entab' that replaces strings of blanks by the minimum 
 * number of tabs and blanks to achieve the same spacing. Use the same tab 
 * stops as for detab. When either a tab or a single blank would suffice to 
 * reach a tab stop, which should be given preference? */

#include <stdio.h>

#define TABSTOP 4
#define SPACE ' '

int main ()
{
    int c;
    int i;
    int spaces = 0;

    while ((c = getchar()) != EOF) {
        if (c != SPACE) {
            for (i = 0; i < spaces; ++i)
                putchar(SPACE);
            putchar(c);
            spaces = 0;
        } else {
            ++spaces;
            if (spaces == TABSTOP) {
                putchar('\t');
                spaces = 0;
            }
        }
    }

    return 0;
}
