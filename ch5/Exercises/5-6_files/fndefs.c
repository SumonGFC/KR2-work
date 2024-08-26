// Rewrite appropriate programs from earlier chapters and exercises with
// pointers instead of array indexing. Good possibilities include getline
// (Chapters 1 and 4), my_atoi, my_itoa, and their variants (Chapters 2, 3, and 4),
// reverse (Chapter 3), and strindex and getop (Chapter 4).

#include <limits.h>
#include <stdio.h>
#include <ctype.h>

int my_getline(char *buff, size_t size)
{
        if (size <= 1)
                return -1;
        size_t i;
        int c;
        for (i = 0; (c = getchar()) != EOF && i < size - 1; ++i) {
                *(buff + i) = c;
                if (c == '\n')
                        break;
        }
        *buff = '\0';
        return i;
}

int my_atoi(const char *str)
{
        int num, digit, sign;

        while (isspace(*str))
                str++;
        
        sign = (*str == '-') ? -1 : 1;
        if (*str == '+' || *str == '-')
                str++;

        for (num = 0; isdigit(*str); str++) {
                digit = *str - '0';
                if (num > (INT_MAX - digit) / 10)
                        return (sign == -1) ? INT_MIN : INT_MAX;
                num = 10*num + digit;
        }
        
        return sign * num;
}

char *my_itoa(int num, char *buff)
{
        char *bp = buff;
        int i = 0;
        int sign = (num < 0) ? -1 : 1;

        if (sign < 0) {
                num = -num;
                *bp++ = '-';
        }
        while (num > 0) {
                *bp++ = (num % 10) + '0'; 
                num /= 10;
        }
        *bp = '\0';

        char *bp_left = (sign < 0) ? buff + 1 : buff;
        while (bp_left < bp) {
                int tmp = *bp_left;
                *bp_left++ = *--bp;
                *bp = tmp;
        }
        return buff;
}
