/**
 * Exercise 1-18
 *
 * Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entire blank lines.
 *
 * In this program, I have printed spaces as plus signs ('+') to check
 * in the printed output whether spaces have been printed out.
 *
 * Unfortunately, this program is not compatible with tabs, only spaces. This
 * is due to the method used to count the number of spaces to not depend on
 * memory/arrays.
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
        bool line_has_chars = false;
        while (1) {
                int nspaces = skip();
                c = getchar();

                if (c == EOF) {
                        break;
                } else if (c == '\n') {
                        if (line_has_chars) {
                                putchar('\n');
                                line_has_chars = false;
                        }
                } else {
                        line_has_chars = true;

                        for (int i = 0; i < nspaces; i++)
                                putchar('+'); //display
                        putchar(c);

                        while ((c = getchar()) != EOF && c != '\n' && c != ' ')
                                putchar(c);

                        if (c == ' ')
                                ungetc(c, stdin);

                        if (c == '\n') {
                                putchar(c);
                                line_has_chars = false;
                        }
                }
        }
}
