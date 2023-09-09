/**
 * Exercise 1-04
 *
 * Write a program to print the corresponding Celsius to Fahrenheit
 * table
 */

#include <stdio.h>

int main()
{
        int lower = 0;
        int upper = 300;
        int step = 20;

        float celsius = lower;
        printf("Fahrenheit\tCelsius\n");
        while (celsius <= upper) {
                float fahr = (celsius * 9.0 / 5.0) + 32.0;
                printf("%6.1f\t\t%3.0f\n", celsius, fahr);
                celsius = celsius + step;
        }
}
