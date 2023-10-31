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

#include "internal.h"
#include "my.h"

int conv_char(print_info_t *pinfo, conv_info_t *cinfo)
{
    unsigned char i = (unsigned char)va_arg(pinfo->ap, int);

    cinfo->len_mod &= ~F_PAD_ZERO;
    pinfo->buf.s[0] = i;
    pinfo->buf.written = 1;
    return 0;
}

int conv_int(print_info_t *pinfo, conv_info_t *cinfo)
{
    union arg a;

    pop_length_modifier(&a, &pinfo->ap, cinfo->len_mod);
    if (a.i < 0) {
        cinfo->prefix.s[cinfo->prefix.written++] = '-';
        cinfo->prec++;
    } else if (cinfo->flag & F_PUT_SIGN) {
        cinfo->prefix.s[cinfo->prefix.written++] = '+';
        cinfo->prec += a.i > 0;
    }
    if (cinfo->flag & F_SET_SPACE && a.i >= 0)
        cinfo->prefix.s[cinfo->prefix.written++] = ' ';
    if (!a.i && cinfo->prec == 0)
        return 0;
    pinfo->buf.written = my_putnbr(pinfo->buf.s, a.i);
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        cinfo->flag = (cinfo->flag | F_PAD_ZERO) & ~F_PAD_LEFT;
        cinfo->width = cinfo->prec;
    }
    return 0;
}

int conv_str(print_info_t *pinfo, conv_info_t *cinfo)
{
    cinfo->flag &= ~F_PAD_ZERO;
    pinfo->buf.s = va_arg(pinfo->ap, char *);
    if (pinfo->buf.s == NULL) {
        if (cinfo->prec >= 6) {
            pinfo->buf.s = (char *)"(null)";
            pinfo->buf.written = 6;
            return 0;
        } else
            pinfo->buf.s = (char *)"\0";
    }
    pinfo->buf.written = my_strnlen(pinfo->buf.s, cinfo->prec);
    return 0;
}

int conv_ptr(print_info_t *pinfo, conv_info_t *cinfo)
{
    size_t ptr = (size_t)va_arg(pinfo->ap, void *);

    (void)cinfo;
    pinfo->buf.s[0] = '0';
    pinfo->buf.s[1] = 'x';
    my_putnbr_base(pinfo->buf.s + 2, 16, ptr);
    pinfo->buf.written = my_base_len(0x10, ptr) + 2;
    return 0;
}

/* The percent conversion may only print a percent no matter the settings.
 * Hencewhise, reset width & precision to cancel padding. */
int conv_per(print_info_t *pinfo, conv_info_t *cinfo)
{
    cinfo->width = 1;
    cinfo->prec = 1;
    pinfo->buf.s = (char *)"%";
    pinfo->buf.written = 1;
    return 0;
}
