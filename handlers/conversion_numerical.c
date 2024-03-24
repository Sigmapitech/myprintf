#include <limits.h>
#include <unistd.h>

#include "converters.h"
#include "../my.h"

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
    conv_base(pinfo, 8, u);
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        for (int i = cinfo->prec - pinfo->buf.written; i; --i) {
            cinfo->prefix.s[cinfo->prefix.written] = '0';
            cinfo->prefix.written++;
        }
        cinfo->flag &= ~F_PAD_ZERO;
    }
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
    conv_base(pinfo, 16, u);
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        for (int i = cinfo->prec - pinfo->buf.written; i; --i) {
            cinfo->prefix.s[cinfo->prefix.written] = '0';
            cinfo->prefix.written++;
        }
        cinfo->flag &= ~F_PAD_ZERO;
    }
    for (int i = 0; i < pinfo->buf.written; i++)
        if (~cinfo->conv & (1 << 5) && IS_ALPHA(pinfo->buf.s[i]))
            pinfo->buf.s[i] &= ~(1 << 5);
}

void conv_uint(print_info_t *pinfo, conv_info_t *cinfo)
{
    uintmax_t u = pop_length_modifier_u(&pinfo->ap, cinfo->len_mod);

    if (!u && cinfo->prec == 0)
        return;
    conv_base(pinfo, 10, u);
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        cinfo->flag = (cinfo->flag | F_PAD_ZERO) & ~F_PAD_LEFT;
        cinfo->width = cinfo->prec;
    }
}

void conv_bin(print_info_t *pinfo, conv_info_t *cinfo)
{
    uintmax_t b = pop_length_modifier_u(&pinfo->ap, cinfo->len_mod);

    if (!b && cinfo->prec == 0)
        return;
    if (cinfo->flag & F_ALT_FORM && b) {
        cinfo->prefix.s[0] = '0';
        cinfo->prefix.s[1] = (~cinfo->conv & (1 << 5)) ? 'B' : 'b';
        cinfo->prefix.written = 2;
    }
    conv_base(pinfo, 2, b);
    if (pinfo->buf.written < cinfo->prec && cinfo->prec != INT_MAX) {
        for (int i = cinfo->prec - pinfo->buf.written; i; --i) {
            cinfo->prefix.s[cinfo->prefix.written] = '0';
            cinfo->prefix.written++;
        }
        cinfo->flag &= ~F_PAD_ZERO;
    }
}
