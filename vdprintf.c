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
int print_invalid_format(
    print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    int conv_len = 1;
    const char *p = fmt;

    cinfo->width = 0;
    for (; *p != '%'; --p)
        conv_len++;
    pinfo->buf.written = conv_len;
    for (char *s = pinfo->buf.s; conv_len--; ++p)
        *s++ = *p;
    return pinfo->buf.written;
}

static
int run_converter(print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    int jmp = CONV_IDX(*fmt);
    static char buf[64];
    static char prefix[4];
    conv_func_t handler;

    cinfo->conv = *fmt;
    pinfo->buf = (small_buf_t){ buf, 0 };
    cinfo->prefix = (small_buf_t){ prefix, 0 };
    if (*fmt == '%') {
        conv_per(pinfo, cinfo);
        return pinfo->buf.written;
    }
    if (!BOUNDS(*fmt, 'A', 'z'))
        return print_invalid_format(pinfo, cinfo, fmt);
    handler = CONVERSION_FUNCS[jmp];
    if (handler == NULL)
        return print_invalid_format(pinfo, cinfo, fmt);
    handler(pinfo, cinfo);
    return pinfo->buf.written;
}

int print_format(print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    int written = run_converter(pinfo, cinfo, fmt) + cinfo->prefix.written;
    int pad = cinfo->width - written;

    if (pad > 0 && ~cinfo->flag & F_PAD_LEFT && ~cinfo->flag & F_PAD_ZERO)
        written += putnchar(pinfo->fd, ' ', pad);
    write(pinfo->fd, cinfo->prefix.s, cinfo->prefix.written);
    if (pad > 0 && cinfo->flag & F_PAD_ZERO)
        written += putnchar(pinfo->fd, '0', pad);
    write(pinfo->fd, pinfo->buf.s, pinfo->buf.written);
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
        format = parse_specifier(&pinfo, &cinfo, ++format);
        if (format == NULL)
            return -1;
        pinfo.written += print_format(&pinfo, &cinfo, format);
        format++;
    }
    return pinfo.written;
}
