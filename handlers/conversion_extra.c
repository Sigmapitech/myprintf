/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_extra.c
*/

#include "internal.h"
#include "my.h"

int conv_num(print_info_t *pinfo, conv_info_t *cinfo)
{
    int *i = va_arg(pinfo->ap, int *);

    (void)cinfo;
    *i = pinfo->written;
    return 0;
}
