/**
 * Exercise 4-14
 *
 * Define a macro swap(t,x,y) that interchanges two arguments of type t
 */
#include <assert.h>
#include <string.h>
#include "../../utility.h"

#define SWAP(t, x, y)           \
        do {                    \
                t __tmp = x;    \
                x = y;          \
                y = __tmp;      \
        } while (0)             \

int main(void)
{
        {
                int x = 10;
                int y = 40;
                SWAP(int, x, y);
                assert(x == 40);
                assert(y == 10);
        }
        {
                char *s = "abcde";
                char *t = "12345";
                SWAP(char*, s, t);
                assert(strcmp(s, "12345") == 0);
                assert(strcmp(t, "abcde") == 0);
        }
        print_tc_success();
}
