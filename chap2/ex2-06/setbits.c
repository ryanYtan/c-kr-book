/**
 * Exercise 2-6
 *
 * Write a function setbits(x,p,b,y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other
 * bits unchanged
 */
#include "../../utility.h"
#include <limits.h>
#include <assert.h>

//sets the i-th (zero-indexed, from the right) bit of x to v (either {1, 0})
unsigned int set_nth(unsigned int x, int i, _Bool v)
{
        return v
                ? x | (1u << i)
                : x & ~(1u << i);
}

//gets the i-th (zero-indexed, from the right) bit of x
_Bool get_nth(unsigned int x, int i)
{
        return (x & (1u << i)) > 0;
        //return 1u & (x >> i);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
        //p=7, n=4
        for (int i = 0; i < n; i++)
        {
                _Bool v = get_nth(y, (n - 1) - i);
                x = set_nth(x, p - i, v);
        }
        return x;
}

unsigned int setbits2(unsigned int x, int p, int n, unsigned int y)
{
        unsigned int mask = (1u << n) - 1; //mask with rightmost n bits set
        unsigned int y1 = mask & y; //y with only rightmost n bits, rest zero
        unsigned int y2 = y1 << (p - n + 1); //set y1 in position to overwrite x
        unsigned int x1 = x & ~(mask << (p - n + 1)); //"poke a hole" in x
        unsigned int ret = x1 | y2;
        return ret;
}

int main()
{
        //                 15     8       0
        unsigned int x = 0b0011001100110011;
        unsigned int y = 0b0111111100001010;

        assert(setbits2(x, 7, 4, y) == 0b0011001110100011);
        assert(setbits2(x, 14, 5, y) == 0b0010101100110011);
        assert(setbits2(x, 9, 8, y) == 0b0011000000101011);
        print_tc_success();
}
