/**
 * Exercise 4-06
 *
 * THIS IS BUILT OFF EX4-05
 *
 * Add commands for handling variables. (It's easy to provide 26 variables
 * withsingle-letter names) Add a variable for the most recently printed
 * value.
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
#define SET_VAR 1
#define GET_VAR 2
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);

int _sp = 0;
double val[MAXVAL];
double vars[26];
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
        else
        {
                printf("error: stack empty\n");
                return NAN;
        }
}

double peek(void)
{
        if (_sp > 0)
                return val[_sp - 1];
        else
        {
                printf("error: stack empty\n");
                return NAN;
        }
}

void swap(void)
{
        double ultimate = pop();
        double penultimate = pop();
        push(ultimate);
        push(penultimate);
}

void clear(void)
{
        _sp = 0;
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
                if (isupper(c))
                        return SET_VAR;
                if (islower(c))
                        return GET_VAR;
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
        double op2, result;
        char s[MAXOP];

        while ((type = getop(s)) != EOF)
        {
                switch (type)
                {
                case NUMBER:
                        push(atof(s));
                        break;
                case SET_VAR:
                        op2 = pop();
                        vars[tolower(s[0]) - 'a'] = op2;
                case GET_VAR:
                        push(vars[s[0] - 'a']);
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
                        if (rint(op1) != op1 || rint(op2) != op2)
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
                case '~': /* sin */
                        push(sin(pop()));
                        break;
                case '@': /* exp */
                        push(exp(pop()));
                        break;
                case '^': /* pow */
                        op2 = pop();
                        push(pow(pop(), op2));
                        break;
                case '!': /* swap */
                        swap();
                        break;
                case '$': /* clear */
                        clear();
                        break;
                case '&': /* duplicate top of stack */
                        push(peek());
                        break;
                case '?': /* peek top of stack */
                        printf("\t%.8g\n", peek());
                        break;
                case '\n':
                        //printf("\t%.8g\n", pop());
                        break;
                default:
                        printf("error: unknown command %s\n", s);
                        break;
                }
        }
        return 0;
}
