/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include "internal.h"
#include <stdio.h>

void pop_length_modifier(union arg *argp, va_list *ap, len_mod_t lm)
{
    if (lm == CONV_LONG) {
        argp->i = va_arg(*ap, long);
        return;
    }
    argp->i = va_arg(*ap, int);
}
