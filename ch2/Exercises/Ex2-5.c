/* Exercise 2-5. Write the function any(s1,s2), which returns the first
 * location in a string s1 where any character from the string s2 occurs, or -1
 * if s1 contains no characters from s2.
 */
#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "asdfghjkl";
    char s2[] = "nchftqwioklajdg";
    printf("Result should be 0: %d\n", any(s1, s2));
    return 0;
}

int any(char s1[], char s2[])
{
    int loc = -1;
    int i = 0;
    while (s2[i] != '\0') {
        int j = 0;
        while (s1[j] != '\0' && s1[j] != s2[i])
            j++;
        if (s1[j] != '\0') {
            if (j < loc || loc == -1)
                loc = j;
        }
        ++i;
    }
    return loc;
}
