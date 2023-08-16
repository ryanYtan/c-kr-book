/**
 * Exercise 2-6
 *
 * Write a function setbits(x,p,b,y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other
 * bits unchanged
 */
#include "../../utility.h"
#include <assert.h>

/*
0 & 1-> 0
1 & 1-> 1
*/

//sets the i-th (zero-indexed, from the right) bit of x to v (1, 0)
unsigned int set_nth(unsigned int x, int i, _Bool v)
{
        return v == 1
                ? x | (v << i)
                : x & ~(v << i);
}

//gets the i-th (zero-indexed, from the right) bit of x
_Bool get_nth(unsigned int x, int i)
{
        return 0x1 & (x >> i);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
        for (int i = 0; i < n; i++)
        {
                int xpos = p - i;
                int ypos = n - i - 1;
                _Bool v = get_nth(y, ypos);
                x = set_nth(x, xpos, v);
        }
        return x;
}

unsigned int setbits2(unsigned int x, int p, int n, unsigned int y)
{

        0b0000111100001010; //original
        0b1010000000000000; //left shift by WIDTH - n
        0b0000000000001010; //right shift by WIDTH - n
        0b0000000010100000; //left shift by n

        0b0011001100110011; //x
        0b1111111110101111; //

        int shift_amt = n - 1;
}

int main()
{
        //                 15     8       0
        unsigned int x = 0b0011001100110011;
        unsigned int y = 0b0000111100001111;

        printf("x=%u\n", x);
        printf("r=%u\n", setbits(x, 7, 4, y));

        assert(setbits(x, 7, 4, y) == 0b0011001111110011);
        print_tc_success();
}
