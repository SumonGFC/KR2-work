#include <stddef.h>
#ifndef _FNDECS_H
#define _FNDECS_H
// get input from stdin; return number of chars read
int my_getline(char *buffer, size_t buffer_size);
void my_getline_test(void);
// convert char array to int
int my_atoi(const char *str);
void my_atoi_test(void);
// convert number to char array, return pointer to array
char *my_itoa(int number, char *buffer);
void my_itoa_test(void);
// convert char array to double; return number
double my_atof(const char *str);
void my_atof_test(void);
// reverse string in place
void my_strrev(char *str);
void my_strrev_test(void);
// return index of pattern in str; -1 if none
int strindex(const char *str, const char *pattern);
void strindex_test(void);
// get next character or numeric operand
void getop_test(void);
int getop(char *str);
int getch(void);
void ungetch(int);
#endif
