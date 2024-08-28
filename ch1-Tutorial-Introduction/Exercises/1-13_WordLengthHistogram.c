//Write program to print a horizontal histogram of the lengths of words in input
//For simplicity, we will limit the length of a word to 20 characters
//We will define a word as a contiguous sequence of non-white-space characters

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LETTERS 20

int main() {
    char c, prev_state;
    int i, j, word_length, num_words[MAX_LETTERS];

    for (i = 0; i <= MAX_LETTERS; ++i)
        num_words[i] = 0;

    prev_state = OUT;
    word_length = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')    
            if (prev_state == IN) {
                prev_state = OUT;
                ++num_words[word_length];
                word_length = 0;
            } 
            else
                ++num_words[word_length];
        else
            ++word_length;
            if (prev_state == OUT) {
                prev_state = IN;
            }
    }

    for (i = 0; i <= MAX_LETTERS; ++i){
        printf("%2d: ", i);
        for (j = 0; j < num_words[i]; ++j)
            printf("x");
        printf(" (%d)\n", num_words[i]);
    }


    return 0;
}
