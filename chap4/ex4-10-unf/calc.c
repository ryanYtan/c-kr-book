/**
 * Exercise 4-10
 *
 * THIS IS BUILT OFF EX4-06
 *
 * An alternate organization uses getline to read an entire input line;
 * this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
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

int pgetline(char s[], int max);
int getop(char []);

int _sp = 0;
double val[MAXVAL];
double vars[26];

/* getline from earlier in chapter 4 */
int pgetline(char s[], int lim)
{
        int c, i = 0;
        while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        if (c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
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
                int bytes_read = pgetline(s, MAXOP);
                if (bytes_read == 1 && s[0] == EOF)
                {
                        break;
                }

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
