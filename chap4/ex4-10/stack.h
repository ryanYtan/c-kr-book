/**
 * Exercise 4-10
 *
 * This is a major refactoring of Ex4-06, plus adding the required
 * functionality.
 *
 * An alternate organization uses getline to read an entire input line;
 * this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
 */
#ifndef EX4_10_CALC_STACK_H_INCLUDED
#define EX4_10_CALC_STACK_H_INCLUDED

typedef enum StackResult
{
        SUCCESS,
        ERR_STACK_FULL,
        ERR_STACK_EMPTY,
}
StackResult;

void s_init(int size);
void s_destroy();
StackResult s_push(double v);
StackResult s_pop(double* out);
StackResult s_peek(double* out);
StackResult s_swap();
StackResult s_dupe();
void s_clear();

#endif
