//Write a program to print a histogram of the frequencies of different characters in its input
//We will define a character as the ASCII characters corresponding to 32-126

#include <stdio.h>

int main() {
    char c;
    int i, j, char_frequencies[99];

    for (i =  0; i < 99; ++i)
        char_frequencies[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 32 && c <= 126)
            ++char_frequencies[c - 32];
    }

    for (i = 0; i < 95; ++i) {
        putchar(i+32);
        printf(": ");
        for (j = 0; j < char_frequencies[i]; ++j)
            printf("x");
        printf("\n");
    }
    return 0;
}
