/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged. 
 */
#include <stdio.h>

int invert(unsigned x, int p, int n);

int main(void)
{
    printf("0x%08x\n", invert(0xffffffff, 27, 8));
    return 0;
}

int invert(unsigned x, int p, int n)
{
    if (p + 1 < n) {
        printf("Error: Negative left shift\n");
        return 0;
    }
    unsigned invert_mask = ~x & ((~(~0u << n)) << (p + 1 - n));
    x = x & ~(~(~0u << n) << (p + 1 - n));
    return x | invert_mask;
}
