#include <stdio.h>
#include <ctype.h>
// This is just a collection of notes on pointers from chapter 5.

// SECTION: 5-1
int section_5_1(void)
{
        int x = 1;
        // POINTER DECLARATIONS ARE A MNEMONIC:
        int *ip;
        // this indicates that the SYMBOL, "*ip", is an int. This is similar to
        // function declarations:
        int func(void);
        // where the return type "int" is really saying that the symbol "func"
        // should be an int where it is referenced

        // VALID OPERANDS OF DEREFERENCE OPERATOR:
        // The & operator can only be applied to objects in memory (variables,
        // array elements, other pointers). It CANNOT be applied to expressions,
        // constants, or register variables.
        ip = &x;

        // REFERENCE AND DEREFERENCE, & AND *, BIND MORE TIGHTLY THAN ARITHMETIC
        // OPERATORS:
        int y = *ip + 1;        // *ip is evaluated before addition
        *ip += 1;               // dereference, THEN increment
        ++*ip;                  // dereference, THEN increment

        (*ip)++;                // parentheses are necessary here: without them,
                                // this expression would increment ip then
                                // dereference it because unary ops associate
                                // right to left (i.e. *(ip++) )

        // POINTERS ARE VARIABLES:
        int *iq;                // can assign pointers as values -- values are
        iq = ip;                // virtual addresses
                                

        return 0;
}

// SECTION: 5-2
void bad_swap(int x, int y)             // WRONG!
{
        int tmp = x;
        x = y;
        y = tmp;
}

void good_swap(int *x, int *y)          // Correct: call as good_swap(&x, &y)
{
        // pass in references to x and y, then interchange the values stored at
        // those references
        int tmp = *x;
        *x = *y;
        *y = tmp;
}

// C is pass by value (except for arrays which are essentially pointers).
// We can enable a function to access and change objects in the scope of the
// caller. 
// EXAMPLE: getint()

#define SIZE 100

int getint(int *);

void section_5_2_getint_example(void)
{
        int n, array[SIZE], getint(int *);
        for (n = 0; n < SIZE && (getint(&array[n]) != EOF); n++)
                printf("array[%d] = %d\n", n, array[n]);
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
        if (c == '+' || c == '-')
                c = getch();
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
