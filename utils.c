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
    for (int n = nb; n--;)
        write(fd, &c, sizeof(char));
    return nb;
}

static
int put_in_str(char *out, char *in)
{
    int i;

    for (i = 0; in[i] != '\0'; i++)
        out[i] = in[i];
    out[i] = in[i];
    return i;
}

int double_to_str(char *out, double d, unsigned int prec)
{
    int itgr = (int)(d + 1e-10);
    int i = 0;
    dpart_t dpart = { (BITS(d) >> 63) & 1,
        (BITS(d) >> 52) & 0x7ff, BITS(d) & 0x000fffffffffffffL };

    if (dpart.exponant == 0x7ff) {
        if (dpart.mentissa == 0)
            return put_in_str(out, (char *)(dpart.sign ? "-inf" : "inf"));
        return put_in_str(out, (char *)"nan");
    }
    if (dpart.sign)
        i += put_in_str(out, (char *)"-");
    d -= itgr;
    i += my_putnbr(out + (dpart.sign ? 0 : 1), itgr);
    if (prec) {
        out[i] = '.';
        d = d * my_pow(10, prec) + 0.1;
        i += my_putnbr(out + i + 1, (int)(d));
    }
    return i;
}
