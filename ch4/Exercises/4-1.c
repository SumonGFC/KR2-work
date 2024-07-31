/* Exercise 4-1. Write the function strindex(s,t) which returns the position of
 * the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#define MAXLINE 1000

int str_index_rev(char line[], char pattern[]);
int rev_str(char str[], int limit);
int str_len(char str[], int limit);

int str_index_rev(char s[], char p[])
{

}

int rev_str(char s[], int lim)
{
        int i, j;
        char c;
        int len = str_len(s, lim);

        if (len == -1) {
                printf("Unterminated string\n");
                return -1;
        }

        for (j = len, i = 0; i < j; i++, j--) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
        return len;
}

int str_len(char s[], int lim)
{
        int i;
        for (i = 0; s[i] != '\0' && i < lim; i++)
                ;
        if (s[i] == '\0')
                return i;
        else
                return -1;
}
