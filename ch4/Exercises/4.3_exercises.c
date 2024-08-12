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

// TODO: VERIFY 'islower()' CLAUSE IN getop()
// TODO: IMPLEMENT VAR/ASSIGNMENT LOGIC IN MAIN AND MAIN HELPER FUNCTIONS

// All of the below headers have been mentioned in the book thus far
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Identifiers to tokenize input for main()
#define MAXOP 100
#define NUMBER '0'
#define STACK_OP '?'
#define PRINT '~'
#define TOP '!'
#define DUP '@'
#define SWAP '#'
#define CLEAR '$'
#define MATH_LIB_FN '^'
#define VAR '&'
#define ASSIGN '='

// declarations for main
int getop(char[]);
void push(double);
double pop(void);
// declarations for exercise 4-4
void stack_op(char[2]);
void print_stack(void);
void top(void);
void dup(void);
void swap(void);
void clear(void);
// declarations for exercise 4-5
void mathh_eval(char[]);
// declarations for exercise 4-6
double var_to_val(char[2]);
void assign_eval(char[]);

// Reverse Polish Calculator
int main(void)
{
        int type, mod_op;
        double op2;
        char s[MAXOP];  // buffer to store characters from input

        printf("RPN Calculator: Enter Input in Reverse Polish Notation\n");
        printf("prnt: ~, top: !, dup: @, swap: #, clear: $\n\n");
        while ((type = getop(s)) != EOF) {
                switch(type) {
                        case NUMBER:
                                push(atof(s));
                                break;
                        case STACK_OP:
                                stack_op(s);
                                break;
                        case MATH_LIB_FN:
                                mathh_eval(s);
                                break;
                        case VAR:
                                break;
                        case ASSIGN:
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
                                printf("\n\tRESULT: ");
                                top();
                                //printf("\tRESULT: %.8g\n", pop());
                                break;
                        default:
                                printf("Syntax Error: bad input: %s\n", s);
                                break;
                }
        }
        printf("\nEND ");
        return 0;
}

// STACK OPERATIONS
#define MAXVAL 100      // max stack depth

int sp = 0;
double val_stack[MAXVAL];
const char var_arr[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
float var_vals[26] = { 0.0 };

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

// execute specified stack operation
void stack_op(char s[2])
{
        char c = s[0];
        switch(c) {
                case PRINT:
                        print_stack();
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
                default:
                        printf("stack_op() error: OOPS! This shouldn't have happened\n");
                        break;
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
                printf("TOP: %g\n", val_stack[(sp - 1)]);
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

// evaluate math.h function according to s[]
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
        else
                printf("Error: unrecognized function or not enough operands on stack to perform %s\n", s);
}

double var_to_val(char[2]);
int valid_assign(void);
void assign_eval(char[]);

// getop(): get next operator or operand

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

        // Guard clause; no uppercase vars, bad assignment syntax
        if (isupper(c) || c == '=')
                return 0;

        // handle stack operation
        if (c == PRINT || c == TOP || c == DUP || c == SWAP || c == CLEAR) {
                return STACK_OP;
        }

        // return if c is +, *, /, \n, or other illegal input
        if (!isalnum(c) && c != '.' && c != '-')
                return c;

        i = 0;

        // handle alphabetic inputs: variable/assignment, math.h lib function
        if (islower(c)) {
                s[++i] = c = getch();
                if (c == '=') {
                        s[++i] = '\0';
                        return ASSIGN;
                }
                else if (islower(c)) {
                        while (islower(s[++i] = c = getch()))
                                ;
                        if (c != EOF)
                                ungetch(c);
                        s[i] = '\0';
                        return MATH_LIB_FN;
                }
                else {
                        s[1] = '\0';
                        if (c != EOF)
                                ungetch(c);
                        return VAR;
                }
        }

        // parse unary/binary minus
        if (c == '-') {
                // return if binary minus (note assignment to s[1] is still executed)
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


