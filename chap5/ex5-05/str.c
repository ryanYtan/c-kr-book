/**
 * Exercise 5-05
 *
 * Write versions  of the library functions strncpy, strncat, and strncmp; which
 * operate on at most the first n characters of their argument strings. For
 * example, strncpy (s,t ,n) copies at most n characters of t to s.  Full
 * descriptions are in Appendix B.
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../../utility.h"

char *pstrncpy(char *s, const char *t, size_t n)
{
        size_t i = 0;
        while (i < n && *t)
        {
                *s++ = *t++;
                i++;
        }
        while (i++ < n)
                *s = '\0';
        return s;
}

char *pstrncat(char *s, const char *t, size_t n)
{
        char *tmp = s;
        //traverse to the end
        while (*s)
                s++;

        size_t i = 0;
        while (i++ < n && *t)
                *s++ = *t++;
        *s = '\0';
        return tmp;
}

int pstrncmp(const char *s, const char *t, size_t n)
{
        size_t i = 0;
        while (i < n && *s && *t && *s == *t)
                i++, s++, t++;
        if (i == n || *s == '\0' || *t == '\0')
                return 0;
        else
                return *s - *t;
}

int main(void)
{
        //strncmp
        {
                char s[] = "cdef";
                char t[] = "abcdefgh";
                assert(pstrncmp(s, t, 1) > 0);
                assert(pstrncmp(s, t, 10) > 0);

                assert(pstrncmp(s, t + 1, 1) > 0);
                assert(pstrncmp(s, t + 1, 10) > 0);

                assert(pstrncmp(s, t + 2, sizeof(s)) == 0);
                assert(pstrncmp(s, t + 2, 10) == 0);
                assert(pstrncmp(s, t + 2, 2) == 0);

                assert(pstrncmp(s + 3, t + 5, 1) == 0);
                assert(pstrncmp(s + 3, t + 5, 2) == 0);
                assert(pstrncmp(s + 3, t + 5, 10) == 0);
        }
        {
                char s[] = "cdeg";
                char t[] = "cdef";
                assert(pstrncmp(s, t, 1) == 0);
                assert(pstrncmp(s, t, 2) == 0);
                assert(pstrncmp(s, t, 3) == 0);
                assert(pstrncmp(s, t, 4) > 0);
                assert(pstrncmp(t, s, 4) < 0);
        }

        //strncat
        {
                char s[] = "abcdef";
                char t[] = "123456";
                pstrncat(s + 2, t, sizeof(t));
                assert(strcmp(s, "abcdef123456") == 0);
        }
        {
                char s[] = "abcdef";
                char t[] = "123456";
                pstrncat(s + 6, t, sizeof(t));
                assert(strcmp(s, "abcdef123456") == 0);
        }
        {
                char s[] = "abcdef";
                char t[] = "123456";
                pstrncat(s, t, 10);
                assert(strcmp(s, "abcdef123456") == 0);
        }
        {
                char s[] = "abcdef";
                char t[] = "";
                pstrncat(s + 6, t, sizeof(t));
                assert(strcmp(s, "abcdef") == 0);
        }
        {
                char s[] = "abcdef";
                char t[] = "0";
                pstrncat(s, t, sizeof(t));
                assert(strcmp(s, "abcdef0") == 0);
        }

        //strncpy
        {
                char s[40] = "AAAAAAAAAAAAAAAAAAAAAAAAAA";
                char t[] = "zzzz";
                pstrncpy(s + 3, t, sizeof(t));
                assert(strcmp(s, "AAAzzzzAAAAAAAAAAAAAAAAAAA") == 0);
        }
        {
                char s[] = "AAAAAAAA";
                char t[] = "abcdef";
                pstrncpy(s, t, 1);
                assert(strcmp(s, "aAAAAAAA") == 0);
        }
        {
                char s[] = "12345\0A";
                char t[] = "abcde";
                pstrncpy(s, t, sizeof(t));
                assert(strcmp(s, "abcde") == 0);
        }
        {
                char s[] = "12345\0A";
                char t[] = "abcdef";
                pstrncpy(s, t, sizeof(t));
                assert(strcmp(s, "abcdefA") == 0);
        }
        {
                char s[] = "AAAAAAAA\0B";
                char t[] = "abcdef";
                pstrncpy(s + 5, t, 3);
                assert(strcmp(s, "AAAAAabc") == 0);
        }
        print_tc_success();
}
