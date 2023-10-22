/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_is_prime.c
*/

#include "my.h"

static
int fast_int_sqrt(int nb)
{
    int k = nb >> 1;

    for (int i = 0; i < 32; i++)
        k = (k + (nb / k)) >> 1;
    return k;
}

int my_is_prime(int nb)
{
    if (nb <= 3)
        return (nb == 2 || nb == 3);
    if (~nb & 1 || (nb % 6 | 4) != 5)
        return 0;
    for (int i = 3; i <= fast_int_sqrt(nb); i += 2) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
