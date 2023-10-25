/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** vdprintf.c
*/

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

static
const char *parse_flag(conv_info_t *cinfo, const char *fmt)
{
    cinfo->flag = 0;
    for (int idx; *fmt != '\0'; fmt++) {
        idx = my_stridx("+#0- ", *fmt);
        if (idx == -1)
            return fmt;
        cinfo->flag |= 1 << idx;
    }
    return NULL;
}

static
const char *parse_width(conv_info_t *cinfo, const char *fmt)
{
    cinfo->width = 0;
    for (; IS_DIGIT(*fmt); fmt++) {
        if (cinfo->width > UINT_MAX / 10)
            return NULL;
        cinfo->width *= 10;
        if (cinfo->width > UINT_MAX - '0')
            return NULL;
        cinfo->width += *fmt - '0';
    }
    return (*fmt == '\0') ? NULL : fmt;
}

static
const char *parse_prec(conv_info_t *cinfo, const char *fmt)
{
    if (*fmt != '.') {
        cinfo->prec = INT_MAX;
        return fmt;
    }
    cinfo->prec = 0;
    for (; *fmt >= '0' && *fmt <= '9'; fmt++) {
        if (cinfo->prec > INT_MAX / 10)
            return NULL;
        cinfo->prec *= 10;
        if (cinfo->width > INT_MAX - '0')
            return NULL;
        cinfo->prec += *fmt - '0';
    }
    return (*fmt == '\0') ? NULL : fmt;
}

static
const char *parse_leng_mod(conv_info_t *cinfo, const char *fmt)
{
    cinfo->len_mod = CONV_NO;
    return fmt;
}

static
const char *print_literal(print_info_t *pinfo, const char *fmt)
{
    const char *s = fmt;

    for (; *fmt != '\0' && *fmt != '%'; fmt++);
    pinfo->written += write(pinfo->fd, s, fmt - s);
    return fmt;
}

__attribute__((optimize("unroll-loops")))
const char *handle_lookahead(conv_info_t *cinfo, const char *fmt)
{
    const char *(*parse_funcs[4])(conv_info_t *, const char *) = {
        &parse_flag, &parse_width, &parse_prec, &parse_leng_mod
    };

    for (int i = 0; i < 4; i++) {
        fmt = parse_funcs[i](cinfo, fmt);
        if (fmt == NULL)
            return NULL;
    }
    return fmt;
}

int vdprintf(int fd, const char *format, va_list ap)
{
    print_info_t pinfo = { .written = 0, .ap = ap, .fd = fd };
    conv_info_t cinfo = { 0 };

    for (; *format != '\0'; format++) {
        if (*format != '%') {
            format++;
            format = print_literal(&pinfo, format);
            continue;
        }
        format = handle_lookahead(&cinfo, ++format);
        if (format == NULL)
            return -1;
        CONVERSION_FUNCS[(int)*format](&pinfo, &cinfo);
    }
    return pinfo.written;
}
