/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_numerical.c
*/

#include <unistd.h>

#include "internal.h"
#include "my.h"

static
int conv_base(print_info_t *pinfo, int baselen, size_t n)
{
    int i = pinfo->buf.written;

    my_putnbr_base(pinfo->buf.s + i, baselen, n);
    pinfo->buf.written += my_base_len(baselen, n);
    return 0;
}

int conv_oct(print_info_t *pinfo, conv_info_t *cinfo)
{
    size_t n = (size_t)va_arg(pinfo->ap, size_t);

    if (!n && cinfo->prec == 0)
        return 0;
    if (cinfo->flag & F_ALT_FORM && n) {
        pinfo->buf.s[0] = '0';
        pinfo->buf.written++;
    }
    return conv_base(pinfo, 8, n);
}

int conv_hex(print_info_t *pinfo, conv_info_t *cinfo)
{
    size_t n = (size_t)va_arg(pinfo->ap, size_t);

    if (!n && cinfo->prec == 0)
        return 0;
    if (cinfo->flag & F_ALT_FORM && n) {
        pinfo->buf.s[0] = '0';
        pinfo->buf.s[1] = 'x';
        pinfo->buf.written += 2;
    }
    conv_base(pinfo, 16, n);
    for (int i = 0; i < pinfo->buf.written; i++)
        if (~cinfo->conv & (1 << 5) && IS_ALPHA(pinfo->buf.s[i]))
            pinfo->buf.s[i] &= ~(1 << 5);
    return 0;
}

int conv_uint(print_info_t *pinfo, conv_info_t *cinfo)
{
    size_t n = (size_t)va_arg(pinfo->ap, size_t);

    if (!n && cinfo->prec == 0)
        return 0;
    return conv_base(pinfo, 10, n);
}
