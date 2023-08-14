/**
 * Exercise 2-5
 *
 * Write the function any(s1,s2) which returns the first location
 * in the string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no characters from s2.
 */
#include "../../utility.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>

int any(char s1[], char s2[])
{
        _Bool has_s2_char[CHAR_MAX] = { 0 };
        for (int i = 0; s2[i] != '\0'; i++)
        {
                has_s2_char[s2[i]] = 1;
        }

        for (int i = 0; s1[i] != '\0'; i++)
        {
                if (has_s2_char[s1[i]])
                {
                        return i;
                }
        }
        return -1;
}

int main()
{
        char s1[] = "abcde";
        assert(any(s1, "d") == 3);
        assert(any(s1, "db") == 1);
        assert(any(s1, "e") == 4);
        assert(any(s1, "rtyrytryta") == 0);
        assert(any(s1, "fg") == -1);
        print_tc_success();
}
