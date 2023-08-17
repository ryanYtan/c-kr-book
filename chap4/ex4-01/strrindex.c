/**
 * Exercise 4-01
 *
 * Write the function strrindex(s,t) which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 */
#include <assert.h>
#include <string.h>
#include "../../utility.h"

// 7
// abcdefg
// abcdef
// 6

int match(char haystack[], char needle[])
{
        while (*needle != '\0' && *haystack == *needle)
        {
                haystack++;
                needle++;
        }
        return *needle == '\0';
}

int strrindex(char s[], char t[])
{
        int sn = strlen(s);
        int tn = strlen(t);

        if (tn > sn)
        {
                return -1;
        }

        int rmost = -1;
        for (int i = 0; i < sn - tn + 1; i++, s++)
        {
                if (match(s, t))
                {
                        rmost = i;
                }
        }
        return rmost;
}

int main()
{
        //          0       8       16
        char s[] = "shishiiishiiishiiiish";
        assert(strrindex(s, "ish") == 18);
        assert(strrindex(s, "shi") == 13);
        assert(strrindex(s, "i") == 18);
        assert(strrindex(s, "shiiih") == -1);
        assert(strrindex(s, "shishi") == 0);
        assert(strrindex(s, "shishiiishiiishiiiish") == 0);
        assert(strrindex(s, "shishiiishiiishiiiishs") == -1);
        print_tc_success();
}
