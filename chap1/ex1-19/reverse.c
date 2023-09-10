/**
 * Exercise 1-19
 *
 * What a function reverse(s) that reverses the character string s. Use it
 * to write a program that reverses its input a line at a time.
 */
#include <stdio.h>

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

void reverse(char s[])
{
        if (*s == '\0')
                return;
        char *t = s;
        while (*(t + 1) != '\n')
                t++;
        while (s <= t) {
                char tmp = *s;
                *s = *t;
                *t = tmp;
                s++, t--;
        }
}

int main()
{
        char s[1024];
        int len;
        while ((len = getline_k(s, 1024)) > 0) {
                reverse(s);
                printf("%s", s); //newline already in s
        }
}
