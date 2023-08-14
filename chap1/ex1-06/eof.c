/**
 * Exercise 1-6
 *
 * Verify that the expression
 *     getchar() != EOF
 * is 0 to 1.
 */

#include <stdio.h>

int main()
{
    int c;
    printf("%d\n", getchar() != EOF);
}
