/*Revise main routine to correctly print the length of arbitrarily long input lines,
 * and as much as possible of the text*/

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int curr_len;               //current line length
    int prev_max_len;           //max length seen so far
    char curr_line[MAXLINE];    //current input line
    char longest_line[MAXLINE]; //longest line saved here

    prev_max_len = 0;
    while ((curr_len = get_line(curr_line, MAXLINE)) > 0) {
        printf("%d: %s", curr_len, curr_line);
        if (curr_len > prev_max_len) {
            prev_max_len = curr_len;
            copy(longest_line, curr_line);
        }
    }
    
    if (prev_max_len > 0) {
        printf("longest line is %d chars: %s", prev_max_len, longest_line);
    }

    return 0;
}

int get_line(char s[], int line_limit) {
    //Read line into s, return its length

    int c, i;

    for (i = 0; i<line_limit-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;


    //new stuff
    if (i == line_limit - 1) {
        s[i] = '\0';
        while ((c = getchar()) != EOF && c != '\n')
            ++i;

    } else {
        if (c == '\n') {
            s[i] = c;
            ++i;
        }
        s[i] = '\0';
    }

    return i;
}

void copy(char to[], char from[]) {
    //copy 'from' into 'to; assume 'to' is big enough

    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
