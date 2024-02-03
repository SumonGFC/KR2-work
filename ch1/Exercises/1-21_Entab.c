/* Write a program 'entab' that replaces strings of blanks by the minimum 
 * number of tabs and blanks to achieve the same spacing. Use the same tab 
 * stops as for detab. When either a tab or a single blank would suffice to 
 * reach a tab stop, which should be given preference? 
 * -- Blank gets preference */

#include <stdio.h>

#define TABSTOP 8
#define SPACE ' '
#define SPACE_PRINT '_'

int main ()
{
    int c;  //store char in here
    int i;
    int tab_pos = 0;
    int blank_len = 0;
    
    while ((c = getchar()) != EOF) {
        ++tab_pos;
        if (c != SPACE) {
            if (c == '\t')
                printf("\\t");
            else {
                for (i = 0; i < blank_len; ++i)
                    putchar(SPACE_PRINT);
                blank_len = 0;
                putchar(c);
            }
        }
        else {
            ++blank_len;
            if (tab_pos % TABSTOP == 0) {
                if (blank_len == 1)
                    putchar(SPACE_PRINT);
                else
                    printf("\\t");
                blank_len = 0;
            }
        }
    }
    return 0;
}
