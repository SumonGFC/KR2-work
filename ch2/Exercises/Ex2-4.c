/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2. 
 */

// By far the simplest and most elegant solution to this problem is to re-use
// the code that K&R gives us, as this is 90% of the work already done for us.

void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}

void squeeze_all(char s1[], char s2[])
{
    int i = 0;
    while (s2[i] != '\0') {
        squeeze(s1, s2[i++]);
    }
}
