/**
 * Exercise 5-04
 *
 * Write the function strend(s,t) which returns 1 if the string t occurs
 * at the end of the string s, and zero otherwise.
 */
#include <string.h>
#include <assert.h>
#include "../../utility.h"

//named pstrcat to not conflict with existing string.h functions
int strend(char s[], char t[])
{
        size_t sn = strlen(s);
        size_t tn = strlen(t);
        if (tn > sn)
                return 0;
        char *s2 = s + sn;
        char *t2 = t + tn;
        while (t2 >= t && (*s2 == *t2))
        {
                t2--;
                s2--;
        }
        return t2 < t;
}

int main()
{
        {
                char s[] = "12345";
                char t[] = "345";
                assert(strend(s, t));
        }
        {
                char s[] = "12345";
                char t[] = "5";
                assert(strend(s, t));
        }
        {
                char s[] = "12345";
                char t[] = "";
                assert(strend(s, t));
        }
        {
                char s[] = "5";
                char t[] = "5";
                assert(strend(s, t));
        }
        {
                char s[] = "5";
                char t[] = "";
                assert(strend(s, t));
        }
        {
                char s[] = "12345";
                char t[] = "245";
                assert(!strend(s, t));
        }
        {
                char s[] = "123";
                char t[] = "023";
                assert(!strend(s, t));
        }
        {
                char s[] = "123";
                char t[] = "0123";
                assert(!strend(s, t));
        }
        print_tc_success();
}
