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
#include "stack.h"
#include <stdlib.h>

static int _sp = 0;
static int _stack_max_size;
static double *_stack = NULL;

void s_init(int size)
{
        _sp = 0;
        _stack_max_size = size;
        _stack = malloc(size * sizeof(*_stack));
}

void s_destroy()
{
        free(_stack);
}

StackResult s_push(double v)
{
        if (_sp >= _stack_max_size)
        {
                return ERR_STACK_FULL;
        }
        _stack[_sp++] = v;
        return SUCCESS;
}

StackResult s_pop(double* out)
{
        if (_sp <= 0)
        {
                return ERR_STACK_EMPTY;
        }
        *out = _stack[--_sp];
        return SUCCESS;
}

StackResult s_peek(double* out)
{
        if (_sp <= 0)
        {
                return ERR_STACK_EMPTY;
        }
        *out = _stack[_sp - 1];
        return SUCCESS;
}

StackResult s_swap(void)
{
        if (_sp < 2)
        {
                return ERR_STACK_EMPTY;
        }
        double tmp = _stack[_sp - 1];
        _stack[_sp - 1] = _stack[_sp - 2];
        _stack[_sp - 2] = tmp;
        return SUCCESS;
}

StackResult s_dupe(void)
{
        if (_sp <= 0)
        {
                return ERR_STACK_EMPTY;
        }
        double o;
        s_peek(&o);
        s_push(o);
        return SUCCESS;
}

void s_clear(void)
{
        _sp = 0;
}
