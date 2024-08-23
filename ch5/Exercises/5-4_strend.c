// Write the function strend(s,t), which returns 1 if the string t occurs at the
// end of the string s, and zero otherwise.
// Pseudo-code:
//      advance s and t to '\0'
//      compare arrays backwards for the length of t

// gcc 5-4_strend.c && ./a.out && rm a.out

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main(void)
{
        char str[] = "asdfghjkl";       // strlen == 9
        char match[] = "ghjkl";
        char empty[] = "";
        char no_match[] = "q";
        char too_long[] = "asdfghjklasdfghjkl";

        printf("PASS (1): %d -- inputs: %s, %s\n\n", strend(str, str), str, str);
        printf("PASS (1): %d -- inputs: %s, %s\n\n", strend(str, match), str, match);
        printf("PASS (1): %d -- inputs: %s, (empty string)\n\n", strend(str, empty), str);
        printf("PASS (1): %d -- inputs: (both empty strings)\n\n", strend(empty, empty));
        printf("FAIL (0): %d -- inputs: %s, %s\n\n", strend(str, no_match), str, no_match);
        printf("FAIL (0): %d -- inputs: %s, %s\n\n", strend(str, too_long), str, too_long);

        return 0;
}

int strend(char *s, char *t)
{
        int offset = strlen(s) - strlen(t);

        if (offset < 0)
                return 0;

        s += offset;

        while (*s == *t && *s != '\0') {
                s++;
                t++;
        }

        if (*s == *t && *s == '\0')
                return 1;
        else
                return 0;
}
