/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n positions.
 */
unsigned rightrot(unsigned x, int n)
{
    unsigned right_bits = (x & ~(~0u << n));
    if (right_bits > 0) {
        while ((right_bits << 1) > right_bits) {
            right_bits = right_bits << 1;
        }
    }
    return (x >> n) | right_bits;
}
