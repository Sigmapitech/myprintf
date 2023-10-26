/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <stdio.h>
#include "my.h"

int my_base_len(int base, size_t n)
{
    int i = 1;

    for (n /= base; n != 0; n /= base)
        i++;
    return i;
}

int my_putnbr_base(char *s, const char *sbase, size_t n)
{
    int base = 0;

    for (const char *p = sbase; *p != '\0'; ++p)
        base++;
    for (int i = my_base_len(base, n); i > 0; n /= base)
        s[--i] = sbase[n % base];
    return 0;
}
