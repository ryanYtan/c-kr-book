/**
 * Exercise 1-4
 * 
 * Write a program to print the corresponding Celsius to Fahrenheit
 * table
 */

#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("Fahrenheit\tCelsius\n");
    while (celsius <= upper) {
        fahr = (celsius * 9.0 / 5.0) + 32.0;
        printf("%6.1f\t\t%3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
