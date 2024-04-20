// atoi: convert s (string of digits) to an integer
#include <ctype.h>
#include <stdio.h>

int atoi(char s[]);
int atoi_ctype(char s[]);
int lower(int c);
int lower_ctype(int c);


int main(void)
{
    char s[] = "1234";
    char c = 'A';
    printf("atio: %d\n", atoi(s));
    printf("atoi_ctype: %d\n", atoi_ctype(s));
    printf("lower: %c\n", lower(c));
    printf("lower_ctype: %c\n", lower_ctype(c));
    return 0;
}

// Without ctype.h
int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) 
        n = n*10 + (s[i] - '0');
    return n;
}

int atoi_ctype(char s[])
{
    int i,n;
    n = 0;
    for (i=0; isdigit(s[i]); ++i)
        n = 10*n + (s[i] - '0');
    return n;
}


int lower(int c)
{
    if (c >= 'A' && c <= 'Z') 
        return c + ('a' - 'A');
    else
        return c;
}

int lower_ctype(int c)
{
    return tolower(c);
}
