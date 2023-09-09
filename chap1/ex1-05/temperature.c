/**
 * Exercise 1-05
 *
 * Modify the temperature conversion program to print the
 * table in reverse order, this is, from 300 degrees to 0.
 */

#include <stdio.h>

int main()
{
        int lower = 0;
        int upper = 300;
        int step = 20;

        printf("Celsius\tFahrenheit\n");
        for (float fahr = upper; fahr >= lower; fahr -= step) {
                float celsius = (5.0 / 9.0) * (fahr - 32.0);
                printf("%3.0f\t%6.1f\n", fahr, celsius);
        }
}
