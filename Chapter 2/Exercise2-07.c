#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    printf("%u\n", invert(170, 5, 3)); /* binary for 170: 10101010 */
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    // mask for x 00xxx000
    unsigned mask = ~(~0 << n) << (p + 1 - n);


    // exclusive OR between x and the mask is xx^^^xxx
    return x ^ mask;
}