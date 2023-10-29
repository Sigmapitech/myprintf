/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** utils.c
*/

#include <stdio.h>
#include <unistd.h>

#include "my.h"

int putnchar(int fd, char c, int nb)
{
    int written;

    for (int n = nb; n--;) {
        written = write(fd, &c, sizeof(char));
        if (written == -1)
            return nb - n;
    }
    return nb;
}

int double_to_str(char *out, double d, unsigned int prec)
{
    int itgr = (int)(d + 1e-10);
    int i;

    d -= itgr;
    i = my_putnbr(out, itgr);
    if (prec) {
        out[i] = '.';
        d = d * my_pow(10, prec) + 0.1;
        i += my_putnbr(out + i + 1, (int)(d));
    }
    return i;
}
