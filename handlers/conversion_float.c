/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_float.c
*/
#include <limits.h>
#include <stdio.h>

#include "internal.h"
#include "my.h"

static
int add_point(char *str)
{
    for (; *str != '.' && *str != '\0'; str++);
    if (*str == '.')
        return 0;
    *str = '.';
    str[1] = '\0';
    return 1;
}

static
void set_flags_space_plus(conv_info_t *cinfo)
{
    if (cinfo->flag & F_SET_SPACE) {
        cinfo->prefix.s[0] = ' ';
        cinfo->prefix.written = 1;
    }
    if (cinfo->flag & F_PUT_SIGN) {
        cinfo->prefix.s[0] = '+';
        cinfo->prefix.written = 1;
    }
}

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
    if (!IS_DIGIT(pinfo->buf.s[pinfo->buf.written - 1]))
        return 0;
    if (cinfo->flag & F_ALT_FORM)
        pinfo->buf.written += add_point(pinfo->buf.s);
    if (0 < d)
        set_flags_space_plus(cinfo);
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
