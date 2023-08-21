/**
 * Exercise 4-03
 *
 * Given the basic framework, it's straightforward to extend the calculator. Add
 * the modulus (%) operator and provisions for negative numbers.
 */
#include <assert.h>
#include "../../utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXVAL 100
#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);

int _sp = 0;
double val[MAXVAL];
char buf[BUFSIZ];
int bufp = 0;

void push(double f)
{
        if (_sp < MAXVAL)
                val[_sp++] = f;
        else
                printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
        if (_sp > 0)
                return val[--_sp];
        else {
                printf("error: stack empty\n");
                return 0.0;
        }
}

int getch(void)
{
        return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZ)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}

int getop(char s[])
{
        int i = 0;
        int c;
        int is_negative = 0;

        while ((s[0] = c = getch()) == ' '|| c == '\t')
                ;
        s[1] = '\0';

        //read number
        //this won't work for e.g. "-.2"
        if (c == '-')
        {
                c = getch();
                is_negative = 1;
        }

        if (!isdigit(c) && c != '.')
        {
                if (is_negative)
                {
                        ungetch(c);
                        return '-';
                }
                return c; //not a number
        }

        if (is_negative)
        {
                s[++i] = c; //add first number to buffer
        }

        if (isdigit(c))
                 while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.')
                while (isdigit(s[++i] = c = getch()))
                        ;
        s[i] = '\0';
        if (c != EOF)
                ungetch(c);
        return NUMBER;
}

int main(void)
{
        int type;
        double op2;
        char s[MAXOP];

        while ((type = getop(s)) != EOF)
        {
                switch (type)
                {
                case NUMBER:
                        push(atof(s));
                        break;
                case '+':
                        push(pop() + pop());
                        break;
                case '*':
                        push(pop() * pop());
                        break;
                case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                case '/':
                        op2 = pop();
                        if (op2 != 0.0)
                                push(pop() / op2);
                        else
                                printf("error: zero divisor\n");
                        break;
                case '%':
                        op2 = pop();
                        double op1 = pop();
                        if (rintf(op1) != op1 || rintf(op2) != op2)
                        {
                                printf("error: mod only works on integers\n");
                        }
                        else if (op2 == 0.0)
                        {
                                printf("error: attempted to mod by zero\n");
                        }
                        else
                        {
                                push((int)op1 % (int)op2);
                        }
                        break;
                case '\n':
                        printf("\t%.8g\n", pop());
                        break;
                default:
                        printf("error: unknown command %s\n", s);
                        break;
                }
        }
        return 0;
}
