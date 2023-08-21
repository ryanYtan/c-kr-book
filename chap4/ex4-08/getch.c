/**
 * Exercise 4-08
 *
 * Suppose that there will never be more than one character of pushback. Modify
 * getch and ungetch accordingly.
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../../utility.h"

/* getch and ungetch code BEGIN */
int _c;
int _cp = 0;

int getch(void)
{
        if (_cp)
        {
                _cp = !_cp;
                return _c;
        }
        return getchar();
}

void ungetch(int c)
{
        _cp = 1;
        _c = c;
}
/* getch and ungetch code END */
