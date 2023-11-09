/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** double_to_str.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "float.h"
#include "../internal.h"
#include "../my.h"

static
int get_first_digit(double d, int prec)
{
    return (int)d + (((d - (int)d) >= .5) && !prec);
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

static
int put_frac_part(char *out, int prec, int i, double d)
{
    char *s = out + i;

    *s = '.';
    s++;
    for (d -= (int)(d); prec-- > 0; d -= (int)d) {
        d *= 10;
        *s = '0' | (int)d % 10;
        s++;
    }
    if (d >= .5L)
        round_up(out, s - out);
    return s - out;
}

static
int add_exponant(char *out, int i, int pad)
{
    unsigned int apad = ABS(pad);
    char *s = out + i;

    *s += 'e';
    s++;
    s += put_in_str(s, 0 <= pad ? "+" : "-");
    s += my_putnbr(s, apad / 10);
    *s = '0' | (apad % 10);
    s++;
    *s = '\0';
    return s - out;
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
    i += my_putnbr(out + i, get_first_digit(d, prec));
    if (prec)
        i += put_frac_part(out, prec, i, d) - 1 - dpart.sign;
    return add_exponant(out, i, pad);
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
    d = ABS(d);
    i += my_putnbr(out + i, get_first_digit(d, prec));
    if (!prec)
        return i;
    return put_frac_part(out, prec, i, d);
}
