/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** double_to_str.c
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
void init_dpart(double d, dpart_t *dpart)
{
    dpart->sign = (BITS(d) >> 63) & 1;
    dpart->exponant = (BITS(d) >> 52) & 0x7ff;
    dpart->mentissa = BITS(d) & 0x000fffffffffffffL;
}

int double_to_str(char *out, double d, unsigned int prec)
{
    int itgr = (int)d_abs(d);
    int i = 0;
    int prec_len = my_pow(10, prec);
    dpart_t dpart;

    init_dpart(d, &dpart);
    if (dpart.exponant == 0x7ff)
        return handle_non_numbers(out, dpart);
    d = d_abs(d) - itgr;
    if (dpart.sign)
        i += put_in_str(out, "-");
    i += my_putnbr(out + dpart.sign, itgr);
    if (prec) {
        itgr = i;
        d = (d + 1) * prec_len + ((d * prec_len - (int)(d * prec_len)) >= 0.5);
        i += my_putnbr(out + i, (int)(d));
        out[itgr] = '.';
    }
    return i;
}