#include <stdio.h>
#define MAXLINE 1000

int prev_max_len;           //max len seen so far
char curr_line[MAXLINE];    //current input line
char longest_line[MAXLINE]; //longest line saved here

int get_line(void);
void copy(void);

int main() {
    int curr_len;
    extern int prev_max_len;
    extern char longest_line[]; 

    prev_max_len = 0;
    while ((curr_len = get_line()) > 0) {
        if (curr_len > prev_max_len) {
            prev_max_len = curr_len;
            copy();
        }
    }
    
    if (prev_max_len > 0)           //there was a line
        printf("%s", longest_line);

    return 0;
}

int get_line(void) {
    int c, i;
    extern char curr_line[];

    for (i = 0; i< MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        curr_line[i] = c;
    if (c == '\n') {
        curr_line[i] = c;
        ++i;
    }
    curr_line[i] = '\0';
    return i;
}

void copy(void) {
    //copy 'from' into 'to; assume 'to' is big enough

    int i;
    extern char curr_line[];
    extern char longest_line[];
    
    i = 0;
    while ((longest_line[i] = curr_line[i]) != '\0')
        ++i;
}
