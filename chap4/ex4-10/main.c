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
#include "calc.h"
#include "stack.h"
#include "../../utility.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

_Bool pop1(double *op, char *err_msg)
{
        StackResult ret1;
        if ((ret1 = s_pop(op)) != SUCCESS)
        {
                sprintf(err_msg, "\terror: stack is empty");
                return 0;
        }
        return 1;
}

_Bool pop2(double *op1, double *op2, char *err_msg)
{
        if (!pop1(op2, err_msg))
        {
                sprintf(err_msg, "\terror: stack is empty");
                return 0;
        }
        if (!pop1(op1, err_msg))
        {
                sprintf(err_msg, "\terror: stack has not enough elements");
                s_push(*op2); //restore stack state
                return 0;
        }
        return 1;
}

int main(void)
{
        Operation op;
        double op1, op2, result;
        StackResult ret1, ret2;
        char s[1024] = { 0 }; /* just a big buffer */
        char err_msg[1024] = { 0 };

        s_init(100);

        while ((op = getop(s)) != EOF)
        {
                switch (op)
                {
                case NUMBER:
                        result = atof(s); /* no error-handling, sorry */
                        s_push(result);
                        break;
                case SET_VAR:
                        // { 'A' <= s[0] <= 'Z' }
                        if (!pop1(&op1, err_msg))
                                goto fail;
                        set_var(s[0], op1);
                        break;
                case GET_VAR:
                        // { 'a' <= s[0] <= 'z' }
                        s_push(get_var(s[0]));
                        break;
                case ADD:
                        if (!pop2(&op1, &op2, err_msg))
                                goto fail;
                        s_push(op1 + op2);
                        break;
                case SUB:
                        if (!pop2(&op1, &op2, err_msg))
                                goto fail;
                        s_push(op1 - op2);
                        break;
                case MUL:
                        if (!pop2(&op1, &op2, err_msg))
                                goto fail;
                        s_push(op1 * op2);
                        break;
                case DIV:
                        if (!pop2(&op1, &op2, err_msg))
                                goto fail;
                        s_push(op1 / op2);
                        break;
                case MOD:
                        if (!pop2(&op1, &op2, err_msg))
                                goto fail;
                        if (rint(op1) != op1 || rint(op2) != op2)
                                goto fail;
                        if (fabs(op2) < 0.000000000000001)
                                goto fail;
                        s_push((int)op1 % (int)op2);
                        break;
                case SIN:
                        if (!pop1(&op1, err_msg))
                                goto fail;
                        s_push(sin(op1));
                        break;
                case EXP:
                        if (!pop1(&op1, err_msg))
                                goto fail;
                        s_push(exp(op1));
                        break;
                case POW:
                        if (!pop2(&op1, &op2, err_msg))
                                goto fail;
                        s_push(pow(op1, op2));
                        break;
                case SWAP:
                        if ((ret1 = s_swap()) != SUCCESS)
                        {
                                sprintf(err_msg, "\terror: not enough elements in stack");
                                goto fail;
                        }
                        break;
                case CLEAR:
                        s_clear();
                        break;
                case DUPE:
                        s_dupe();
                        break;
                case PEEK:
                        if ((ret1 = s_peek(&op1)) != SUCCESS)
                        {
                                sprintf(err_msg, "\terror: stack is empty");
                                goto fail;
                        }
                        printf("\t%.8g\n", op1);
                        break;
                case END_OF_INPUT:
                        goto cleanup;
                case UNKNOWN:
                        sprintf(err_msg, "\terror: unknown command \"%s\"", s);
                        goto fail;
                }
        }

fail:
        fprintf(stderr, "%s\n", err_msg);
cleanup:
        s_destroy();
}
