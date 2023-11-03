/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_extra.c
*/

#include "converters.h"
#include "my.h"

void conv_num(print_info_t *pinfo, conv_info_t *cinfo)
{
    int *i = va_arg(pinfo->ap, int *);

    (void)cinfo;
    *i = pinfo->written;
}
