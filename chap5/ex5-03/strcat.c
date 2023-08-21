/**
 * Exercise 5-03
 *
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s
 */
#include <string.h>
#include <assert.h>
#include "../../utility.h"

//named pstrcat to not conflict with existing string.h functions
void strend(char s[], char t[])
{
        while (*s)
                s++;
        while ((*s++ = *t++))
                ;
}

int main()
{
        {
                char s[] = "abcde\0AAAAAAAAAAAAAAAAAAAAAA";
                char t[] = "1234";
                strend(s, t);
                assert(strcmp(s, "abcde1234") == 0);
                assert(s[9] == '\0');
                assert(strlen(s) == 9);
        }
        {
                char s[] = "\0AAAAAAAAAAAAAAAAAAA";
                char t[] = "1234";
                strend(s, t);
                assert(strcmp(s, "1234") == 0);
                assert(s[4] == '\0');
                assert(strlen(s) == 4);
        }
        {
                char s[] = "abcde\0AAAAAAAAAAAAAAAAAAAAAA";
                char t[] = "";
                strend(s, t);
                assert(strcmp(s, "abcde") == 0);
                assert(s[5] == '\0');
                assert(strlen(s) == 5);
        }
        {
                char s[] = "";
                char t[] = "";
                strend(s, t);
                assert(strcmp(s, "") == 0);
                assert(s[0] == '\0');
                assert(strlen(s) == 0);
        }
}
