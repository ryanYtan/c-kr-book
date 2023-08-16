/**
 * Exercise 2-10
 *
 * Rewrite the function `lower`, which converts upper case letters to
 * lower case, with a conditional expression instead of if-else.
 */
#include <assert.h>
#include <stdint.h>
#include "../../utility.h"

char lower(char c)
{
        return 'A' <= c && c <= 'Z'
                ? c - 'A' + 'a'
                : c;
}

int main()
{
        assert(lower('\0') == '\0');
        assert(lower('\n') == '\n');
        assert(lower('\b') == '\b');
        assert(lower('A') == 'a');
        assert(lower('K') == 'k');
        assert(lower('R') == 'r');
        assert(lower('Y') == 'y');
        assert(lower('Z') == 'z');
        assert(lower('a') == 'a');
        assert(lower('k') == 'k');
        assert(lower('r') == 'r');
        assert(lower('y') == 'y');
        assert(lower('z') == 'z');
        print_tc_success();
}
