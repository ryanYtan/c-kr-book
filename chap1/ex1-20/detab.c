/**
 * Exercise 1-20
 *
 * Write a program detab that replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 */
#include <assert.h>
#include "../../utility.h"
#define MAXLINE 1024

const int TAB_STOP = 4;

/*
Using 4 space tabs (represented as spaces here)
a   b   cd  efg     h
012345678901234567890

        a
01234567890123456
*/
int read()
{
        int c;
        int len = 0;
        while ((c = getchar()) != EOF && c != '\n') {
                if (c != '\t') {
                        putchar(c);
                        len++;
                        continue;
                }
                if (len % TAB_STOP == 0) {
                        putchar(' ');
                        len++;
                }
                while (len % TAB_STOP != 0) {
                        putchar(' ');
                        len++;
                }
        }
        if (c == '\n' && len > 0)
                putchar('\n');
        return len;
}

int main()
{
        while (read() > 0)
                ;
}
