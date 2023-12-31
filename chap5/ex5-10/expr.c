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
#include <math.h>
#include "../../utility.h"
#define MAX_NARGS 50
#define MAX_SLEN 256

static char stack[MAX_NARGS][MAX_SLEN] = {{ 0 }};
static int sp = 0;

static char *binops[] = {  "+", "-", "*", "/", "%", };
static int binops_len = sizeof(binops) / sizeof(binops[0]);
static char *unops[] = { "sin", "sqrt", };
static int unops_len = sizeof(unops) / sizeof(unops[0]);

void stack_push(char *s)
{
        strcpy(stack[sp++], s);
}

void stack_pop(char *s)
{
        if (sp <= 0)
                *s = 0;
        else
                strcpy(s, stack[--sp]);
}

int stack_size()
{
        return sp;
}

bool is_in(char *s, char *a[], int alen)
{
        for (int i = 0; i < alen; i++)
                if (strcmp(s, a[i]) == 0)
                        return true;
        return false;
}

int main(int argc, char *argv[])
{
        if (argc < 2)
        {
                fprintf(stderr, "Not enough arguments\n");
                return 0;
        }

        char op1[256];
        char op2[256];

        for (int i = 1; i < argc; i++)
        {
                char *arg = argv[i];
                if (is_in(arg, unops, unops_len))
                {
                        stack_pop(op1);
                        if (*op1 == '\0')
                        {
                                fprintf(stderr, "Not enough arguments for operator\n");
                                return 1;
                        }

                        double n = atof(op1);

                        if (strcmp(arg, "sin") == 0)
                                n = sin(n);
                        else
                                n = sqrt(n);

                        char buf[1024] = { 0 };
                        sprintf(buf, "%lf", n);
                        stack_push(buf);
                }
                else if (is_in(arg, binops, sizeof(binops) / sizeof(binops[0])))
                {
                        stack_pop(op2);
                        stack_pop(op1);
                        if (*op1 == '\0' || *op2 == '\0')
                        {
                                fprintf(stderr, "Not enough arguments for operator\n");
                                return 1;
                        }

                        double n2 = atof(op2);
                        double n1 = atof(op1);

                        if (strcmp(arg, "+") == 0)
                                n1 = n1 + n2;
                        else if (strcmp(arg, "-") == 0)
                                n1 = n1 - n2;
                        else if (strcmp(arg, "*") == 0)
                                n1 = n1 * n2;
                        else if (strcmp(arg, "/") == 0)
                                n1 = n1 / n2;
                        else
                                n1 = (int)n1 % (int)n2;

                        char buf[1024] = {0};
                        sprintf(buf, "%lf", n1);
                        stack_push(buf);
                }
                else
                {
                        stack_push(arg);
                }
        }

        char buf[1024] = {0};

        if (stack_size() != 1)
        {
                fprintf(stderr, "Invalid expression\n");
                return 1;
        }

        stack_pop(buf);
        printf("%s\n", buf);
}
