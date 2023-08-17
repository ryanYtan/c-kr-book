/**
 * Exercise 3-01
 *
 * Our binary search makes two tests inside the loop, when one would suffice (at
 * the price of more tests outside). Write a version with only one test inside
 * the loop and measure the difference in run-time
 */
#define N 500000000
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include "../../utility.h"

double time_taken(long (*search)(long, long[], long), long x, long v[], long n)
{
        clock_t tic = clock();
        long _ = search(x, v, n); //assumed to be correct
        clock_t toc = clock();
        return ((double)(toc - tic) / (double)CLOCKS_PER_SEC);
}

long binsearch(long x, long v[], long n)
{
        long low, high, mid;
        low = 0;
        high = n - 1;
        while (low <= high)
        {
                mid = (low + high) / 2;
                if (x < v[mid])
                        high = mid - 1;
                else if (x > v[mid])
                        low = mid + 1;
                else /* found match */
                        return mid;
        }
        return -1; /* no match */
}

// Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside). Write a version with only one test inside
// the loop and measure the difference in run-time
long mybinsearch(long x, long v[], long n)
{
        long low, high, mid, ret;
        low = 0;
        high = n - 1;
        ret = -1;
        while (low <= high && v[mid = (low + high) / 2] != x)
        {
                if (x < v[mid])
                        high = mid - 1;
                else
                        low = mid + 1;
        }
        return v[mid] == x ? mid : -1;
}

long linearsearch(long x, long v[], long n)
{
        for (long i = 0; i < n; i++)
        {
                if (v[i] == x)
                        return i;
        }
        return -1;
}

int main()
{
        long v[] = { 0, 1, 2, 4, 5, 7, 9, 10, 23, 15, 17, 18, 19 };
        long n = sizeof(v) / sizeof(v[0]);
        for (long i = 0; i <= 20; i++)
        {
                long result = mybinsearch(i, v, n);
                long true_index = linearsearch(i, v, n);
                if (true_index == -1)
                        assert(result == -1);
                else
                        assert(result == true_index);
        }
        print_tc_success();


        //init some data
        long *arr = malloc(N * sizeof(*arr));
        for (long i = 0; i < N; i++)
                arr[i] = i;

        //test
        double time1 = time_taken(&binsearch, (3.0 / 4.0)*N, arr, N);
        double time2 = time_taken(&mybinsearch, (3.0 / 4.0)*N, arr, N);

        printf("ORIGINAL: %lf\n", time1);
        printf("MODIFIED: %lf\n", time2);
}
