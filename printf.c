/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <stdarg.h>
#include <unistd.h>

#include "internal.h"

int printf(const char *format, ...)
{
    int written;
    va_list ap;

    va_start(ap, format);
    written = vdprintf(STDOUT_FILENO, format, ap);
    va_end(ap);
    return written;
}
