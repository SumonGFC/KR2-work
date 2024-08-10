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
 *
 * Exercise 4-7. Write a routine ungets(s) that will push back an entire string
 * onto the input. Should ungets know about buf and bufp, or should it just use
 * ungetch?
 *
 * Exercise 4-8. Suppose that there will never be more than one character of
 * pushback. Modify getch and ungetch accordingly.
 *
 * Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
 * correctly. Decide what their properties ought to be if an EOF is pushed back,
 * then implement your design.
 *
 * Exercise 4-10. An alternate organization uses getline to read an entire input
 * line; this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define TOP '!'
#define DUP '@'
#define SWAP '#'
#define CLEAR '$'
#define MATH_LIB_FN '&'
#define VAR '^'

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
// EXERCISE 4-5
void mathh_eval(char[]);

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
                        case CLEAR:
                                clear();
                                break;
                        case MATH_LIB_FN:
                                mathh_eval(s);
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
                                if (op2)
                                        push(pop() / op2);
                                else
                                        printf("Error: Zero Division\n");
                                break;
                        case '%':
                                mod_op = (int)pop();
                                if (mod_op)
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

// STACK OPERATIONS
#define MAXVAL 100      // max stack depth

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
        if (sp <= MAXVAL && sp > 0)
                push(val_stack[sp-1]);
        else
                printf("Stack empty\n");
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

void mathh_eval(char s[])
{
        double tmp;
        if (strcmp(s, "pow") == 0 && sp >= 2) {
                tmp = pop();
                push(pow(pop(), tmp));
        } 
        else if (strcmp(s, "exp") == 0 && sp >= 1)
                push(exp(pop()));
        else if (strcmp(s, "log") == 0 && sp >= 1)
                push(log(pop()));
        else if (strcmp(s, "sqrt") == 0 && sp >= 1)
                push(sqrt(pop()));
        else if (strcmp(s, "print") == 0)
                print_stack();
        else
                printf("Error: unrecognized function or not enough operands on stack to perform %s\n", s);
}

// getop(): get next operator or operand
#include <ctype.h>

// declarations for getop
int getch(void);
void ungetch(int);

int getop(char s[])
{
        int i, c;

        // skip leading white space
        while ((s[0] = c = getch()) == ' ' || c == '\t')
                ;
        s[1] = '\0';

        if (!isalnum(c) && c != '.' && c != '-')
                return c;

        i = 0;

        // collect contiguous alphabetical str and return
        if (isalpha(c)) {
                if (!isalpha(s[++i] = c = getch())) {
                        if (c != EOF)
                                ungetch(c);
                        s[1] = '\0';
                        return VAR;
                } else {
                        while (isalpha(s[++i] = c = getch()))
                                ;
                        if (c != EOF)
                                ungetch(c);
                        s[i] = '\0';
                        return MATH_LIB_FN;
                }
        }

        // parse unary/binary minus
        if (c == '-') {
                // return if binary minus (note assignment to s[])
                if (!isdigit(s[++i] = c = getch()) && c != '.') {
                        if (c != EOF)
                                ungetch(c);
                        return s[0];
                }
        }
        
        // Input is a number; collect integer and fractional parts
        if (isdigit(c))
                while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.')
                while (isdigit(s[++i] = c = getch()))
                        ;

        s[i] = '\0';
        // push last read character to buffer to read on next call to getop()
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


