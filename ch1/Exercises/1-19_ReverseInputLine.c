/*Write a function reverses(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.*/

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverses(char from[], char to[]);

int main() {
    /*read line from input
     * while line is not EOF: print reversed line
     */

    char line[MAXLINE];
    char reversed[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        reverses(line, reversed);
        printf("%s\n", reversed);
    }
    return 0;
}

int get_line(char line[], int lim) {
    int c;      //store chars
    int i;      //line limit

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    
    return i;       //returns 0 only when getchar() reads EOF
}


void reverses(char from[], char to[]) {
    int i;
    int line_len = 0;

    while (from[line_len] != '\0')
        ++line_len;
    
    if (line_len <= 2)
        for (i = 0; i < line_len; ++i)
            to[i] = from[i];
    else {
        for (i = 0; i < line_len; ++i)
            to[line_len - i - 1] = from[i];
        to[line_len] = '\0';
    }
}
