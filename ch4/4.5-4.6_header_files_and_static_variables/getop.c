#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
        int i, c;

        // skip leading white space and read first char into s[]
        while ((s[0] = c = getch()) == ' ' || c == '\t')
                ;
        s[1] = '\0';

        // Guard clause: no uppercase vars, bad assignment syntax
        if (isupper(c) || c == '=')
                return 0;

        // handle stack op
        if (c == PRINT || c == TOP || c == DUP || c == SWAP || c == CLEAR) {
                return STACK_OP;
        }

        // return if c is +, *, /, \n, or other illegal input
        if (!isalnum(c) && c != '.' && c != '-')
                return c;

        i = 0;

        // handle alphabetic inputs: variable/assignment, math.h function
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
