/**
 * Exercise 1-23
 *
 * Write a program to remove all comments from a C program. Don't forget
 * to handle quoted strings and character constants properly. C comments
 * do not nest.
 */
#include <stdio.h>
#include <stdbool.h>

bool follows(char s)
{
        int c = getchar();
        if (c != s) {
                ungetc(c, stdin);
                return false;
        }
        return true;
}

bool follows2(char a, char b)
{
        int c = getchar();
        if (c != a)
                goto follows2_fail1;
        int d = getchar();
        if (d != b)
                goto follows2_fail2;
        return true;
//using goto to stack unwind
follows2_fail2:
        ungetc(d, stdin);
follows2_fail1:
        ungetc(c, stdin);
        return false;
}

void read_rest(char target)
{
        while (!follows(target)) {
                if (follows2('\\', target)) {
                        putchar('\\');
                        putchar(target);
                } else {
                        int c = getchar();
                        if (c == EOF)
                                return;
                        putchar(c);
                }
        }
        putchar(target);
}

void discard_inline_comment()
{
        int c;
        while ((c = getchar()) != EOF && c != '\n')
                ;
        putchar('\n');
}

void discard_multiline_comment()
{
        while (!follows2('*', '/'))
                if (getchar() == EOF)
                        return;
}

int main()
{
        while (1) {
                if (follows('"')) {
                        putchar('"');
                        read_rest('"');
                } else if (follows('\'')) {
                        putchar('\'');
                        read_rest('\'');
                } else if (follows2('/', '/')) { //discard rest of the line
                        discard_inline_comment();
                } else if (follows2('/', '*')) {
                        discard_multiline_comment();
                } else {
                        int c = getchar();
                        if (c == EOF)
                                break;
                        putchar(c);
                }
        }
}
