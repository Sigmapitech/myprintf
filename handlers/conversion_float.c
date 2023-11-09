/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_float.c
*/
#include <limits.h>
#include <stdio.h>

#include "converters.h"
#include "../float/float.h"
#include "../my.h"

static
void set_upcase(char *s, int is_up)
{
    for (; *s != '\0'; s++) {
        if (!IS_ALPHA(*s))
            continue;
        if (is_up)
            *s &= ~(1 << 5);
        else
            *s |= 1 << 5;
    }
}

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

static
int insert_char(char *str, char c)
{
    char temp;

    for (; *str != '\0'; str++) {
        temp = *str;
        *str = c;
        c = temp;
    }
    *str = c;
    str[1] = '\0';
    return 1;
}

// scientific notation of float %e
void conv_nota_sci(print_info_t *pinfo, conv_info_t *cinfo)
{
    double d = (double)va_arg(pinfo->ap, double);

    if (cinfo->prec == INT_MAX)
        cinfo->prec = 6;
    pinfo->buf.written = double_to_str_sci(pinfo->buf.s, d, cinfo->prec);
    if (cinfo->flag & F_PAD_ZERO &&
        (pinfo->buf.s[d < 0] == 'i' || pinfo->buf.s[d < 0] == 'n'))
        cinfo->flag &= ~F_PAD_ZERO;
    set_upcase(pinfo->buf.s, ~cinfo->conv & 32);
    if (!IS_DIGIT(pinfo->buf.s[pinfo->buf.written - 1]))
        return;
    if (0 <= d)
        set_flags_space_plus(cinfo);
    if (cinfo->flag & F_ALT_FORM && pinfo->buf.s[1 + (d < 0)] != '.')
        pinfo->buf.written += insert_char(pinfo->buf.s + 1 + (d < 0), '.');
}

// decimal notation %f
void conv_nota_dec(print_info_t *pinfo, conv_info_t *cinfo)
{
    double d = (double)va_arg(pinfo->ap, double);

    if (cinfo->prec == INT_MAX)
        cinfo->prec = 6;
    pinfo->buf.written = double_to_str(pinfo->buf.s, d, cinfo->prec);
    if (cinfo->flag & F_PAD_ZERO &&
        (pinfo->buf.s[d < 0] == 'i' || pinfo->buf.s[d < 0] == 'n'))
        cinfo->flag &= ~F_PAD_ZERO;
    set_upcase(pinfo->buf.s, ~cinfo->conv & 32);
    if (!IS_DIGIT(pinfo->buf.s[pinfo->buf.written - 1]))
        return;
    if (cinfo->flag & F_ALT_FORM)
        pinfo->buf.written += add_point(pinfo->buf.s);
    if (0 <= d)
        set_flags_space_plus(cinfo);
}

/**
void conv_nota_var(print_info_t *pinfo, conv_info_t *cinfo)
{
    double d = (double)va_arg(pinfo->ap, double);
    dpart_t dpart;
    int exp;

    init_dpart(d, &dpart);
    exp = ABS((int)dpart.exponant) - 1023;
    if (cinfo->prec == 0)
        cinfo->prec = 1;
    if (exp < -4 || exp >= cinfo->prec)
        pinfo->buf.written = double_to_str_sci(pinfo->buf.s, d, cinfo->prec);
    else
        pinfo->buf.written = double_to_str(pinfo->buf.s, d, cinfo->prec);
    set_upcase(pinfo->buf.s, ~cinfo->conv & 32);
} **/

// variable between -f & -e %g
void conv_nota_var(print_info_t *pinfo, conv_info_t *cinfo)
{
    double d = (double)va_arg(pinfo->ap, double);

    pinfo->buf.written = double_to_str(pinfo->buf.s, d, cinfo->prec);
    set_upcase(pinfo->buf.s, ~cinfo->conv & 32);
}

static
void incr_and_set(char **ptr, char c)
{
    **ptr = c;
    (*ptr)++;
}

// hexadecimal + scientific notation %a
void conv_nota_hex(print_info_t *pinfo, conv_info_t *cinfo)
{
    char *s = pinfo->buf.s;
    double d = (double)va_arg(pinfo->ap, double);
    dpart_t dpart;
    int exp;

    init_dpart(d, &dpart);
    if (dpart.sign)
        incr_and_set(&s, '-');
    s += put_in_str(s, "0x1");
    if (dpart.mentissa) {
        incr_and_set(&s, '.');
        s += my_putnbr_base(s, 16, dpart.mentissa);
    }
    incr_and_set(&s, 'p');
    exp = ABS((int)dpart.exponant) - 1023;
    incr_and_set(&s, "-+"[exp >= 0]);
    s += my_putnbr_base(s, 10, (unsigned)ABS(exp));
    pinfo->buf.written = s - pinfo->buf.s;
    set_upcase(pinfo->buf.s, ~cinfo->conv & 32);
}
