/*Write a program to remove trailing blanks and tabs from each line of input, and delete entirely blank lines*/

#include <stdio.h>

#define MAXLEN 1000

int get_line(char line[], int max_len);


int main(void) {
    char line[MAXLEN];
    int len;

    while ((len = get_line(line, MAXLEN)) > 0) {
        if (len > 1)
            printf("%s\n", line);
    }
    return 0;
}


int get_line(char line[], int max_len) {
    int c;          //store char from input
    int i = 0;      
    int j = 0;

    while (i < max_len - 1 && (c = getchar()) != EOF && c != '\n') {
        if (c != ' ' && c != '\t') {
            line[j] = c;
            ++j;
        }
        ++i;
    }

    if (c == '\n') {
        if (i == 0) {
            ++i;
        }
        line[j] = '\0';
    }
    return i;
}
