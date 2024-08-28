// Write versions of the library functions strncpy, strncat, and strncmp, which
// operate on at most the first n characters of their argument strings. For
// example, strncpy(s,t,n) copies at most n characters of t to s.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void my_strncpy_test(void);
void my_strncat_test(void);
void my_strncmp_test(void);

int main(void)
{
        my_strncpy_test();
        my_strncat_test();
        my_strncmp_test();
        return 0;
}

char *my_strncpy(char *dst, const char *src, size_t n);
char *my_strncat(char *dst, const char *src, size_t n);
int my_strncmp(const char *str1, const char *str2, size_t n);

void my_strncpy_test(void)
{
        char dst[100];
        char empty[] = "";
        char str[] = "asdfghjkl";       // len == 9
        printf("\nSTRNCPY TESTS\n");
        printf("Test str: %s\n\n", str);
        printf("Test str, n = 0\n\texpected:  , actual: %s\n",
                        my_strncpy(dst, str, 0));
        printf("Test str, n = 9\n\texpected: asdfghjkl, actual: %s\n",
                        my_strncpy(dst, str, 9));
        printf("Test str, n = 5\n\texpected: asdfg, actual: %s\n",
                        my_strncpy(dst, str, 5));
        printf("Empty str, n = 5\n\texpected:  , actual: %s\n",
                        my_strncpy(dst, empty, 5));
}

char *my_strncpy(char *dst, const char *src, size_t n) {
        // Copy at most n characters of string src to dst; return dst.
        // Pad with '\0''s if src has fewer than n characters.
        int i;
        for (i = 0; i < n; i++)
                *(dst + i) = *(src + i) ? *(src + i) : '\0';
        *(dst + i) = '\0';
        return dst;
}

void my_strncat_test(void)
{
        char buff[100];
        char buff_filled[] = "qwerty";
        char src[] = "asdfg";
        printf("\n\nSTRNCAT() TESTS:\n");
        printf("Empty buffer, full concat\n\texpected: asdfg, actual: %s\n",
                        my_strncat(buff, src, 20));
        buff[0] = '\0';
        printf("Empty buffer, 0 concat\n\texpected: , actual: %s\n",
                        my_strncat(buff, src, 0));
        buff[0] = '\0';
        printf("Empty buffer, single letter concat\n\texpected: a, actual:"
                        " %s\n", my_strncat(buff, src, 1));
        printf("Filled buffer, multiple letter concat\n\texpected: qwertyasdfg,"
                        " actual: %s\n", my_strncat(buff_filled, src, 5));
}

char *my_strncat(char *dst, const char *src, size_t n) {
        // Concatenate at most n characters of string src to string dst.
        // Terminate dst with '\0'; return dst.
        char *pos = dst + strlen(dst);
        for (int i = 0; *src && i < n; ++i, *pos++ = *src++)
                ;
        *pos = '\0';
        return dst;
}

void my_strncmp_test(void)
{
        char str1[] = "asdf";
        char str2[] = "asdfghjkl";
        printf("strncmp: %d\n", my_strncmp(str1, str2, 4));
}

int my_strncmp(const char *str1, const char *str2, size_t n) {
        // Compare at most n characters of string str1 to string str2;
        // return <0 if str1<str2, 0 if str1==str2, or >0 if str1>str2. 
        int i;
        for (i = 0; i < n-1 && *str1 && *str2 && *(str1 + i) == *(str2 + i); i++)
                printf("(%d, %c, %c)\n", i, *(str1 + i), *(str2 + i));
                
        printf("(%d, %c, %c)\n", i, *(str1 + i), *(str2 + i));
        return (unsigned char)*(str1 + i) - (unsigned char)*(str2 + i);
}
