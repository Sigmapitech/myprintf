/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** conversion_numerical.c
*/

#include <limits.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

static
void conv_base(print_info_t *pinfo, int baselen, size_t n)
{
    int i = pinfo->buf.written;

    my_putnbr_base(pinfo->buf.s + i, baselen, n);
    pinfo->buf.written += my_base_len(baselen, n);
}

void conv_oct(print_info_t *pinfo, conv_info_t *cinfo)
{
    uintmax_t u = pop_length_modifier_u(&pinfo->ap, cinfo->len_mod);

    if (!u && cinfo->prec == 0)
        return;
    if (cinfo->flag & F_ALT_FORM && u) {
        cinfo->prefix.s[0] = '0';
        cinfo->prefix.written++;
    }
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        cinfo->flag |= F_PAD_ZERO;
        cinfo->flag &= ~F_PAD_LEFT;
        cinfo->width = cinfo->prec;
    }
    conv_base(pinfo, 8, u);
}

void conv_hex(print_info_t *pinfo, conv_info_t *cinfo)
{
    uintmax_t u = pop_length_modifier_u(&pinfo->ap, cinfo->len_mod);

    if (!u && cinfo->prec == 0)
        return;
    if (cinfo->flag & F_ALT_FORM && u) {
        cinfo->prefix.s[0] = '0';
        cinfo->prefix.s[1] = (~cinfo->conv & (1 << 5)) ? 'X' : 'x';
        cinfo->prefix.written = 2;
    }
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        cinfo->flag |= F_PAD_ZERO;
        cinfo->flag &= ~F_PAD_LEFT;
        cinfo->width = cinfo->prec;
    }
    conv_base(pinfo, 16, u);
    for (int i = 0; i < pinfo->buf.written; i++)
        if (~cinfo->conv & (1 << 5) && IS_ALPHA(pinfo->buf.s[i]))
            pinfo->buf.s[i] &= ~(1 << 5);
}

void conv_uint(print_info_t *pinfo, conv_info_t *cinfo)
{
    uintmax_t u = pop_length_modifier_u(&pinfo->ap, cinfo->len_mod);

    if (!u && cinfo->prec == 0)
        return;
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        cinfo->flag |= F_PAD_ZERO;
        cinfo->flag &= ~F_PAD_LEFT;
        cinfo->width = cinfo->prec;
    }
    conv_base(pinfo, 10, u);
}
