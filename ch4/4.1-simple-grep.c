/* Write a program to print each line of its input that contains a particular 
 * "pattern" or string of characters. (This is a special case of the UNIX 
 * programgrep.)
 */

/* Idea:
 * while (there's another line)
 *      if (line contains patter)
 *              print it
 *
 * while (there's another line) -- this is just getline() function
 * print it -- this is just printf()
 * Only need to write a function, strindex(s, t)
 */

#include <stdio.h>
#define MAXLINE 1000    // max input line length

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";        // pattern to search for

int main()
{
        char line[MAXLINE];
        int found = 0;

        while (get_line(line, MAXLINE) > 0) {
                if (strindex(line, pattern) >= 0) {
                        printf("%s\n", line);
                        found++;
                }
        }
        return found;
}

/* getline: get line into s, return length */
int get_line(char s[], int lim)
{
        int c, i;

        i = 0;
        while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
                s[i++] = c;
        }

        if (c == '\n')
                s[i++] = c;

        s[i] = '\0';
        return i;
}

/* strindex: return index of string t in string s, -1 if none */
int strindex(char s[], char t[])
{
        int i, j, k;

        for (i = 0; s[i] != '\0'; i++) {
                j = 0;
                k = i;
                while (t[j] != '\0' && s[k] == t[j]) {
                        k++;
                        j++;
                }
                
                if (j > 0 && t[j] == '\0')
                        return i;
        }

        return -1;
}
