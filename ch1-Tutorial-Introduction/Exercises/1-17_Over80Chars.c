/*Write a program to print all input lines that are longer than 80 characters.*/

/* Read input
 * store line into char array
 * count number of non newline chars
 * if count > 80: print line
 * end execution once we read EOF */

#include <stdio.h>

#define MAXLINE 1000
#define MINLEN 81

int get_line_len(char line[], int max_line_len);

int main(void) {
    int len;                //length of current line
    char line[MAXLINE];     //current line

    while ((len = get_line_len(line, MAXLINE)) > 0) {
        if (len > 80) 
            printf("%d: %s\n", len, line);
    }

    return 0;
}

int get_line_len(char line[], int max_len) {
    /* Read input into line -- This function modifies the array line.
     * Return 0 if EOF, else Return line length */

    int c, i;

    for (i = 0; (i < max_len - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
        line[i] = c;
    }
    
    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}
