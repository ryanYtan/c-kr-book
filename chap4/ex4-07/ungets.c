/**
 * Exercise 4-07
 *
 * Write a routine ungets(s) that will push back an entire string onto the
 * input.  Should ungets know about buf and bufp, or should it just use ungetch?
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../../utility.h"

/* getch and ungetch code BEGIN */
char buf[BUFSIZ];
int bufp = 0;

int getch(void)
{
        return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZ)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}
/* getch and ungetch code END */

/*
[ '1' '2' '3' '4' '5' '6' '7' ]

[ '4' '5' '6' '7' ]
char *s = "123";

ungets(s)
[ '3' '2' '1' '4' '5' '6' '7' ]

*/

void ungets(char *s)
{
        size_t n = strlen(s);
        char *t = s + n - 1;
        while (t >= s)
        {
                ungetch(*t);
                t--;
        }
}

int main()
{
        // echo "1234567" | ./a.out

        char t[40] = { 0 };
        for (int i = 0; i < 5; i++)
        {
                t[i] = getch();
        }

        ungets(t);

        int c;
        char *t2 = t;
        while ((c = getch()) != EOF)
        {
                *t2++ = c;
        }
        assert(strcmp(t, "1234567\n") == 0);

        print_tc_success();
}
