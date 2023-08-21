/**
 * Exercise 4-09
 *
 * Our getch and ungetch do not handle a pushed-back EOF correctly.
 * Decide what their properties ought to be if an EOF is pushed back, then
 * implement your design.
 *
 * MY ANSWER
 * 1. ungetch(EOF) should terminate the input stream
 * 2. if EOF is the next in buffer, getch() should return the EOF. Further
 *    calls should return EOF
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../../utility.h"

/* getch and ungetch code BEGIN */
int buf[BUFSIZ];
int bufp = 0;
int eof_seen = 0;

int getch(void)
{
        if (eof_seen)
                return EOF;
        int c;
        if (bufp > 0)
                c = buf[--bufp];
        else
                c = getchar();
        if (c == EOF)
                eof_seen = 1;
        return c;
}

void ungetch(int c)
{
        if (bufp >= BUFSIZ)
                printf("ungetch: too many characters\n");
        else
        {
                if (c == EOF)
                        eof_seen = 1;
                buf[bufp++] = c;
        }
}
/* getch and ungetch code END */

int main()
{
        {
                ungetch('1');
                ungetch('2');
                ungetch('3');
                assert(getch() == '3');
                ungetch(EOF);
                assert(getch() == EOF);
                assert(getch() == EOF);
                assert(getch() == EOF);
        }
}
