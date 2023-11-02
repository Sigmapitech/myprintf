/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** pop_length_mod.c
*/

#include <limits.h>
#include <stdio.h>

#include "internal.h"

void pop_length_modifier(union arg *argp, va_list *ap, len_mod_t lm)
{
    if (lm == CONV_LONG) {
        argp->i = va_arg(*ap, long);
        return;
    }
    if (lm == CONV_LONG_LONG) {
        argp->i = va_arg(*ap, long long);
        return;
    }
    if (lm == CONV_SHORT) {
        argp->i = (short)va_arg(*ap, int);
        return;
    }
    if (lm == CONV_CHAR) {
        argp->i = (char)va_arg(*ap, int);
        return;
    }
    argp->i = va_arg(*ap, int);
}

void pop_length_modifier_u(union arg *argp, va_list *ap, len_mod_t lm)
{
    if (lm == CONV_LONG) {
        argp->i = va_arg(*ap, unsigned long);
        return;
    }
    if (lm == CONV_LONG_LONG) {
        argp->i = va_arg(*ap, unsigned long long);
        return;
    }
    if (lm == CONV_SHORT) {
        argp->i = (unsigned short)va_arg(*ap, unsigned int);
        return;
    }
    if (lm == CONV_CHAR) {
        argp->i = (unsigned char)va_arg(*ap, unsigned int);
        return;
    }
    argp->i = va_arg(*ap, unsigned int);
}
