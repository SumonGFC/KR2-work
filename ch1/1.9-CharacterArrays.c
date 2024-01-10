/*Write a program that reads a set of text lines and prints the longest */

#include <stdio.h>
#define MAXLINE 1000

/*
 * 1. write function get_line() that fetches the next line of input;
 *      - return length of line or 0 if input reaches EOF
 * 2. write function copy() that saves a copy of a longer line if it is found
 */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int prev_max_len, curr_len;
    char curr_line[MAXLINE], longest_line[MAXLINE]; 

    prev_max_len = 0;
    while ((curr_len = get_line(curr_line, MAXLINE)) > 0) {
        if (curr_len > prev_max_len) {
            prev_max_len = curr_len;
            copy(longest_line, curr_line);
        }
    }
    
    if (prev_max_len > 0) {
        printf("%s", longest_line);
    }

    return 0;
}

int get_line(char s[], int line_limit) {
    //Read line into s, return its length

    int c, i;

    for (i = 0; i<line_limit-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    //copy 'from' into 'to; assume 'to' is big enough

    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
