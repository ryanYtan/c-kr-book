/**
 * Exercise 3-06
 *
 * Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be
 * padded with blanks on the left if necessary to make it width enough.
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

void itoa(int n, char s[], int z)
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

        if (z - i > 0)
        {
                int padding = z - i;
                for (int _ = 0; _ < padding; _++)
                {
                        s[i++] = '0';
                }
        }

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
                itoa(n, s, 12);
                assert(strcmp(s, "-002147483648") == 0);
        }
        {
                int n = INT_MAX;
                char s[100] = { 0 };
                itoa(n, s, 13);
                assert(strcmp(s, "0002147483647") == 0);
        }
        {
                int n = 0;
                char s[100] = { 0 };
                itoa(n, s, 3);
                assert(strcmp(s, "000") == 0);
        }
        {
                int n = -0;
                char s[100] = { 0 };
                itoa(n, s, 5);
                assert(strcmp(s, "00000") == 0);
        }
        {
                int n = -1;
                char s[100] = { 0 };
                itoa(n, s, 1);
                assert(strcmp(s, "-1") == 0);
        }
        {
                int n = 1;
                char s[100] = { 0 };
                itoa(n, s, 2);
                assert(strcmp(s, "01") == 0);
        }
        {
                int n = 187923;
                char s[100] = { 0 };
                itoa(n, s, 30);
                assert(strcmp(s, "000000000000000000000000187923") == 0);
        }
        {
                int n = -9999;
                char s[100] = { 0 };
                itoa(n, s, 1);
                assert(strcmp(s, "-9999") == 0);
        }
        {
                int n = 1000000001;
                char s[100] = { 0 };
                itoa(n, s, 2);
                assert(strcmp(s, "1000000001") == 0);
        }
        {
                int n = -100000;
                char s[100] = { 0 };
                itoa(n, s, 3);
                assert(strcmp(s, "-100000") == 0);
        }

        print_tc_success();
}
