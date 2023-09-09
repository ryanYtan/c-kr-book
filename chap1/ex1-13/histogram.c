/**
 * Exercise 1-13
 *
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal, a vertical
 * orientation is more challenging.
 *
 * I'm assuming the following:
 * 1. No word goes above 20 characters
 * 2. "Words" only contain alphanumeric and digits, everything else is not a word
 *
 * Compile with `-D HORIZONTAL` flag for horizontal printing.
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#define UPPER 20
#define BLOCK "█"
#define HBLOCK "▌"
#define UHBLOCK "▀"

bool isletter(int c)
{
        return isalpha(c) || isdigit(c);
}

int skip()
{
        int c;
        while ((c = getchar()) != EOF && !isletter(c))
                ;
        if (c == EOF)
                return -1;
        ungetc(c, stdin);
        return 0;
}

int read()
{
        int c, len = 0;
        while ((c = getchar()) != EOF && isletter(c)) {
                len++;
        }
        ungetc(c, stdin);
        return len;
}

int main()
{
        int hist[UPPER + 1] = { 0 };
        int nwords = 0;
        int c;

        int word_len = 0;
        while (1) {
                if (skip() == -1)
                        break;
                int word_len = read();
                hist[word_len]++;
                nwords++;
        }

        float proportion[UPPER + 1] = { 0 };
        for (int i = 1; i <= UPPER; i++) {
                proportion[i] = ((float)hist[i] / nwords) * 100.0f;
        }

#ifdef HORIZONTAL
        //prints the histogram horizontally
        for (int i = 1; i <= UPPER; i++) {
                printf("%d:\t", i);
                float prop = proportion[i];
                for (int j = 0; j < (int)floor(prop); j++)
                        printf(BLOCK);
                if (prop - floor(prop) > 0.5)
                        printf(HBLOCK);
                putchar('\n');
        }
#else
        //prints the histogram vertically

        for (int i = 1; i <= UPPER; i++) {
                printf("%4d", i);
        }
        putchar('\n');

        while (1) {
                bool printed = false;
                for (int i = 1; i <= UPPER; i++) {
                        printf("   ");

                        float prop = proportion[i];
                        if (proportion[i] >= 1.0) {
                                printf(BLOCK);
                                printed = true;
                                proportion[i]--;
                        } else if (proportion[i] >= 0.5) {
                                printf(UHBLOCK);
                                printed = true;
                                proportion[i] = 0.0f;
                        } else {
                                putchar(' ');
                        }
                }
                putchar('\n');
                if (!printed)
                        break;
        }
#endif
}
