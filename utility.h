#ifndef C_KR_BOOK_UTIL_H
#define C_KR_BOOK_UTIL_H

#include <stdio.h>

void print_tc_success()
{
        fprintf(stderr, "All test cases passed!\n");
}

void bprintln(unsigned int x, int nbits)
{
        for (int i = 0; i < nbits; i++)
        {
                if (i != 0 && i % 4 == 0)
                {
                        putchar(' ');
                }
                putchar((1u & (x >> (31 - nbits))) == 1 ? '1' : '0');
                x <<= 1;
        }
        putchar('\n');
}

#endif
