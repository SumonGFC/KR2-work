/*Write program to print the ranges of char, short, int and long variables, 
 * both signed and unsigned, by printing appropriate values from standard 
 * headers and by direct computation
 */

#include <stdio.h>
#include <limits.h>

void compute_s_char(signed char arr[2]);
void compute_us_char(unsigned char arr[2]);

void compute_s_short(signed short arr[2]);
void compute_us_short(unsigned short arr[2]);

void compute_s_int(signed int arr[2]);
void compute_us_int(unsigned int arr[2]);

void compute_s_long(signed long arr[2]);
void compute_us_long(unsigned long arr[2]);

int main(void) 
{
    /*
    // CHARS
    unsigned char us_chars[2] = {0, 1};
    signed char s_chars[2] = {0, 1};

    // SHORTS
    signed short s_shorts[2] = {0, 1};
    unsigned short us_shorts[2] = {0, 1};

    // INTS
    signed int s_ints[2] = {0, 1};
    unsigned int us_ints[2] = {0, 1};

    // LONGS
    signed long s_longs[2] = {0, 1};
    unsigned long us_longs[2] = {0, 1};
    compute_s_char(s_chars);
    compute_us_char(us_chars);
    printf("CHAR RANGE signed: (%d, %d), unsigned: (%d, %d)\n", s_chars[1], s_chars[0], us_chars[1], us_chars[0]);

    compute_s_short(s_shorts);
    compute_us_short(us_shorts);
    printf("SHORT RANGE signed: (%d, %d), unsigned: (%d, %d)\n", s_shorts[1], s_shorts[0], us_shorts[1], us_shorts[0]);

    compute_s_int(s_ints);
    compute_us_int(us_ints);
    printf("INT RANGE signed: (%d, %d), unsigned: (%d, %d)\n", s_ints[1], s_ints[0], us_ints[1], us_ints[0]);

    compute_s_long(s_longs);
    compute_us_long(us_longs);
    printf("LONG RANGE signed: (%ld, %ld), unsigned: (%ld, %ld)\n",s_longs[1], s_longs[0], us_longs[1], us_longs[0]);
    */

    printf("\nBits of type char: %d\n\n", CHAR_BIT);                     /* IV */

    printf("Maximum numeric value of type char: %d\n", CHAR_MAX);        /* IV */
    printf("Minimum numeric value of type char: %d\n\n", CHAR_MIN);      /* IV */

    printf("Maximum value of type signed char: %d\n", SCHAR_MAX);        /* IV */
    printf("Minimum value of type signed char: %d\n\n", SCHAR_MIN);      /* IV */

    printf("Maximum value of type unsigned char: %u\n\n", (unsigned) UCHAR_MAX);    /* SF */  /* IV */
  
    printf("Maximum value of type short: %d\n", SHRT_MAX);               /* IV */
    printf("Minimum value of type short: %d\n\n", SHRT_MIN);             /* IV */

    printf("Maximum value of type unsigned short: %u\n\n", (unsigned) USHRT_MAX);   /* SF */  /* IV */


    printf("Maximum value of type int: %d\n", INT_MAX);                  /* IV */
    printf("Minimum value of type int: %d\n\n", INT_MIN);                /* IV */

    printf("Maximum value of type unsigned int: %u\n\n", UINT_MAX);      /* RB */   /* IV */

    printf("Maximum value of type long: %ld\n", LONG_MAX);               /* RB */   /* IV */
    printf("Minimum value of type long: %ld\n\n", LONG_MIN);             /* RB */   /* IV */

    printf("Maximum value of type unsigned long: %lu\n\n", ULONG_MAX);   /* RB */   /* IV */
    return 0;
}


void compute_s_char(signed char arr[2])
{
    while (++arr[0] < ++arr[1])
        ;
}

void compute_us_char(unsigned char arr[2])
{
    while (++arr[0] < ++arr[1])
        ;
}

void compute_s_short(signed short arr[2])
{
    while (++arr[0] < ++arr[1])
        ;
}

void compute_us_short(unsigned short arr[2])
{
    while (++arr[0] < ++arr[1])
        ;
}

void compute_s_int(signed int arr[2])
{
    while (++arr[0] < ++arr[1])
        ;
}

void compute_us_int(unsigned int arr[2])
{
    while (++arr[0] < ++arr[1])
        ;
}

void compute_s_long(signed long arr[2])
{
    while (++arr[0] < ++arr[1])
        ;
}

void compute_us_long(unsigned long arr[2])
{
    while (++arr[0] < ++arr[1])
        ;
}
