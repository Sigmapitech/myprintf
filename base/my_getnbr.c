/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_getnbr.c
*/

#include <limits.h>
#include "my.h"

static
void compute_n(int *np, char s)
{
    int n = *np;
    char next = s & ~'0';

    if (n < (INT_MIN / 10)) {
        *np = 1;
        return;
    }
    n *= 10;
    if (n < (INT_MIN + next)) {
        *np = 1;
        return;
    }
    n -= next;
    *np = n;
}

int my_getnbr(char *str)
{
    int n = 0;
    int negated = 0;

    for (int started = 0; *str != '\0' && n != 1; str++) {
        if (IS_DIGIT(*str)) {
            started |= 1;
            compute_n(&n, *str);
            continue;
        }
        if (*str == '-' && !started) {
            negated++;
            continue;
        }
        if (*str != '+')
            break;
    }
    if (n == 1)
        return 0;
    n = negated & 1 ? n : -n;
    return (!(negated & 1) && n < 0) ? 0 : n;
}
