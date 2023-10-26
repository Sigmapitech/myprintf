/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_putnbr.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_putnbr(char *s, int n)
{
    if (n >= 0)
        n = -n;
    else
        *s++ = '-';
    for (int i = my_intlen(n); i != 0; n /= 10)
        s[--i] = -ABS((n % 10)) | '0';
    return 0;
}
