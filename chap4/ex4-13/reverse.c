/**
 * Exercise 4-13
 *
 * Write a recursive version of the function reverse(s), which reverses the
 * string s in place.
 */
#include <assert.h>
#include <string.h>
#include "../../utility.h"


void _swap(char *s, char *t)
{
        char tmp = *s;
        *s = *t;
        *t = tmp;
}


int _reverse(char *s, char *t, int depth)
{
        if (*t == '\0')
        {
                return depth;
        }
        int end = _reverse(s, t + 1, depth + 1);
        int oppose = end - depth - 1;
        if (depth >= end / 2)
        {
                _swap(s + oppose, t);
        }
        return end;
}

void reverse(char *s)
{
        _reverse(s, s, 0);
}

int main()
{
        {
                char s[] = "";
                reverse(s);
                assert(strcmp(s, "") == 0);
        }
        {
                char s[] = "ab";
                reverse(s);
                assert(strcmp(s, "ba") == 0);
        }
        {
                char s[] = "abc";
                reverse(s);
                assert(strcmp(s, "cba") == 0);
        }
        {
                char s[] = "abcd";
                reverse(s);
                assert(strcmp(s, "dcba") == 0);
        }
        {
                char s[] = "to be or not to be";
                reverse(s);
                assert(strcmp(s, "eb ot ton ro eb ot") == 0);
        }
        print_tc_success();
}
