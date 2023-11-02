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

int put_in_str(char *out, const char *in)
{
    int i;

    for (i = 0; in[i] != '\0'; i++)
        out[i] = in[i];
    out[i] = in[i];
    return i;
}

static
int handle_non_numbers(char *out, dpart_t dpart)
{
    if (dpart.mentissa != 0)
        return put_in_str(out, "nan");
    return put_in_str(out, dpart.sign ? "-inf" : "inf");
}

void init_dpart(double d, dpart_t *dpart)
{
    union {
        double d;
        unsigned long long ull;
    } fh = { .d = d };

    dpart->sign = (fh.ull >> 63) & 1;
    dpart->exponant = (fh.ull >> 52) & 0x7ff;
    dpart->mentissa = fh.ull & 0x000fffffffffffffL;
}

void round_up(char *out, int len)
{
    --len;
    for (; out[len] == '9'; len--)
        out[len] = '0';
    out[len]++;
}

int double_to_str(char *out, double d, unsigned int prec)
{
    int i = 0;
    dpart_t dpart;

    init_dpart(d, &dpart);
    if (dpart.exponant == 0x7ff)
        return handle_non_numbers(out, dpart);
    if (dpart.sign)
        i += put_in_str(out, "-");
    i += my_putnbr(out + dpart.sign, (int)ABS(d));
    if (!prec)
        return i;
    out[i++] = '.';
    d = ABS(d);
    for (d -= (int)(d); prec-- > 0; d -= (int)d) {
        d *= 10;
        out[i++] = '0' | (int)d % 10;
    }
    if (d >= .5)
        round_up(out, i);
    return i;
}
