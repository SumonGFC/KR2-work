#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calc.h"

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

float var_vals[26] = { 0.0 };

void print_vars(void)
{
        int i;
        for (i = 'a'; i <= 'z'; i++)
                printf("%c: %g, ", i, var_vals[i - 'a']);
        printf("\n");
}

double var_to_val(char s[2])
{
        return var_vals[s[0] - 'a'];
}
void assign_var(char s[3])
{
        if (sp < 1)
                printf("Error: stack empty; can't assign %s\n", s);
        else {
                var_vals[s[0] - 'a'] = val_stack[(sp - 1)];
                printf("variable '%c' assigned %g\n", s[0], val_stack[(sp - 1)]);
        }
}
