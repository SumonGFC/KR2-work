#include <stdio.h>
#include <limits.h>
#include "fndecs.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_int_eq(int expected, int actual)
{
        if (expected == actual)
                printf(ANSI_COLOR_GREEN"expected %d: actual %d \n"ANSI_COLOR_RESET, expected, actual);
        else
                printf(ANSI_COLOR_RED"expected %d: actual %d\n"ANSI_COLOR_RESET, expected, actual);
}

void my_getline_test(void) {}

void atoi_test(void)
{
        char empty[] = "";
        char pure_num[] = "123";
        char alpha[] = "asdf";
        char whitespace_alpha[] = "             asdf";
        char whitespace_num[] = "     123";
        char single_negative[] = "-";
        char neg_alpha[] = "-a";
        char negative[] = "-123";
        char positive[] = "+123";
        char num_alpha[] = "123asd";
        char max_int[] = "999999999999999999999999999999";
        char min_int[] = "-999999999999999999999999999999";
        printf("When empty\n\t"); print_int_eq(0, atoi(empty)); 
        printf("When '123'\n\t"); print_int_eq(123, atoi(pure_num)); 
        printf("When 'asdf'\n\t"); print_int_eq(0, atoi(alpha)); 
        printf("With leading ws front of alpha\n\t"); print_int_eq(0, atoi(whitespace_alpha)); 
        printf("With leading ws front of 123\n\t"); print_int_eq(123, atoi(whitespace_num)); 
        printf("When '-'\n\t"); print_int_eq(0, atoi(single_negative)); 
        printf("When '-a'\n\t"); print_int_eq(0, atoi(neg_alpha)); 
        printf("When '-123'\n\t"); print_int_eq(-123, atoi(negative)); 
        printf("When '+123'\n\t"); print_int_eq(123, atoi(positive)); 
        printf("When '123asd'\n\t"); print_int_eq(123, atoi(num_alpha)); 
        printf("When >MAX_INT\n\t"); print_int_eq(INT_MAX, atoi(max_int)); 
        printf("When <MAX_INT\n\t"); print_int_eq(INT_MIN, atoi(min_int)); 
}

void itoa_test(void)
{
        int zero = 0;
        int negs_one = -1;
        int one = 1;
        int max = INT_MAX;
        int min = INT_MIN;
        int pos = 12345;
        int neg = -12345;
        char len_one[1];
        char too_small[3];
        char too_big[100];
        char just_right_pos[11];
        char just_right_neg[12];
}
void atof_test(void) {}
void strrev_test(void) {}
void strindex_test(void) {}
void getop_test(void) {}

