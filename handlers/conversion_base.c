/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_base.c
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

int conv_char(print_info_t *pinfo, conv_info_t *cinfo)
{
    int i = va_arg(pinfo->ap, int);

    (void)cinfo;
    pinfo->buf.s[0] = i;
    pinfo->buf.written = 1;
    return 0;
}

int conv_int(print_info_t *pinfo, conv_info_t *cinfo)
{
    int i = va_arg(pinfo->ap, int);

    (void)cinfo;
    my_putnbr(pinfo->buf.s, i);
    pinfo->buf.written = my_intlen(i) + (i < 0);
    return 0;
}

int conv_str(print_info_t *pinfo, conv_info_t *cinfo)
{
    pinfo->buf.s = va_arg(pinfo->ap, char *);
    if (pinfo->buf.s == NULL) {
        pinfo->buf.s = (char *)"(null)";
        pinfo->buf.written = 6;
        return 0;
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
    my_putnbr_base(pinfo->buf.s + 2, "0123456789abcdef", ptr);
    pinfo->buf.written = my_base_len(0x10, ptr) + 2;
    return 0;
}

int conv_per(print_info_t *pinfo, conv_info_t *cinfo)
{
    (void)cinfo;
    pinfo->buf.s[0] = '%';
    pinfo->buf.written = 1;
    return 0;
}
