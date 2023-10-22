/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_put_nbr.c
*/

#include "my.h"

static
void cycle_print(int n)
{
    if (n < -9)
        cycle_print(n / 10);
    my_putchar('0' - (n % 10));
}

int my_put_nbr(int n)
{
    if (n >= 0)
        n = -n;
    else
        my_putchar('-');
    cycle_print(n);
    return 0;
}
