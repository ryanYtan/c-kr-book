#include <stdio.h>

float fahr_to_celsius(float temp_in_fahr)
{
    return (5.0 / 9.0) * (temp_in_fahr - 32.0);
}

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
        fahr = fahr + step;
    }
    return 0;
}
