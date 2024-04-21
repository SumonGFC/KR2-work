/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 */
#include <stdio.h>

int setbits(unsigned x, unsigned int p, unsigned int n, unsigned y);

int main(void)
{
    int i;
    for (i = 0; i < 8; ++i)
        printf("0x%08x\n", setbits(0xffffffff, (i*4), 4, 0));
    return 0;
}

int setbits(unsigned x, unsigned int p, unsigned int n, unsigned y)
{
    int mask_x = ~((~(~0U << n)) << p); // 0...01...10...0
    int mask_y = ~(~0U << n);           // 0...01...1
    x = x & mask_x;
    y = (y & mask_y) << p;
    return x | y;
}
