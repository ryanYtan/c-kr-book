/**
 * Exercise 2-08
 *
 * Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n bit positions.
 */
#include <assert.h>
#include <stdint.h>
#include "../../utility.h"

uint8_t rightrot(uint8_t x, int n)
{
        n %= 8;
        uint8_t rx = x >> n;
        uint8_t lx = x & ((1u << n) - 1);
        return rx | (lx << (8 - n));
}

int main()
{
        uint8_t x = 0b10110011;

        assert(rightrot(x, 0) == x);
        assert(rightrot(x, 1) == 0b11011001);
        assert(rightrot(x, 2) == 0b11101100);
        assert(rightrot(x, 3) == 0b01110110);
        assert(rightrot(x, 4) == 0b00111011);
        assert(rightrot(x, 8) == x);
        assert(rightrot(x, 13) == 0b10011101);
        assert(rightrot(x, 16) == x);
        print_tc_success();
}
