/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_find_prime_sup.c
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb | 1) || nb <= 2)
        return nb <= 2 ? 2 : nb | 1;
    for (nb = (nb | 1) + 2; !my_is_prime(nb); nb += 2);
    return nb;
}
