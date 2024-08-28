/* squeeze: delete all c from s*/

void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}


/* strcat: concatenate t to end of s; s must be big enough */

void strcat(char s[], char t[])
{
    int i,j;

    while (s[i] != '\0')
        ++i;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
