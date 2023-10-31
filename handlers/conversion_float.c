/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_float.c
*/
#include "internal.h"
#include "my.h"
#include <limits.h>

// scientific notation of float %e
int conv_nota_sci(print_info_t *pinfo, conv_info_t *cinfo)
{
    (void)pinfo;
    (void)cinfo;
    return 0;
}

// decimal notation %f
int conv_nota_dec(print_info_t *pinfo, conv_info_t *cinfo)
{
    double d = (double)va_arg(pinfo->ap, double);

    if (cinfo->prec == INT_MAX)
        cinfo->prec = 6;
    pinfo->buf.written = double_to_str(pinfo->buf.s, d, cinfo->prec);
    return 0;
}

// variable between -f & -e %g
int conv_nota_var(print_info_t *pinfo, conv_info_t *cinfo)
{
    (void)pinfo;
    (void)cinfo;
    return 0;
}

// hexadecimal + scientific notation %a
int conv_nota_hex(print_info_t *pinfo, conv_info_t *cinfo)
{
    (void)pinfo;
    (void)cinfo;
    return 0;
}
