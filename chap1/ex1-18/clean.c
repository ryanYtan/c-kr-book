/**
 * Exercise 1-18
 *
 * Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entire blank lines.
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "../../utility.h"

int skip()
{
        int c, count = 0;
        while ((c = getchar()) != EOF && c == ' ')
                count++;
        ungetc(c, stdin);
        return count;
}

int main()
{
        int c;
        int nchars_for_line = 0;
        while (1)
        {
                int nspaces = skip();
                c = getchar();

                if (c == EOF)
                {
                        break;
                }
                else if (c == '\n')
                {
                        if (nchars_for_line > 0)
                                putchar('\n');
                }
                else
                {
                        for (int i = 0; i < nspaces; i++)
                                putchar(' ');

                        putchar(c);
                        nchars_for_line++;
                        while ((c = getchar()) != EOF && c != '\n' && c != ' ')
                        {
                                putchar(c);
                                nchars_for_line++;
                        }

                        if (c == ' ')
                        {
                                ungetc(c, stdin);
                        }
                        if (c == '\n')
                        {
                                putchar(c);
                        }
                }
        }
}
