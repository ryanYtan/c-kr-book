/**
 * Exercise 2-4
 *
 * Write an alternative version of squeeze(s1,s2) that deletes each character
 * in s1 that matches any character in the string s2
 */
#include <limits.h>
#include <stdio.h>

void squeeze(char s1[], char s2[])
{
        _Bool has_s2_char[CHAR_MAX] = { 0 };
        for (int i = 0; s2[i] != '\0'; i++)
        {
                has_s2_char[s2[i]] = 1;
        }

        int j = 0;
        for (int i = 0; s1[i] != '\0'; i++)
        {
                char c = s1[i];
                if (!has_s2_char[c])
                {
                        s1[j++] = s1[i];
                }
        }
        s1[j] = '\0';
}

int main()
{
        char s1[] = "abcdejkfghiiijk234";
        char s2[] = "ikaj3";
        squeeze(s1, s2);
        printf("%s\n", s1);
}
