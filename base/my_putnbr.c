/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_putnbr.c
*/

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_putnbr(char *s, intmax_t n)
{
    int size = n < 0;

    if (n >= 0)
        n = -n;
    else
        *s++ = '-';
    size += my_intlen(n);
    for (int i = my_intlen(n); i != 0; n /= 10)
        s[--i] = -(n % 10) | '0';
    return size;
}
