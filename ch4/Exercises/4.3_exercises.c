/* Exercise 4-3. Given the basic framework, it's straightforward to extend the
 * calculator. Add the modulus (%) operator and provisions for negative numbers.
 *
 * Exercise 4-4. Add the commands to print the top elements of the stack
 * without popping, to duplicate it, and to swap the top two elements. Add a
 * command to clear the stack.
 *
 * Exercise 4-5. Add access to library functions like sin, exp, and pow. See
 * <math.h> in Appendix B, Section 4.
 *
 * Exercise 4-6. Add commands for handling variables. (It's easy to provide
 * twenty-six variables with single-letter names.) Add a variable for the most
 * recently printed value.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define TOP '!'
#define DUP '@'
#define SWAP '#'

// declarations for main
int getop(char[]);
void push(double);
double pop(void);
// EXERCISE 4-4 (declarations)
void print_stack(void);
void top(void);
void dup(void);
void swap(void);
void clear(void);

// Reverse Polish Calculator
int main(void)
{
        int type, mod_op;
        double op2;
        char s[MAXOP];  // buffer to store characters from input

        printf("RPN Calculator: Enter Input in Reverse Polish Notation\n\n");

        while ((type = getop(s)) != EOF) {
                print_stack();
                switch(type) {
                        case NUMBER:
                                push(atof(s));
                                break;
                        case TOP:
                                top();
                                break;
                        case DUP:
                                dup();
                                break;
                        case SWAP:
                                swap();
                                break;
                        case '+':
                                push(pop() + pop());
                                break;
                        case '-':
                                op2 = pop();
                                push(pop() - op2);
                                break;
                        case '*':
                                push(pop() * pop());
                                break;
                        case '/':
                                op2 = pop();
                                if (op2 != 0.0)
                                        push(pop() / op2);
                                else
                                        printf("Error: Zero Division\n");
                                break;
                        case '%':
                                mod_op = (int)pop();
                                if (mod_op != 0)
                                        push((float)(((int)pop()) % mod_op));
                                else
                                        printf("Error: Zero Division\n");
                                break;
                        case '\n':
                                printf("\t%.8g\n", pop());
                                break;
                        default:
                                printf("Error: Unknown command %s\n", s);
                                break;
                }
        }
        printf("\nEND ");
        print_stack();
        return 0;
}

// push(): Push operand onto stack
// pop(): Pop operand from stack
#define MAXVAL 100      // max stack depth

// EXTERNAL declarations for push() and pop()
int sp = 0;
double val_stack[MAXVAL];

void push(double f)
{
        if (sp < MAXVAL)
                val_stack[sp++] = f;
        else
                printf("Error: Stack full. Can't push %g\n", f);
}

double pop(void)
{
        if (sp > 0)
                return val_stack[--sp];
        else {
                printf("Error: stack empty\n");
                return 0.0;
        }
}

void print_stack(void)
{
        int i;
        printf("STACK: ");
        for (i = 0; i < sp; i++)
                printf("%g ", val_stack[i]);
        printf("\n");
}
void top(void)
{
        // Exercise only instructs us to "print" the top, not necessarily
        // return top for future use.
        if (sp <= MAXVAL && sp > 0)
                printf("Top: %g\n", val_stack[(sp - 1)]);
        else if (sp == 0)
                printf("Stack empty\n");
        else
                printf("Error: stack pointer out of bounds\n");
}

void dup(void)
{
        push(val_stack[sp-1]);
}

void swap(void)
{
        if (sp < 2)
                printf("Can't swap: less than 2 operands on the stack\n");
        else {
                double last = val_stack[sp-1];
                val_stack[sp-1] = val_stack[sp - 2];
                val_stack[sp - 2] = last;
        }
}

void clear(void)
{
        sp = 0;
}

// getop(): get next operator or operand
#include <ctype.h>

// declarations for getop
int getch(void);
void ungetch(int);

int getop(char s[])
{
        int i, c;

        // skip leading white space and check if input char is not a number
        while ((s[0] = c = getch()) == ' ' || c == '\t')
                ;
        s[1] = '\0';

        if (!isdigit(c) && c != '.' && c != '-')
                return c;

        // collect integer (and fractional if necessary)
        i = 0;
        // EXERCISE 4-3
        if (c == '-') {
                if (!isdigit(s[++i] = c = getch()) && c != '.') {
                        if (c != EOF)
                                ungetch(c);
                        return s[0];
                }
        }

        if (isdigit(c))
                while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.')
                while (isdigit(s[++i] = c = getch()))
                        ;

        s[i] = '\0';

        if (c != EOF)
                ungetch(c);
        return NUMBER;
}

// declarations for getch() and ungetch()
#define BUFSIZE 100

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

// get a (possibly pushed back) character
int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c)
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}
