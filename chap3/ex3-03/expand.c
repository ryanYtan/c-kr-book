/**
 * Exercise 3-03
 *
 * Write a function expand(s1,s2) that expands shorthand notations like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, and be prepared to handle cases like
 * a-b-c and a-z0-9 and -a-z. Arrage that a leading or trailing - is taken
 * literally
 */
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "../../utility.h"

//assume that s has enough space
//returns index of position immediately after the last character inserted
void concat_range(char s[], int *i, char begin, char end)
{
        while (begin <= end)
        {
                s[(*i)++] = begin++;
        }
}


_Bool scan(char s1[], int *i, char s2[], int *j)
{
        if (!s1[*i] || !s1[*i + 1] || !s1[*i + 2] || s1[*i + 1] != '-')
        {
                return 0;
        }

        char begin = s1[*i];
        char end = s1[*i + 2];
        if ((islower(begin) && islower(end) && begin <= end)
                        || (isupper(begin) && isupper(end) && begin <= end)
                        || (isdigit(begin) && isdigit(end) && begin <= end))
        {
                concat_range(s2, j, begin, end);
                *i += 3;
                return 1;
        }
        return 0;
}

//assumptions (following regex-style notation)
//"a-b-c" is treated as range "a-b" followed by "-" and "c"
//"-a-z" is treated as "-" followed by range "a-z"
//"a-z-" is treated as range "a-z" followed by "-"
//invalid ranges (e.g. "a-0" or "A-z" or "Z-A") are treated as normal strings
void expand(char s1[], char s2[])
{
        int i = 0;
        int j = 0;
        while (s1[i] != '\0')
        {
                if (!scan(s1, &i, s2, &j))
                {
                        s2[j++] = s1[i++];
                }
        }
        s2[j] = '\0';
}

int main()
{
        {
                char s1[] = "-";
                char s2[100] = { 0 };
                expand(s1, s2);
                assert(strcmp(s2, "-") == 0);
        }
        {
                char s1[] = "a-";
                char s2[100] = { 0 };
                expand(s1, s2);
                assert(strcmp(s2, "a-") == 0);
        }
        {
                char s1[] = "-a-fZ-Y";
                char s2[100] = { 0 };
                expand(s1, s2);
                assert(strcmp(s2, "-abcdefZ-Y") == 0);
        }
        {
                char s1[] = "-a-fZ-Y";
                char s2[100] = { 0 };
                expand(s1, s2);
                assert(strcmp(s2, "-abcdefZ-Y") == 0);
        }
        {
                char s1[] = "a-f";
                char s2[100] = { 0 };
                expand(s1, s2);
                assert(strcmp(s2, "abcdef") == 0);
        }
        {
                char s1[] = "Aa-fZAA-F";
                char s2[100] = { 0 };
                expand(s1, s2);
                assert(strcmp(s2, "AabcdefZAABCDEF") == 0);
        }
        print_tc_success();
}
