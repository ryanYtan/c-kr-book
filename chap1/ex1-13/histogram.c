/**
 * Exercise 1-13
 *
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal, a vertical
 * orientation is more challenging.
 */

#include <stdio.h>
#define UPPER 20
#define BLOCK '#'

int is_a_letter(int c)
{
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int is_a_separator(int c)
{
        return c == ' ' || c == '\n' || c == '\t';
}

int main()
{
        int hist[UPPER], c, i, j, word_len;
        for (i = 0; i < UPPER; ++i)
                hist[i] = 0;

        word_len = 0;
        while ((c = getchar()) != EOF) {
                if (!is_a_letter(c)) {
                        ++hist[word_len];
                        word_len = 0;
                }
                else if (is_a_separator(c)) {
                        ++hist[word_len];
                        word_len = 0;
                }
                else {
                        ++word_len;
                }
        }

        for (i = 1; i < UPPER; ++i) {
                printf("%d:\t", i);
                for (j = 0; j < hist[i]; ++j) {
                        putchar(BLOCK);
                }
                putchar('\n');
        }
}
