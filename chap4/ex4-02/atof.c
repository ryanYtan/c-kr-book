/**
 * Exercise 4-02
 *
 * Extend atof to handle scientific notation of the form
 *
 * 123.45e-6
 *
 * where a floating point number may be followed by 'e' or 'E' and an optionally
 * signed exponent
 */
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include "../../utility.h"

double atof(char s[])
{
        double val, power;
        int i, sign;

        //skip whitespaces
        for (i = 0; isspace(s[i]); i++)
                ;

        //get number sign
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
                i++;

        //left side of dp
        for (val = 0.0; isdigit(s[i]); i++)
                val = 10.0 * val + (s[i] - '0');

        if (s[i] == '.')
                i++;

        //right side of dp
        for (power = 1.0; isdigit(s[i]); i++)
        {
                val = 10.0 * val + (s[i] - '0');
                power *= 10.0;
        }

        if (s[i] == 'e' || s[i] == 'E')
        {
                i++;

                int exp_sign = s[i] == '-' ? -1 : 1;
                if (s[i] == '-' || s[i] == '+')
                        i++;

                if (s[i] == '\0')
                {
                        //throw error;
                }

                //get exponent
                int exp = 0;
                for (; isdigit(s[i]); i++)
                        exp = (exp * 10) + (s[i] - '0');

                if (s[i] != '\0')
                {
                        //throw error
                }

                for (int _ = 0; _ < exp; _++)
                {
                        power = exp_sign == 1
                                ? power / 10.0
                                : power * 10.0;
                }
        }

        double value = sign * val / power;
        return value;
}

int main()
{
        {
                double expected = 123.45E+7;
                double actual = atof("123.45E+7");
                assert(fabs(expected - actual) < 0.0000000000001);
        }
        {
                double expected = -323.298e-4;
                double actual = atof("-323.298e-4");
                assert(fabs(expected - actual) < 0.0000000000001);
        }
        print_tc_success();
}
