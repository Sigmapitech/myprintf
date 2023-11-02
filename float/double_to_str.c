/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** utils.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

static
int put_in_str(char *out, const char *in)
{
    int i;

    for (i = 0; in[i] != '\0'; i++)
        out[i] = in[i];
    out[i] = in[i];
    return i;
}

static
double d_abs(double d)
{
    unsigned long long i = (BITS(d) << 1) >> 1;

    return *(double *)&i;
}

static
int handle_non_numbers(char *out, dpart_t dpart)
{
    if (dpart.mentissa != 0)
        return put_in_str(out, "nan");
    return put_in_str(out, dpart.sign ? "-inf" : "inf");
}

static
dpart_t init_dpart(double d)
{
    dpart_t dpart = {
        .sign = (BITS(d) >> 63) & 1,
        .exponant = (BITS(d) >> 52) & 0x7ff,
        .mentissa = BITS(d) & 0x000fffffffffffffL
    };

    return dpart;
}

int double_to_str(char *out, double d, unsigned int prec)
{
    int itgr = (int)d_abs(d);
    int i = 0;
    int nb_prec = my_pow(10, prec);
    dpart_t dpart = init_dpart(d);

    if (dpart.exponant == 0x7ff)
        return handle_non_numbers(out, dpart);
    d = d_abs(d) - itgr;
    i += put_in_str(out, dpart.sign ? "-" : "")
        + my_putnbr(out + dpart.sign, itgr);
    if (prec) {
        itgr = i;
        d = (d + 1) * nb_prec + ((d * nb_prec - (int)(d * nb_prec)) >= 0.5);
        i += my_putnbr(out + i, (int)(d));
        out[itgr] = '.';
    }
    return i;
}
