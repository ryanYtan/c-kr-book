/**
 * Exercise 2-3
 *
 * Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are '0' through '9', 'a' through 'f',
 * and 'A' through 'F'
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        size_t buf_size = 32;
        char *buf;
        getline(&buf, &buf_size, stdin);
        buf[strcspn(buf, "\n")] = 0;
        printf("%s\n", buf);
}
