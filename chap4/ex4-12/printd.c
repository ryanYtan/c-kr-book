/**
 * Exercise 4-12
 *
 * Adapt the ideas of printd to write a recursive versionof itoa; that is,
 * convert an integer into a string by calling a recursive routine.
 */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../../utility.h"

void printd(int n)
{
        if (n < 0)
        {
                putchar('-');
                n = -n;
        }
        if (n / 10)
                printd(n / 10);
        putchar(n % 10 + '0');
}

void _add_if_int_min(char *buf, int i)
{
        int end = i + 1;
        int carry = 1;
        while (i > 1 && carry)
        {
                int sum = (buf[i] - '0') + carry;
                buf[i] = (sum % 10) + '0';
                carry = sum / 10;
        }
        if (carry)
        {
                buf[end + 1] = '\0';
                for (; carry && end > 1; end--)
                {
                        buf[end] = buf[end - 1];
                }
                buf[1] = '1';
        }
}

int _itoa(int n, char *buf, int i)
{
        if (n < 0)
        {
                buf[i] = '-';
                return _itoa(-n, buf, i + 1);
        }
        if (n == 0)
        {
                return i;
        }
        int end = _itoa(n / 10, buf, i + 1);
        int index = end - i - (buf[0] == '-' ? 0 : 1);
        buf[index] = (n % 10) + '0';
        return end;
}

char *itoa(int n, char *buf)
{
        int end = _itoa(n == INT_MIN ? n + 1 : n, buf, 0);
        if (end == 0)
        {
                buf[end++] = '0';
        }
        buf[end] = '\0';
        if (n == INT_MIN)
        {
                _add_if_int_min(buf, end - 1);
        }
        return buf;
}

int main()
{
        {
                int n = INT_MAX;
                char buf[16] = "AAAABBBBCCCCDDDD";
                itoa(n, buf);
                assert(strcmp(buf, "2147483647") == 0);
        }
        {
                int n = INT_MIN;
                char buf[16] = "AAAABBBBCCCCDDDD";
                itoa(n, buf);
                assert(strcmp(buf, "-2147483648") == 0);
        }
        {
                int n = 1001;
                char buf[16] = "AAAABBBBCCCCDDDD";
                itoa(n, buf);
                assert(strcmp(buf, "1001") == 0);
        }
        {
                int n = -123;
                char buf[16] = "AAAABBBBCCCCDDDD";
                itoa(n, buf);
                assert(strcmp(buf, "-123") == 0);
        }
        {
                int n = 0;
                char buf[16] = "AAAABBBBCCCCDDDD";
                itoa(n, buf);
                assert(strcmp(buf, "0") == 0);
        }
        {
                int n = -0;
                char buf[16] = "AAAABBBBCCCCDDDD";
                itoa(n, buf);
                assert(strcmp(buf, "0") == 0);
        }
        {
                int n = 100;
                char buf[16] = "AAAABBBBCCCCDDDD";
                itoa(n, buf);
                assert(strcmp(buf, "100") == 0);
        }
        {
                int n = 123;
                char buf[16] = "AAAABBBBCCCCDDDD";
                itoa(n, buf);
                assert(strcmp(buf, "123") == 0);
        }
        print_tc_success();
}
