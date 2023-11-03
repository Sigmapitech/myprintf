/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** double_to_str_sci.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

static
int handle_non_numbers(char *out, dpart_t dpart)
{
    if (dpart.mentissa != 0)
        return put_in_str(out, "nan");
    return put_in_str(out, dpart.sign ? "-inf" : "inf");
}

static
void round_up(char *out, int len)
{
    --len;
    for (; out[len] == '9'; len--)
        out[len] = '0';
    out[len]++;
}

static
int put_frac_part(char *out, int prec, int i, double d)
{
    char *s = out + i;

    *s++ = '.';
    for (d -= (int)(d); prec-- > 0; d -= (int)d) {
        d *= 10;
        *s++ = '0' | (int)d % 10;
    }
    if (d >= .5L)
        round_up(out, s - out);
    return s - out;
}

static
int get_pad(double *d)
{
    int pad = 0;

    if (*d == 0)
        return 0;
    for (; *d < 1; *d *= 10)
        pad--;
    for (; 10 <= *d; *d /= 10)
        pad++;
    return pad;
}

int double_to_str_sci(char *out, double d, unsigned int prec)
{
    int i = 0;
    int pad = 0;
    dpart_t dpart;

    init_dpart(d, &dpart);
    if (dpart.exponant == 0x7ff)
        return handle_non_numbers(out, dpart);
    if (dpart.sign)
        i += put_in_str(out, "-");
    d = ABS(d);
    pad = get_pad(&d);
    i += my_putnbr(out + i, (int)d + (((d - (int)d) >= 0.5) && !prec));
    if (prec)
        i += put_frac_part(out, prec, i, d) - 1 - dpart.sign;
    i += put_in_str(out +i, "e") + put_in_str(out +i +1, 0 <= pad ? "+" : "-");
    if (pad < 10)
        i += put_in_str(out + i, "0");
    i += my_putnbr(out + i, pad);
    return i + put_in_str(out + i, "\0");
}
