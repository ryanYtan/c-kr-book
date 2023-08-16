/**
 * Exercise 2-07
 *
 * Write a function invert(x,p,n) that returns x with the n bits that begin
 * at position p inverted (i.e., 1 changed to 0 and vice versa), leaving
 * the others unchanged
 */
#include <assert.h>
#include "../../utility.h"

unsigned int invert(unsigned int x, int p, int n)
{
        unsigned int mask = (1u << n) - 1;
        return x ^ (mask << (p - n + 1));
}

int main()
{
        //                 7  4
        unsigned int x = 0b00110011;
        assert(invert(x, 7, 8) == 0b11001100);
        assert(invert(x, 5, 5) == 0b00001101);
        assert(invert(x, 4, 0) == x);
        assert(invert(x, 4, 1) == 0b00100011);
        print_tc_success();
}
