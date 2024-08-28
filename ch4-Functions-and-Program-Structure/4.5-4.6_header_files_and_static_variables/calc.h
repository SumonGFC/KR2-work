#ifndef CALC_H
#define CALC_H

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
void assign_var(char[3]);
void print_vars(void);
// declarations for getop()
int getch(void);
void ungetch(int);

#endif
