/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_numerical.c
*/

#include "internal.h"
#include "my.h"

static
int conv_base(print_info_t *pinfo, conv_info_t *cinfo, int baselen)
{
    size_t n = (size_t)va_arg(pinfo->ap, size_t);

    my_putnbr_base(pinfo->buf.s, baselen, n);
    pinfo->buf.written = my_base_len(baselen, n);
    if (~cinfo->conv & (1 << 5))
        for (int i = 0; i < pinfo->buf.written; i++)
            pinfo->buf.s[i] &= ~(1 << 5);
    return 0;
}

int conv_oct(print_info_t *pinfo, conv_info_t *cinfo)
{
    return conv_base(pinfo, cinfo, 8);
}

int conv_hex(print_info_t *pinfo, conv_info_t *cinfo)
{
    return conv_base(pinfo, cinfo, 16);
}

int conv_uint(print_info_t *pinfo, conv_info_t *cinfo)
{
    return conv_base(pinfo, cinfo, 10);
}
