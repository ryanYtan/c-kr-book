/**
 * Exercise 5-10
 *
 * Write the program expr, which revaluates a reverse Polish expression
 * from the command line, where each operator or operand is a separate argument.
 * For example,
 *
 * expr 2 3 4 + *
 */
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../utility.h"
#define MAX_NARGS 50

static char *stack[MAX_NARGS] = { 0 };
static int sp = 0;
static char *allowed_ops[] = { "+", "-", "*", "/", "%" };
static int allowed_ops_len = sizeof(allowed_ops) / sizeof(allowed_ops[0]);

void push(char *s)
{
        stack[sp++] = s;
}

char *pop()
{
        if (sp <= 0)
                return NULL;
        return stack[--sp];
}

int size()
{
        return sp;
}

bool is_op(char *s)
{
        for (int i = 0; i < allowed_ops_len; i++)
                if (strcmp(s, allowed_ops[i]) == 0)
                        return true;
        return false;
}

int main(int argc, char *argv[])
{
        if (argc < 2)
        {
                fprintf(stderr, "No arguments given\n");
                return 1;
        }

        for (int i = 0; i < argc; i++)
        {
                char *op = argv[i];
                if (is_op(op))
                {
                        char *op2 = pop();
                        char *op1 = pop();
                        if (op1 == NULL || op2 == NULL)
                        {
                                fprintf(stderr, "Invalid expression\n");
                                return 1;
                        }
                        char *op2_endptr;
                        char *op1_endptr;
                        int op2_i = strtol(op2, &op2_endptr, 10);
                        int op1_i = strtol(op1, &op1_endptr, 10);
                        if (*op1_endptr != '\0' || *op2_endptr != '\0')
                        {
                                fprintf(stderr, "Invalid expression\n");
                                return 1;
                        }
                }
        }

        if (size() != 1)
        {
                fprintf(stderr, "Invalid expression\n");
                return 1;
        }
}
