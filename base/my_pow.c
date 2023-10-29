/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_pow.c
*/


#include "my.h"

int my_pow(int nb, int p)
{
    int r = 1;

    if (p < 0)
        return 0;
    while (p--)
        r *= nb;
    return r;
}
