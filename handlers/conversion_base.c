/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_base.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

int conv_char(print_info_t *pinfo, conv_info_t *cinfo)
{
    (void)pinfo;
    (void)cinfo;
    return 0;
}

int conv_int(print_info_t *pinfo, conv_info_t *cinfo)
{
    (void)pinfo;
    (void)cinfo;
    return 0;
}

int conv_str(print_info_t *pinfo, conv_info_t *cinfo)
{
    char *s = va_arg(pinfo->ap, char *);
    int len = MIN(my_strnlen(s, cinfo->width), cinfo->prec);
    int pad = cinfo->width - ((len != -1) ? len : (int)SSTR_LEN("(null)"));
    int written = 0;

    if (pad > 0 && cinfo->flag & F_PAD_LEFT)
        written += putnchar(pinfo->fd, ' ', pad);
    if (s != NULL)
        written += write(pinfo->fd, s, len);
    else
        written += write(pinfo->fd, "(null)", (int)SSTR_LEN("(null)"));
    if (pad > 0 && ~cinfo->flag & F_PAD_LEFT)
        written += putnchar(pinfo->fd, ' ', pad);
    return written;
}

int conv_ptr(print_info_t *pinfo, conv_info_t *cinfo)
{
    (void)pinfo;
    (void)cinfo;
    return 0;
}

// percent
int conv_per(print_info_t *pinfo, conv_info_t *cinfo)
{
    (void)pinfo;
    (void)cinfo;
    return 0;
}
