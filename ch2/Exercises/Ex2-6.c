/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 */
#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    int i;
    for (i = 0; i < 8; ++i)
        printf("0x%08x\n", setbits(0xffffffff, (i*4), 4, 0x69));
    return 0;
}

int setbits(unsigned x, int p, int n, unsigned y)
{
    // Use unsigned 0 (0U) so the compiler doesn't complain with -Wall -Wextra
    // Otherwise, n will be promoted to a (signed) int -- possible negative left shift

    int mask_x = ~((~(~0U << n)) << p); // 1...10...01...1
    int mask_y = ~(~0U << n);           // 0...01...1
    x = x & mask_x;                     // x...x0...0x...x
    y = (y & mask_y) << p;              // 0...0y...y0...0
    return x | y;
}
