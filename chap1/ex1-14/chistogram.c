/**
 * Exercise 1-14
 *
 * Write a program to print a histogram of the frequencies of different
 * characters in its input
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#define LEN 26
#define BLOCK "█"
#define HBLOCK "▌"

int main()
{
        int counter['z' + 1] = { 0 };
        int nchars = 0;
        int c;
        while ((c = getchar()) != EOF)
                if (isalpha(c)) {
                        counter[tolower(c)]++;
                        nchars++;
                }

        float proportions['z' + 1] = { 0 };
        for (int i = 'a'; i <= 'z'; i++)
                proportions[i] = ((float)counter[i] / nchars) * 100.0f;

        for (int i = 'a'; i <= 'z'; i++) {
                printf("%c:\t", i);
                float prop = proportions[i];

                if (prop < 0.5) {
                        printf(HBLOCK);
                } else {
                        for (int j = 0; j < (int)floor(prop); j++)
                                printf(BLOCK);
                        if (prop - floor(prop) > 0.5)
                                printf(HBLOCK);
                }
                putchar('\n');
        }
}
