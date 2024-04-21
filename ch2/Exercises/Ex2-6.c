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
        printf("0x%08x\n", setbits(0xffffffff, (i*4), 8, 0x69));
    return 0;
}

int setbits(unsigned x, int p, int n, unsigned y)
{
    // Use unsigned 0 (0U) so the compiler doesn't complain with -Wall -Wextra
    // Otherwise, n will be promoted to a (signed) int -- possible negative left shift
    int mask_y = ~(~0U << n);           // zeros followed by n ones
                                        // .........p.....
    int mask_x = ~((~(~0U << n)) << p); // 1...10...01...1
    x = x & mask_x;                     // x...x0...0x...x
    y = (y & mask_y) << p;              // 0...0y...y0...0
    return x | y;
}


/* Discussion: Some factors we want to consider here include how we order the
 * bits (start at 0 or 1) and whether or not p refers to the most significant
 * bit or least significant bit. We can infer from the code in the getbits()
 * function in K&R that the least significant bit is indexed as 0, and that p
 * refers to the most significant bit of the chunk that we want to mask out.
 * Working with these specifications we must left-shift our (right-adjusted)
 * masks by p+1-n bits, as is presented in getbits() (in the case that we index
 * the least significant bit as 1, this just becomes p-n, which forces a lower
 * bound of 1 on p). However, this allows for the possibility that we end up
 * left shifting by a negative number (when n > p+1), which is undefined
 * behaviour. With this implementation on my machine, this has always produced
 * a right shift that wraps to the most significant bit, however this may not
 * be the case on all machines. On the other hand, if we consider p to point to
 * the least significant bit of the chunk we want to mask (as I have done
 * above), then we don't have to worry about negative left shifts, but of
 * course this will alter the upper bound of p, which will depend on n.
 *
 * TL;DR
 * p points to the most significant bit:
 *  - n <= p+1 <= w, where w is bit-width of the integral type
 *
 * p points to the least significant bit:
 *  - n <= w - p and p <= w - n
 * 
 * I didn't include these bound checks in my solution because, honestly, I
 * can't be bothered at the moment.
 */
