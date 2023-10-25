/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** vdprintf.c
*/
#include <stdarg.h>
#include <unistd.h>
#include "internal.h"
#include "my.h"

char parse_flag(const char **format)
{
    char out = 0;
    char cmp[] = "+#0- ";
    int idx;

    for (; **format != '\0'; (*format)++) {
        idx = my_stridx(cmp, **format);
        if (idx == -1)
            return out;
        out |= 1 << idx;
    }
    return -1;
}

static
size_t parse_width(const char **format)
{
    size_t out = 0;

    for (; '0' <= **format && **format <= '9'; (*format)++) {
        out *= 10;
        out += **format - '0';
    }
    return out;
}

static
int parse_prec(const char **format)
{
    int out = 0;

    if (**format != '.')
        return -1;
    for (;'0' <= **format && **format <= '9'; (*format)++) {
        out *= 10;
        out += **format - '0';
    }
    return out;
}

static
char *parse_leng_mod(const char **format UNUSED)
{
    return NULL;
}

static
int print_literal(int fd, const char **format)
{
    const char *s = *format;

    for (; **format != '\0' && **format != '%'; (*format)++);
    return write(fd, s, *format - s);
}

static
conv_info_t handle_lookahead(print_info_t *pinfo UNUSED, const char **format)
{
    conv_info_t cinfo;

    cinfo.flag = parse_flag(++format);
    cinfo.width = parse_width(format);
    cinfo.prec = parse_prec(format);
    cinfo.len_mod = parse_leng_mod(format);
    return cinfo;
}

int vdprintf(int fd, const char *format, va_list ap)
{
    print_info_t pinfo = { .written = 0, .ap = ap, .fd = fd };
    conv_info_t cinfo;

    for (; *format != '\0'; format++) {
        if (*format != '%') {
            format++;
            pinfo.written += print_literal(fd, &format);
        } else {
            cinfo = handle_lookahead(&pinfo, &format);
            CONVERSION_FUNCS[(int)*format](&pinfo, &cinfo);
        }
    }
    return 0;
}
