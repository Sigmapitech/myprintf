/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_putnbr_base.c
*/

#include "my.h"

static
void my_putpos_base(int nbr, char const *base, int base_length)
{
    if (nbr >= base_length)
        my_putpos_base(nbr / base_length, base, base_length);
    my_putchar(base[nbr % base_length]);
}

int my_putnbr_base(int nbr, char const *base)
{
    int div = my_strlen(base);
    int abs_n = (nbr >= 0) ? nbr : -nbr;

    if (nbr < 0)
        my_putchar('-');
    if (abs_n >= 0) {
        my_putpos_base(abs_n, base, div);
        return 0;
    }
    my_putpos_base(-(nbr / div), base, div);
    my_putchar(base[-(nbr % div)]);
    return 0;
}
