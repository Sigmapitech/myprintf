/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <stdio.h>
#include "my.h"

int my_base_len(int base, int n)
{
    int i = 1;

    for (n /= base; n != 0; n /= base)
        i++;
    return i;
}

int my_putnbr_base(char *s, const char *sbase, int n)
{
    int base = 0;

    for (const char *p = sbase; *p != '\0'; ++p)
        base++;
    if (n >= 0)
        n = -n;
    else
        *s++ = '-';
    for (int i = my_base_len(base, n); i != 0; n /= base)
        s[--i] = sbase[-(n % base)];
    return 0;
}
