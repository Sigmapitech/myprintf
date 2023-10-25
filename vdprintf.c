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
    char cmp[] = "+#0- ";
    int idx;

    cinfo->flag = 0;
    for (; *fmt != '\0'; fmt++) {
        idx = my_stridx(cmp, *fmt);
        if (idx == -1) {
            return fmt;
        }
        cinfo->flag |= 1 << idx;
    }
    return NULL;
}

static
const char *parse_width(conv_info_t *cinfo, const char *fmt)
{
    cinfo->width = 0;
    for (; '0' <= *fmt && *fmt <= '9'; fmt++) {
        cinfo->width *= 10;
        cinfo->width += *fmt - '0';
    }
    if (*fmt == '\0')
        return NULL;
    return fmt;
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
        cinfo->prec *= 10;
        cinfo->prec += *fmt - '0';
    }
    if (*fmt == '\0')
        return NULL;
    return fmt;
}

static
const char *parse_leng_mod(conv_info_t *cinfo, const char *fmt)
{
    cinfo->len_mod = "\0";
    return fmt;
}

static
int print_literal(int fd, const char **format)
{
    const char *s = *format;

    for (; **format != '\0' && **format != '%'; (*format)++);
    return write(fd, s, *format - s);
}

const char *handle_lookahead(
    print_info_t *pinfo UNUSED,
    conv_info_t *cinfo,
    const char *fmt)
{
    fmt = parse_flag(cinfo, fmt);
    if (fmt == NULL)
        return NULL;
    fmt = parse_width(cinfo, fmt);
    if (fmt == NULL)
        return NULL;
    fmt = parse_prec(cinfo, fmt);
    if (fmt == NULL)
        return NULL;
    fmt = parse_leng_mod(cinfo, fmt);
    if (fmt == NULL)
        return NULL;
    return fmt;
}

int vdprintf(int fd, const char *format, va_list ap)
{
    print_info_t pinfo = { .written = 0, .ap = ap, .fd = fd };
    conv_info_t cinfo = { 0 };

    for (; *format != '\0'; format++) {
        if (*format != '%') {
            format++;
            pinfo.written += print_literal(fd, &format);
            continue;
        } else {
            format++;
            format = handle_lookahead(&pinfo, &cinfo, format);
        }
        if (format == NULL)
            return -1;
        else
            CONVERSION_FUNCS[(int)*format](&pinfo, &cinfo);
    }
    return pinfo.written;
}
