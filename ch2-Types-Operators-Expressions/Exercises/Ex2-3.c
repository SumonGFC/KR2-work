/* Exercise 2-3. Write a function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */
#include <stdio.h>

unsigned int htoi(char s[]);
int is_valid_hex(char c);
unsigned int xchar_to_ui(char c);

int main(void)
{
    char test1[] = "0x12aBc4F";
    char test2[] = "0X12aBc4FF";
    char test3[] = "1qw";
    
    printf("test1: %d\n", 19577935 == htoi(test1));
    printf("test2: %d\n", 313246975 == htoi(test2));
    printf("test3: %d\n", 1 == htoi(test3));
    return 0;
}

unsigned int htoi(char s[])
{
    int i;
    unsigned int n = 0;
    
    i = (s[1] == 'x' || s[1] == 'X') ? 2 : 0;

    for (; s[i] != '\0' && is_valid_hex(s[i]); ++i) {
        n = 16*n + xchar_to_ui(s[i]);
    }
    return n;
}

int is_valid_hex(char c) 
{
    return (c >= '0' && c <= '9') ||
           (c >= 'a' && c <= 'f') ||
           (c >= 'A' && c<= 'F');
}

unsigned int xchar_to_ui(char c)
{
    if (c >= '0' && c <= '9')
        return (unsigned int) (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (unsigned int) (c - 'a' + 10);
    else
        return (unsigned int) (c - 'A' + 10);
}
