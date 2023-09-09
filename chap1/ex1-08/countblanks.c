/**
 * Exercise 1-08
 *
 * Write a program to count blanks, tabs and newlines
 */

#include <stdio.h>

int main()
{
        int c, n = 0;
        while ((c = getchar()) != EOF)
        {
                if (c == ' ')
                        n++;
                if (c == '\n')
                        n++;
                if (c == '\t')
                        n++;
        }
        printf("%d\n", n);
}
