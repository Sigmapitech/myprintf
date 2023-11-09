/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_base.c
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#include "converters.h"
#include "../my.h"

void conv_char(print_info_t *pinfo, conv_info_t *cinfo)
{
    unsigned char i = (unsigned char)va_arg(pinfo->ap, int);

    cinfo->len_mod &= ~F_PAD_ZERO;
    pinfo->buf.s[0] = i;
    pinfo->buf.written = 1;
}

static
void set_prefix(conv_info_t *cinfo, char c)
{
    cinfo->prefix.s[cinfo->prefix.written] = c;
    cinfo->prefix.written++;
}

void conv_int(print_info_t *pinfo, conv_info_t *cinfo)
{
    intmax_t i = pop_length_modifier(&pinfo->ap, cinfo->len_mod);

    if (i < 0)
        set_prefix(cinfo, '-');
    else if (cinfo->flag & F_PUT_SIGN)
        set_prefix(cinfo, '+');
    if (cinfo->flag & F_SET_SPACE && i >= 0)
        set_prefix(cinfo, ' ');
    if (!i && cinfo->prec == 0)
        return;
    cinfo->prec += i && cinfo->prefix.written;
    pinfo->buf.written = my_putnbr(pinfo->buf.s, i);
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        cinfo->flag = (cinfo->flag | F_PAD_ZERO) & ~F_PAD_LEFT;
        cinfo->width = cinfo->prec;
    }
}

void conv_str(print_info_t *pinfo, conv_info_t *cinfo)
{
    cinfo->flag &= ~F_PAD_ZERO;
    pinfo->buf.s = va_arg(pinfo->ap, char *);
    if (pinfo->buf.s == NULL) {
        if (cinfo->prec >= 6)
            pinfo->buf.s = (char *)"(null)";
        else
            pinfo->buf.s = (char *)"\0";
    }
    pinfo->buf.written = my_strnlen(pinfo->buf.s, cinfo->prec);
}

void conv_ptr(print_info_t *pinfo, conv_info_t *cinfo)
{
    size_t ptr = (size_t)va_arg(pinfo->ap, void *);

    (void)cinfo;
    pinfo->buf.s[0] = '0';
    pinfo->buf.s[1] = 'x';
    my_putnbr_base(pinfo->buf.s + 2, 16, ptr);
    pinfo->buf.written = my_base_len(0x10, ptr) + 2;
}

/* The percent conversion may only print a percent no matter the settings.
 * Hencewhise, reset width & precision to cancel padding. */
void conv_per(print_info_t *pinfo, conv_info_t *cinfo)
{
    cinfo->width = 1;
    cinfo->prec = 1;
    pinfo->buf.s = (char *)"%";
    pinfo->buf.written = 1;
}
