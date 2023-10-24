/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** vdprintf.c
*/
#include <stdarg.h>
#include "internal.h"

static
char parse_flag(char **format)
{
    char out = 0;

    for (; **format != '\0'; *format++) {
        switch (*format) {
            case '+':
                out |= 1;
                break;
            case '#':
                out |= 1 << 1;
                break;
            case '0':
                out |= 1 << 2;
                break;
            case '-':
                out |= 1 << 3;
                break;
            case ' ':
                out |= 1 << 4;
                break;
            default:
                return out;
        }
    }
    return NULL;
}

static
size_t parse_width(void)
{
}

static
int parse_prec(void)
{
}

static
char *parse_leng_mod(void)
{
}

static
int print_literal(char **format)
{
    char *s = *format;

    for (; **format != '\0' && **format != '%'; *format++);
    return += write(fd, s, *format - s);
}

static
conv_info_t handle_lookahead(print_info_t *pinfo, char **format)
{
    conv_info_t cinfo;

    cinfo.flag = parse_flag(format);
    cinfo.width = parse_width();
    cinfo.prec = parse_prec();
    cinfo.len_mod = parse_leng_mod();
    return cinfo;
}

int vdprintf(int fd, const char *format, va_list ap)
{
    print_info_t pinfo = {.written = 0, .ap = ap, .fd = fd};
    conv_info_t cinfo;

    for (; *format != '\0'; format++) {
        if (*format != '%')
            pinfo.written += print_literal(&format);
        else {
            cinfo = handle_lookahead(&pinfo, &format);
            conv_func_t[*format].handle(&pinfo, &cinfo);
        }
    }
    return 0;
}
