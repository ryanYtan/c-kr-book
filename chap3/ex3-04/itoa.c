/**
 * Exercise 3-05
 *
 * In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2^(wordsize - 1)). Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 *
 * Range of an k-bit integer is [-2**k, 2**k - 1] in 2s complement notation.
 * If n=-2**k, then when we do (n = -n), n is not large enough to fit that
 * value inside it
 */
#include <assert.h>
#include <string.h>
#include <limits.h>
#include "../../utility.h"

void reverse(char s[])
{
        size_t n = strlen(s);
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
        }
}

// [-100, 69]
// -100 => -99
// ...
// '-', '9', '9'

void itoa(int n, char s[])
{
        int i, sign, is_int_min, carry = 0;

        if ((is_int_min = (n == INT_MIN)))
        {
                n++;
                carry = 1;
        }

        if ((sign = n) < 0)
                n = -n;

        i = 0;
        do
        {
                int digit = n % 10 + carry;
                carry = digit / 10;
                digit = digit % 10;
                s[i++] = digit + '0';
        }
        while((n /= 10) > 0);

        if (sign < 0)
                s[i++] = '-';

        s[i] = '\0';
        reverse(s);
}

int main()
{
        {
                int n = INT_MIN;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "-2147483648") == 0);
        }
        {
                int n = INT_MAX;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "2147483647") == 0);
        }
        {
                int n = 0;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "0") == 0);
        }
        {
                int n = -0;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "0") == 0);
        }
        {
                int n = -1;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "-1") == 0);
        }
        {
                int n = 1;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "1") == 0);
        }
        {
                int n = 187923;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "187923") == 0);
        }
        {
                int n = -9999;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "-9999") == 0);
        }
        {
                int n = 1000000001;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "1000000001") == 0);
        }
        {
                int n = -100000;
                char s[100] = { 0 };
                itoa(n, s);
                assert(strcmp(s, "-100000") == 0);
        }

        print_tc_success();
}
