/**
 * Exercise 4-10
 *
 * This is a major refactoring of Ex4-06, plus adding the required
 * functionality.
 *
 * An alternate organization uses getline to read an entire input line;
 * this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
 */
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include "calc.h"
#define PBUFSIZ 1024

static char buf[PBUFSIZ] = {0};
static char *bufp = &buf[0];
static double vars[26] = { 0 };

/* getline from earlier in chapter 4 */
int pgetline(char s[], int lim)
{
        int c, i = 0;
        while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
}

_Bool at_end_of_buffer()
{
        return (bufp - buf >= PBUFSIZ) || *bufp == '\0';
}

void reset_buffer()
{
        memset(buf, 0, PBUFSIZ);
        bufp = &buf[0];
}

void skip_spaces()
{
        while (!at_end_of_buffer() && *bufp == ' ')
        {
                bufp++;
        }
}

Operation getop(char s[])
{
        skip_spaces();
        if (at_end_of_buffer())
        {
                reset_buffer();
                pgetline(buf, PBUFSIZ);
        }

        int si = 0;
        int is_negative = 0;

        if (*bufp == '-')
        {
                s[si++] = *bufp++;
                is_negative = 1;
        }

        if (!isdigit(*bufp) && *bufp != '.')
        {
                int c;

                if (is_negative)
                {
                        c = *(bufp - 1);
                }
                else
                {
                        c = *bufp;
                        bufp++;
                }

                if (isupper(c))
                {
                        s[0] = c;
                        return SET_VAR;
                }
                if (islower(c))
                {
                        s[0] = c;
                        return GET_VAR;
                }

                switch (c)
                {
                case '+':
                        return ADD;
                case '-':
                        return SUB;
                case '*':
                        return MUL;
                case '/':
                        return DIV;
                case '%':
                        return MOD;
                case '~': /* sin */
                        return SIN;
                case '@': /* exp */
                        return EXP;
                case '^': /* pow */
                        return POW;
                case ',': /* swap */
                        return SWAP;
                case '&': /* dupe */
                        return DUPE;
                case '$': /* clear */
                        return CLEAR;
                case '?': /* peek */
                        return PEEK;
                default:
                        return UNKNOWN;
                }
        }


        //read digits
        while (isdigit(*bufp))
        {
                s[si++] = *bufp++;
        }

        if (*bufp == '.')
        {
                s[si++] = *bufp++;
                while (isdigit(*bufp))
                {
                        s[si++] = *bufp++;
                }
        }
        s[si] = '\0';

        if (*bufp == EOF)
                return END_OF_INPUT;

        return NUMBER;
}

void set_var(char varname, double value)
{
        varname = tolower(varname);
        vars[varname - 'a'] = value;
}

double get_var(char varname)
{
        varname = tolower(varname);
        return vars[varname - 'a'];
}
