/**
 * Exercise 5-09
 *
 * Rewrite the routines day_of_year and month_day with pointers
 * instead of indexing.
 */
#include "../../utility.h"
#include <assert.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap_year(int year)
{
        int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        return leap;
}

int day_of_year(int year, int month, int day)
{
        if (year < 0)
                return -1;
        if (!(1 <= month && month <= 12))
                return -1;
        int leap = is_leap_year(year);
        if (!(1 <= day && day <= daytab[leap][month]))
                return -1;
        char *ptr = *(daytab + leap);
        char *end = ptr + 13;
        while (ptr != end)
                day += *ptr++;
        return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
        if (year < 0)
        {
                *pmonth = -1, *pday = -1;
                return;
        }

        int leap = is_leap_year(year);

        if (!(1 <= yearday && yearday <= (leap ? 366 : 365)))
        {
                *pmonth = -1, *pday = -1;
                return;
        }

        char *ptr = *(daytab + leap);
        char *end = ptr + 13;

        while (ptr != end && yearday > *ptr)
        {
                *pmonth = 13 - (end - ptr);
                yearday -= *ptr++;
        }

        *pday = yearday;
}

int main()
{
        {
                assert(day_of_year(-1, 6, 15) == -1);

                assert(day_of_year(2000, 0, 15) == -1);
                assert(day_of_year(2000, -1, 15) == -1);
                assert(day_of_year(2000, 6, 15) != -1);
                assert(day_of_year(2000, 12, 15) != -1);
                assert(day_of_year(2000, 13, 15) == -1);

                assert(day_of_year(2000, 6, 0) == -1);
                assert(day_of_year(2000, 6, 1) != -1);

                //feb has 29 days on leap year, 28 on non-leap-year
                assert(day_of_year(2000, 2, 29) != -1);
                assert(day_of_year(2001, 2, 29) == -1);
                assert(day_of_year(2000, 2, 28) != -1);
                assert(day_of_year(2001, 2, 28) != -1);

                //june has 30 days
                assert(day_of_year(2000, 6, 30) != -1);
                assert(day_of_year(2000, 6, 31) == -1);

                //july has 31 days
                assert(day_of_year(2000, 7, 30) != -1);
                assert(day_of_year(2000, 7, 31) != -1);
                assert(day_of_year(2000, 7, 32) == -1);
        }
        {
                int pmonth;
                int pday;

                {
                        month_day(2000, 365, &pmonth, &pday);
                }
        }
}
