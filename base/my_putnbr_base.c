/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_putnbr_base.c
*/

#include <stdio.h>
#include "../my.h"

int my_base_len(int base, size_t n)
{
    int i = 1;

    for (n /= base; n != 0; n /= base)
        i++;
    return i;
}

int my_putnbr_base(char *s, size_t base, size_t n)
{
    int len = my_base_len(base, n);

    for (int i = len; i > 0; n /= base) {
        i--;
        s[i] = BASE_CHARSET[n % base];
    }
    return len;
}
