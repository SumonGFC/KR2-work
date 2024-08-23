/*
Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.

old strcat for reference:

void strcat(char s[], char t[])
{ 
        int i, j;
        i = j = 0;
        while (s[i] != '\0')
                i++;
        while ((s[i++] = t[j++]) != '\0')
                ;
}
*/

// This seems pretty straight forward:
void str_cat(char *s, char *t)
{
        while (*s)
                s++;    // don't increment before checking for null
        while (*s++ = *t++);
}
