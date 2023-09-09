/**
 * Exercise 1-17
 *
 * Write a program to print all input lines that are longer than 80 characters.
 *
 * (For easier testing, I've set the limit at 10 characters instead of 80)
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "../../utility.h"
#define THRESHOLD 10

//Reads `limit` number of characters into `buf`, until a newline is encountered.
//Returns the number of characters read.
//If EOF is encountered while reading, returns -1
int read_into(char buf[], int limit)
{
        int c, i = 0;
        while (i < limit && (c = getchar()) != EOF && c != '\n')
        {
                buf[i++] = c;
        }
        if (c == EOF)
                return -1;
        return i;
}

int main()
{
        char buf[THRESHOLD + 1] = { 0 };
        while (1)
        {
                int len = read_into(buf, THRESHOLD + 1);
                if (len == -1)
                        break;
                if (len >= THRESHOLD + 1)
                {
                        for (int j = 0; j < THRESHOLD + 1; j++)
                                putchar(buf[j]);
                        int c;
                        while ((c = getchar()) != EOF && c != '\n')
                                putchar(c);
                        putchar('\n');
                }
                memset(buf, 0, THRESHOLD);
        }
}
