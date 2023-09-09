/**
 * Exercise 1-15
 *
 * Rewrite the temperature conversion program of Section 1.2 to use a
 * function for conversion.
 */
#include <stdio.h>

float fahr_to_celsius(float temp_in_fahr)
{
        return (5.0 / 9.0) * (temp_in_fahr - 32.0);
}

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
        int lower = 0;
        int upper = 300;
        int step = 20;

        float fahr = lower;
        while (fahr <= upper) {
                printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
                fahr = fahr + step;
        }
}
