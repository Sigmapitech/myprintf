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

static
int put_frac_part(char *out, int prec_len, int i, double d)
{
    int start = i;

    d = (d + 1) * prec_len + ((d * prec_len - (int)(d * prec_len)) >= 0.5);
    i += my_putnbr(out + i, (int)(d));
    out[start] = '.';
    return i;
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
    int prec_len = my_pow(10, prec);
    dpart_t dpart;

    init_dpart(d, &dpart);
    if (dpart.exponant == 0x7ff)
        return handle_non_numbers(out, dpart);
    if (dpart.sign)
        i += put_in_str(out, "-");
    d = ABS(d);
    pad = get_pad(&d);
    i += my_putnbr(out + i, (int)d);
    if (prec)
        i += put_frac_part(out, prec_len, i, d) - 1 - dpart.sign;
    fprintf(stderr, "[%i]\n", i);
    i += put_in_str(out +i, "e") + put_in_str(out +i +1, 0 <= pad ? "+" : "-");
    fprintf(stderr, "[%i]\n", i);
    if (pad < 10)
        i += put_in_str(out + i, "0");
    i += my_putnbr(out + i, pad);
    return i + put_in_str(out + i, "\0");
}
