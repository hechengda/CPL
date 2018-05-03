/*inverts the n bits of x that begin at pos p*/
unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}