#ifndef EX4_10_CALC_STACK_H_INCLUDED
#define EX4_10_CALC_STACK_H_INCLUDED

typedef enum StackError
{
        SUCCESS,
        ERR_STACK_FULL,
        ERR_STACK_EMPTY,
} StackError;

StackError stack_push(double v);
StackError stack_pop(double* out);
StackError stack_peek(double* out);
void stack_swap(void);
void stack_clear(void);

#endif
