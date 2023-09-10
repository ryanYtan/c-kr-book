/**
 * Exercise 1-16
 *
 * Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of
 * the text.
 */
#include <stdio.h>
#define MAXLINE 1024

/* getline: read a line into s, return length */
int getline_k(char s[], int lim)
{
        int c, i = 0;
        while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        if (c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
}

/* copy: copy `from` into `to`; assume `to` is big enough */
void copy(char to[], char from[])
{
        while ((*to++ = *from++) != 0)
                ;
}

int main()
{
        int len, max = 0;
        char line[MAXLINE] = { 0 };
        char longest[MAXLINE] = { 0 };

        while ((len = getline_k(line, MAXLINE)) > 0)
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }
        if (max > 0)
                printf("%s", longest);
        return 0;
}
