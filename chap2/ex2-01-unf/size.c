/**
 * Exercise 2-1
 *
 * Write a program to determine the ranges of char, short, int and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */
#include <float.h>
#include <limits.h>
#include <stdio.h>

int get_char_max()
{

        char c;
        c = 1;
        while (c > 0) // assumes c will wrap
                c++;
        c -= 1;
        return (int)c;
}

int get_char_min()
{
        char c;
        c = -1;
        while (c < 0)
                c--;
        c += 1;
        return (int)c;
}

int main()
{
        printf("Using <limits.h>\n");
        printf("[SHRT_MIN...SHRT_MAX] = [%d...%d]\n", SHRT_MIN, SHRT_MAX);
        printf("[CHAR_MIN...CHAR_MAX] = [%d...%d]\n", CHAR_MIN, CHAR_MAX);
        printf("[INT_MIN...INT_MAX] = [%d...%d]\n", INT_MIN, INT_MAX);
        printf("[LONG_MIN...LONG_MAX] = [%zu...%zu]\n", LONG_MIN, LONG_MAX);
        printf("USHRT_MAX = %d\n", USHRT_MAX);
        printf("UINT_MAX = %u\n", UINT_MAX);
        printf("UCHAR_MAX = %d\n", UCHAR_MAX);
        printf("ULONG_MAX = %zu\n", ULONG_MAX);

        printf("\n");

        printf("By direct computation\n");
        printf("CHAR_MAX = %d\n", get_char_max());
        printf("CHAR_MIN = %d\n", get_char_min());
}
