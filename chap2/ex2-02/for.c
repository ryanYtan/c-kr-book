/**
 * Exercise 2-2
 *
 * Write a loop equivalent to the for loop above without using
 * && or ||.
 */


/*
for (i = 0; i < lim - 1 && (char = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
*/

#include <stdio.h>

int getline_k(char[], int);

int main()
{
        char s[] = "example";
        int lim = 100;
        getline_k(s, lim);
}

int getline_k(char s[], int lim)
{
        int c, i;
        i = 0;
        while (i < lim - 1)
        {
                if ((c = getchar()) == EOF)
                        goto destroyed;
                if (c == '\n')
                        goto destroyed;
                ++i;
        }

destroyed:
        if (c == '\n')
        {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}
