/**
 * Exercise 1-12
 *
 * Write a program that prints its input one word per line
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
        int c;
        bool line_has_chars = false;
        while ((c = getchar()) != EOF) {
                if (isspace(c)) {
                        if (line_has_chars) {
                                putchar('\n');
                                line_has_chars = false;
                        }
                } else {
                        putchar(c);
                        line_has_chars = true;
                }
        }
}
