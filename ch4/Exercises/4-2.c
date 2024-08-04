#include <stdio.h>
#include <ctype.h>
#include "get_line.h"

#define MAXLINE 1000

double atof(char float_string[]);

int main(void)
{
        char line[MAXLINE];

        while (get_line(line, MAXLINE) > 0)
                printf("\t--> %g\n", atof(line));
        return 0;
}

double atof(char s[])
{
        double val;
        double power;
        double exp_pow;
        int i;
        int sign;
        int exp_sign;

        // skip white space at the beginning
        // get sign
        // get integer part of string
        // get decimal point
        // get decimal part of string

        for (i = 0; isspace(s[i]); i++)
                ;
        sign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-')
                i++;

        for (val = 0.0; isdigit(s[i]); i++)
                val = 10.0 * val + (s[i] - '0');

        if (s[i] == '.')
                i++;

        for (power = 1.0; isdigit(s[i]); i++) {
                val = 10.0 * val + (s[i] - '0');
                power *= 10.0;
        }

        return sign * val / power;
}
