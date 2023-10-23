/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_getnbr_base.c
*/

#include <stddef.h>

#include "limits.h"
#include "my.h"

static
int str_contains(char const *str, char c)
{
    int i = 0;

    for (; *str != '\0'; i++)
        if (*str++ == c)
            return i;
    return -1;
}

static
int compute_n(int np, char s, char const *base)
{
    int n = np;
    char next = str_contains(base, s);
    int base_len = my_strlen(base);

    if (n < (INT_MIN / base_len))
        return 1;
    n *= base_len;
    if (n < (INT_MIN + next))
        return 1;
    return n - next;
}

static
int compute_real_value(int n, int negated)
{
    if (n == 1)
        return 0;
    n = negated & 1 ? n : -n;
    return (!(negated & 1) && n < 0) ? 0 : n;
}

int my_getnbr_base(char *str, char const *base)
{
    int n = 0;
    int negated = 0;

    if (str == NULL || base == NULL)
        return 0;
    for (int started = 0; *str != '\0' && n != 1; str++) {
        if (str_contains(base, *str) != -1) {
            started |= 1;
            n = compute_n(n, *str, base);
            continue;
        }
        if (*str == '-' && !started) {
            negated++;
            continue;
        }
        if (*str != '+')
            break;
    }
    return compute_real_value(n, negated);
}
