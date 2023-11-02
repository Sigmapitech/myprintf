/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** pop_length_mod.c
*/

#include <limits.h>
#include <stdio.h>

#include "internal.h"

intmax_t pop_length_modifier(va_list *ap, len_mod_t lm)
{
    switch (lm) {
        case CONV_LONG:
            return va_arg(*ap, long);
        case CONV_LONG_LONG:
            return va_arg(*ap, long long);
        case CONV_SHORT:
            return (short)va_arg(*ap, int);
        case CONV_CHAR:
            return (char)va_arg(*ap, int);
        default:
            return va_arg(*ap, int);
    }
}

uintmax_t pop_length_modifier_u(va_list *ap, len_mod_t lm)
{
    switch (lm) {
        case CONV_LONG:
            return va_arg(*ap, unsigned long);
        case CONV_LONG_LONG:
            return va_arg(*ap, unsigned long long);
        case CONV_SHORT:
            return (unsigned short)va_arg(*ap, unsigned int);
        case CONV_CHAR:
            return (unsigned char)va_arg(*ap, unsigned int);
        default:
            return va_arg(*ap, unsigned int);
    }
}
