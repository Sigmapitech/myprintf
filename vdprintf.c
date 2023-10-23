/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** vdprintf.c
*/
#include <stdarg.h>
#include "internal.h"

spec_t SPEC = {
    {&print_char, "c", CONVERSION},
    {&print_str, "s", CONVERSION},
    {&print_int, "i", CONVERSION},
    {&print_int, "d", CONVERSION},
    {&print_percent, "%", CONVERSION},
    NULL
};

int handle_lookahead(int fd, const char *restrict format, print_info_t pinfo)
{
    spec_t p = SPEC;

    for (; *p != NULL && *p->name != *format; p++);
    if (*p == NULL) {
        pinfo->written += write(fd, "%", 1);
        return 0;
    }
    *p->handle(fd, pinfo);
}

int vdprintf(int fd, const char *restrict format, va_list ap)
{
    print_info_t pinfo = { .ap = &ap };

    for (; *format != '\0'; format++) {
        if (*format == '%') {
            handle_lookahead(fd, format, pinfo);
        } else {
            pinfo->written += write(fd, format, 1);
        }
    }
    return 0;
}
