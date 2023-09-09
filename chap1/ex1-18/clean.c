/**
 * Exercise 1-18
 *
 * Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../../utility.h"
#define BUFSIZ 1024
#define THRESHOLD 10

int main()
{
        char buf[BUFSIZ] = { 0 };

        int c, i = 0;
        while ((c = fgetc(stdin)) != EOF)
        {
                if (c == '\n')
                {
                        if (strlen(buf) > THRESHOLD)
                                printf("%s\n", buf);
                        memset(buf, 0, BUFSIZ);
                        i = 0;
                }
                else
                {
                        buf[i++] = c;
                }
        }
}
