#include "stack.h"

static int _sp = 0;
static int _stack_max_size = 100;
static double _stack[];

StackError stack_push(double v)
{
        if (_sp >= _stack_max_size)
        {
                return ERR_STACK_FULL;
        }
        _stack[_sp++] = v;
        return SUCCESS;
}

StackError stack_pop(double* out)
{
        if (_sp <= 0)
        {
                return ERR_STACK_EMPTY;
        }
        *out = _stack[--_sp];
        return SUCCESS;
}

StackError stack_peek(double* out)
{
        if (_sp <=  0)
        {
                return ERR_STACK_EMPTY;
        }
        *out = _stack[_sp];
        return SUCCESS;
}

StackError stack_swap(void)
{
        if (_sp < 2)
        {
                return ERR_STACK_EMPTY;
        }
        double tmp = _stack[_sp - 1];
        _stack[_sp - 1] = _stack[_sp - 2];
        _stack[_sp - 2] = tmp;
}

void stack_clear(void)
{
        _sp = 0;
}
