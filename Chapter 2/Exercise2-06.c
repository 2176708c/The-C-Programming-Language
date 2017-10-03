#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    printf("%u\n", setbits(170, 5, 3, 15)); /* binary for 170: 10101010, binary for 15: 00001111*/
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // mask for x xx000xxx
    unsigned maskx = x & ~(~(~0 << n) << (p + 1 - n));

    // mask for y 00yyy000
    unsigned masky = (y & ~(~0 << n)) << (p + 1 - n);

    // combination of the two masks xxyyyxxx
    return maskx | masky;
}
