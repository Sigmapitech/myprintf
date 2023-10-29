/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** vdprintf.c
*/

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

const char *print_literal(print_info_t *pinfo, const char *fmt)
{
    const char *s = fmt;

    for (; *fmt != '\0' && *fmt != '%'; fmt++);
    pinfo->written += write(pinfo->fd, s, fmt - s);
    return fmt;
}

static
int run_converter(print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    static char buf[64];

    pinfo->buf.s = buf;
    pinfo->buf.written = 0;
    cinfo->conv = *fmt;
    if (*fmt == '%')
        conv_per(pinfo, cinfo);
    else
        CONVERSION_FUNCS[CONV_IDX(*fmt)](pinfo, cinfo);
    return pinfo->buf.written;
}

int print_format(print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    int pad;
    int written = 0;

    pad = run_converter(pinfo, cinfo, fmt);
    pad = cinfo->width - pad;
    if (pad > 0 && ((cinfo->flag & F_PAD_ZERO) || ~cinfo->flag & F_PAD_LEFT)) {
        written += putnchar(
            pinfo->fd,
            cinfo->flag & F_PAD_ZERO ? '0' : ' ',
            pad
        );
        pad = 0;
    }
    written += write(pinfo->fd, pinfo->buf.s, pinfo->buf.written);
    if (pad > 0 && cinfo->flag & F_PAD_LEFT)
        written += putnchar(pinfo->fd, ' ', pad);
    return written;
}

int my_vdprintf(int fd, const char *format, va_list ap)
{
    print_info_t pinfo = { .written = 0, .fd = fd };
    conv_info_t cinfo = { 0 };

    va_copy(pinfo.ap, ap);
    while (*format != '\0') {
        if (*format != '%') {
            format = print_literal(&pinfo, format);
            continue;
        }
        format = parse_specifier(&cinfo, ++format);
        if (format == NULL)
            return -1;
        print_format(&pinfo, &cinfo, format);
        format++;
    }
    return pinfo.written;
}
