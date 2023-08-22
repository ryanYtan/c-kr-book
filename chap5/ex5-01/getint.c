/**
 * Exercise 5-01
 *
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push a character back on the input.
 */
#include <assert.h>
#include <ctype.h>
#include "../../utility.h"
#define BUFSIZE 100

/* getch & unfetch BEGIN */
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}
/* getch & unfetch END */

int getint(int *pn)
{
        int c, sign;

        //skip spaces
        while (isspace(c = getch()))
                ;

        if (!isdigit(c) && c != EOF && c != '+' && c != '-')
        {
                ungetch(c);
                return 0;
        }

        sign = (c == '-') ? -1 : 1;

        if (c == '+' || c == '-')
        {
                int d = getch();
                if (d == EOF)
                {
                        ungetch(d);
                        ungetch(c);
                        return c;
                }
        }
        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * (*pn) + (c - '0');
        *pn *= sign;
        if (c != EOF)
                ungetch(c);
        return c;
}

int main()
{
        int v;
        printf("ret=%d, v=%d\n", getint(&v), v);
}
