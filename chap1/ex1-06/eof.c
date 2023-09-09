/**
 * Exercise 1-06
 *
 * Verify that the expression
 *     getchar() != EOF
 * is 0 to 1.
 *
 * Run
 *      echo "0" | ./a.out
 *      touch __f; cat _empty_file | ./a.out; rm __f
 */

#include <stdio.h>

int main()
{
        int c;
        printf("%d\n", getchar() != EOF);
}
