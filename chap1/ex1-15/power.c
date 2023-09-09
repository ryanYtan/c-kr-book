#include <stdio.h>

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
        int p = 1;
        for (int i = 1; i <= n; ++i)
                p = p * base;
        return p;
}

/* test power function */
int main()
{
        int i;

        for (i = 0; i < 10; ++i)
                printf("%d %d %d\n", i, power(2, i), power(-3, i));
        return 0;
}
