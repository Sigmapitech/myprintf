/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** pop_length_mod.c
*/

#include "internal.h"
#include <stdio.h>

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
