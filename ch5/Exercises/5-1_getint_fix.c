#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getint(int *array);

int main(void)
{
        int n, array[SIZE], getint(int *);
        for (n = 0; n < SIZE && (getint(&array[n]) != EOF); n++)
                printf("array[%d] = %d\n", n, array[n]);
        return 0;
}

int getch(void);
void ungetch(int);

int getint(int *s)
{
        int c, sign;

        while (isspace(c = getch()))
                ;

        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);
                return 0;
        }

        sign = (c == '-') ? -1 : 1;

        if (c == '+' || c == '-') {
                c = getch();
                if (!isdigit(c)) {
                        (sign == -1) ? ungetch('-') : ungetch('+');
                        ungetch(c); // if c == EOF, push it back to read later
                        return 0;
                }
        }

        for (*s = 0; isdigit(c); c = getch())
                *s = 10 * (*s) + (c - '0');

        *s *= sign;

        if (c != EOF)
                ungetch(c);
        return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
} 
