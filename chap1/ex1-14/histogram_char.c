#include <stdio.h>
#define LEN 26

int is_a_letter(int c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int is_upper(int c)
{
    return ('A' <= c && c <= 'Z');
}

int to_lower(int c)
{
    if (is_upper(c))
        c += 'a' - 'A';
    return c;
}

int char_index(int c)
{
    return to_lower(c) - 'a';
}

int main()
{
    int c, nchar[LEN];
    for (int i = 0; i < LEN; ++i)
        nchar[i] = 0;

    while ((c = getchar()) != EOF)
        if (is_a_letter(c))
            ++nchar[char_index(c)];

    for (int i = 0; i < LEN; ++i) {
        printf("%c: ", i + 'a');
        for (int j = 0; j < nchar[i]; ++j)
            printf("#");
        printf("\n");
    }
}
