/**
 * Exercise 3-05
 *
 * Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16) formats
 * n as a hexadecimal integer in s.
 */
#include <string.h>
#include <assert.h>
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

//assume s is large enough
//limit b to [2,16]
void itob(int n, char s[], int b)
{
        int sign = n < 0;
        if (sign)
                n = -n; //might overflow

        char *t = s;
        do
        {
                int div = n % b;
                switch (div)
                {
                case 0: *s++ = '0'; break;
                case 1: *s++ = '1'; break;
                case 2: *s++ = '2'; break;
                case 3: *s++ = '3'; break;
                case 4: *s++ = '4'; break;
                case 5: *s++ = '5'; break;
                case 6: *s++ = '6'; break;
                case 7: *s++ = '7'; break;
                case 8: *s++ = '8'; break;
                case 9: *s++ = '9'; break;
                case 10: *s++ = 'A'; break;
                case 11: *s++ = 'B'; break;
                case 12: *s++ = 'C'; break;
                case 13: *s++ = 'D'; break;
                case 14: *s++ = 'E'; break;
                case 15: *s++ = 'F'; break;
                case 16: *s++ = 'G'; break;
                case 17: *s++ = 'H'; break;
                case 18: *s++ = 'I'; break;
                case 19: *s++ = 'J'; break;
                case 20: *s++ = 'K'; break;
                case 21: *s++ = 'L'; break;
                case 22: *s++ = 'M'; break;
                case 23: *s++ = 'N'; break;
                case 24: *s++ = 'O'; break;
                case 25: *s++ = 'P'; break;
                case 26: *s++ = 'Q'; break;
                case 27: *s++ = 'R'; break;
                case 28: *s++ = 'S'; break;
                case 29: *s++ = 'T'; break;
                case 30: *s++ = 'U'; break;
                case 31: *s++ = 'V'; break;
                case 32: *s++ = 'W'; break;
                default: return; //error
                }
        }
        while ((n /= b) > 0);
        if (sign)
                *s++ = '-';
        *s = '\0';
        reverse(t);
}

int main()
{
        {
                char s[100] = { 0 };
                itob(1236745, s, 16);
                assert(strcmp(s, "12DF09") == 0);
        }
        {
                char s[100] = { 0 };
                itob(983, s, 16);
                assert(strcmp(s, "3D7") == 0);
        }
        {
                char s[100] = { 0 };
                itob(-238748, s, 16);
                assert(strcmp(s, "-3A49C") == 0);
        }
        {
                char s[100] = { 0 };
                itob(-6781247, s, 2);
                assert(strcmp(s, "-11001110111100100111111") == 0);
        }
        {
                char s[100] = { 0 };
                itob(458943, s, 5);
                assert(strcmp(s, "104141233") == 0);
        }
        {
                char s[100] = { 0 };
                itob(123, s, 2);
                assert(strcmp(s, "1111011") == 0);
        }
        {
                char s[100] = { 0 };
                itob(INT_MIN + 1, s, 2);
                assert(strcmp(s, "-1111111111111111111111111111111") == 0);
        }
        //TODO
        //{
        //        char s[100] = { 0 };
        //        itob(INT_MIN, s, 2);
        //        assert(strcmp(s, "-10000000000000000000000000000000") == 0);
        //}
        print_tc_success();
}
