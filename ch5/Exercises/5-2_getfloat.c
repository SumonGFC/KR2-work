/* Exercise 5-2. Write getfloat, the floating-point analog of getint. What type
 * does getfloat return as its function value? */

#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getfloat(double *s);

int main(void)
{
        int n, getfloat(double *); 
        double array[SIZE];

        for (n = 0; n < SIZE && (getfloat(&array[n]) != EOF); n++)
                printf("array[%d] = %.8g\n", n, array[n]);
        return 0;
}


int getch(void);
void ungetch(int);

int getfloat(double *s)
{
        int c, sign, exp;
        // skip whitesapce
        while (isspace(c = getch()))
                ;
        // return if invalid
        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);
                return 0;
        }
        sign = (c == '-') ? -1 : 1;
        // determine valid '+' or '-' number
        if (c == '+' || c == '-') {
                c = getch();
                if (!isdigit(c) || c != '.') {
                        (sign == -1) ? ungetch('-') : ungetch('+');
                        ungetch(c); // if c == EOF, push it back to read later
                        return 0;
                }
        }
        // collect integral 
        for (*s = 0; isdigit(c); c = getch())
                *s = 10.0 * (*s) + (c - '0');
        // collect fractional
        if (c == '.') {
                c = getch();
                for (exp = 0; isdigit(c); c = getch(), exp++)
                        *s = 10.0 * (*s) + (c - '0');
        }
        // divide out fractional part
        for (; exp > 0; --exp)
                *s /= 10;
        // return valid float
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
