/**
 * Exercise 2-09
 *
 * In a two's complement number system, (x &= (x - 1)) deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster version of
 * bitcount.
 *
 * MY ANSWER IS
 *
 * Subtraction in 2s complement works like so:
 *
 * Say we have a number x, and we wish to subtract y, we
 *     1. Get y in binary representation, invert the bits, then add 1
 *     2. Add x to the result obtained in step 1
 *
 * Given y=1
 *     1. We have 0000_0000_0000_0001
 *     2. Inverted, we get 1111_1111_1111_1110
 *     3. Adding 1, we get 1111_1111_1111_1111. This is the 2s complement repr of -1
 *
 * Say we have x=12. This is 0000_0000_0000_1100. When we add the two together:
 *
 *   0000 0000 0000 1100 (x)
 * + 1111 1111 1111 1111 (-1)
 *   0000 0000 0000 1011 (x-1)
 *
 * If we now take (x & (x-1)), we get
 *
 *   0000 0000 0000 1100
 * & 0000 0000 0000 1011
 *   0000 0000 0000 1000
 *
 * Now, say we have x=-4. This is 1111_1111_1111_1100
 *
 *   1111 1111 1111 1100 (x)
 * + 1111 1111 1111 1111 (-1)
 *   1111 1111 1111 1011 (x-1)
 *
 * In essence, in (x-1)
 *     1. (A) All bits to the left of the rightmost 1-bit will remain the same
 *     2. (B) All bits including and to the right of the rightmost 1-bit will flip
 *     3. When we take (x&(x-1))
 *         1. All bits in (A) are copied over from x
 *         2. The first bit of (B) in (x-1) will be a 0, and 1 & 0 = 0.
 *            Therefore the bit is removed. The rest of the bits of (B) in (x-1)
 *            will be 1s, but the bits in (x) will be 0s, and 1 & 0 = 0 once again.
 */
#include <assert.h>
#include <stdint.h>
#include "../../utility.h"

//Counts the number of set (1) bits in x
int bitcount(unsigned x)
{
        int b;
        for (b = 0; x != 0; x >>= 1)
                if (x & 01)
                        b++;
        return b;
}

//this is faster because the loop iterations are bounded by the number of
//1-bits. The other version's iterations are bound by the position of the most
//significant 1-bit
int fast_bitcount(unsigned int x)
{
        int ctr = 0;
        while (x != 0)
        {
                x &= (x - 1);
                ++ctr;
        }
        return ctr;
}

int main()
{
        assert(fast_bitcount(0b1111000011001010) == 8);
        assert(fast_bitcount(0b1100010101101011) == 9);
        assert(fast_bitcount(0) == 0);
        assert(fast_bitcount(1) == 1);
        print_tc_success();
}
