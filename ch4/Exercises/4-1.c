/* Exercise 4-1. Write the function strindex(s,t) which returns the position of
 * the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#define MAXLINE 1000

int str_index_rev(char line[], char pattern[], int limit);;
int rev_str(char str[], int limit);
int str_len(char str[], int limit);

int main()
{
        char pattern[] = "ould";        // pattern to search for
        char input[] = "coulda woulda shoulda";

        printf("pattern: %s\n", pattern);
        printf("input: %s\n", input);
        printf("index: %d\n", str_index_rev(input, pattern, MAXLINE));
        return 0;
 }

int str_index_rev(char s[], char t[], int lim)
{
        int i, j, k;
        int len_t = str_len(t, lim) - 1;
        int len_s = str_len(s, lim) - 1;

        int string = rev_str(s, lim);
        int pattern = rev_str(t, lim);

        if (string == -1 || pattern == -1)
                return -1;

        for (i = 0; s[i] != '\0'; i++) {
                j = 0;
                k = i;
                while (t[j] != '\0' && s[k] == t[j]) {
                        k++;
                        j++;
                }
                
                if (j > 0 && t[j] == '\0') {
                        printf("Reversed index: %d\n", j);
                        return len_s - j;
                }
        }

        return -1;
}

int rev_str(char s[], int lim)
{
        int i, j;
        char c;
        int len = str_len(s, lim) - 1;

        if (len == -1) {
                printf("String exceeds max length (1000)\n");
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
