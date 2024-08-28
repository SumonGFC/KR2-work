#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"

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
                                push(var_to_val(s));
                                break;
                        case ASSIGN:
                                assign_var(s);
                                print_vars();
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
