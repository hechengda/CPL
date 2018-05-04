/*rotate x to the right by n positions*/
unsigned rightrot1(unsigned x, int n)
{
    int wordlen(void);
    int rbit;       /*rightmost bit*/

    while (n-- > 0)
    {
        rbit = (x & 1) << (wordlen() - 1);
        x >>= 1;
        x |= rbit;      /*complete one rotation*/
    }
    return x;
}

unsigned rightrot2(unsigned x, int n)
{
    int wordlen(void);
    unsigned rbits;

    if ((n %= wordlen()) > 0)
    {
        rbits = ~(~0 << n) & x;         /*n rightmost bits of x*/
        rbits <<= (wordlen() - n);      /*n rightmost bits left*/
        x >>= n;        /*x shifted n positions right*/
        x |= rbits;     /*rotation completed*/
    }
    return x;
}

/*computes word length of the machine*/
int wordlen(void)
{
    int i;
    unsigned v = (unsigned)~0;

    for (i = 1; (v >>= 1) > 0; i++)
    {
        ;
    }
    return i;
}
