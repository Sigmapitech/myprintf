/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_compute_power_rec.c
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 1)
        return p == 0;
    if (p > 1)
        return my_compute_power_rec(nb, p - 1) * nb;
    return nb;
}
