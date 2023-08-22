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
#ifndef EX4_10_CALC_H_INCLUDED
#define EX4_10_CALC_H_INCLUDED

typedef enum Operation
{
        NUMBER,

        SET_VAR,
        GET_VAR,

        /* common operators */
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,

        /* math functions */
        SIN,
        EXP,
        POW,

        /* stack operations */
        SWAP,
        CLEAR,
        DUPE,
        PEEK,

        /* end of input reached */
        END_OF_INPUT,

        /* unknown cmmand */
        UNKNOWN,
}
Operation;

Operation getop(char s[]);
void set_var(char var, double value);
double get_var(char var);

#endif
