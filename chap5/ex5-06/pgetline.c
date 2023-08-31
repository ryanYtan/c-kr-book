#include <stdio.h>
#include <stdlib.h>

int pgetline(char **lineptr, int *n)
{
        char *ptr = *lineptr;
        int bytes_read = 0;

        int c;
        while ((c = fgetc(stdin)) != EOF && c != '\n')
        {
                bytes_read++;
                *ptr++ = c;
        }
        if (c != EOF || c != '\n')
                return 0;
        if (c == '\n')
                *ptr++ = '\n';
        *ptr = '\0';
        if (n != NULL)
                *n = bytes_read;
        return 1;
}
