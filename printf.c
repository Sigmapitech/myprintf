/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** printf.c
*/

#include <stdarg.h>
#include <unistd.h>

#include "internal.h"

int my_printf(const char *format, ...)
{
    int written;
    va_list ap;

    va_start(ap, format);
    written = my_vdprintf(STDOUT_FILENO, format, ap);
    va_end(ap);
    return written;
}
