/**
 * Exercise 1-01
 *
 * Run the "hello, world" program on your system. Experiment
 * with leaving out parts of the program, to see what error messages
 * you get.
 *
 * ::1::
 * Leaving out `int` in `int main()` will throw a compiler warning. This is
 * a generalised warning for all functions that the return type will be
 * default to `int` if no type is specified. This probably did not throw
 * an error in C89 as all return types defaulted to `int` implicitly.
 *
 * ::2::
 * Leaving out some calls to `printf` just doesn't print out certain strings.
 *
 * ::3::
 * Removing the `#include` statement results in the compiler complaining about
 * an implicit declaration of the function `printf`. `printf` is declared in
 * `stdio.h`, so without the `include` I guess the compiler automatically
 * assumes that `printf` comes from `stdio.h`. Compiling with `-Werror` causes
 * this to be a compiler error instead of a warning.
 */
#include <stdio.h>

main()
{
        printf("hello, ");
        printf("world");
        printf("\n");
}
