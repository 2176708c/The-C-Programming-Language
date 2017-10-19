#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    printf("%u\n", rightrot(400, 3)); 
    /* binary for 400 : 110010000, after 3 rotations
    to the right gives: 000110010 which is 50 */
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    char size = sizeof(unsigned) * CHAR_BIT; /* size of unsigned char */
    
    /* if either is 0 then original value is unchanged */
    if((0 == x) || (0 == n))
       return x;
    else
        /* return the OR of the shifting  x to the left
        by (size-n) bits with the shifting x to the right by n bits*/
        return (x >> n)|(x << (size - n));
}