#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

/**
 * Format specifier parser, that collect all the required information
 * to translate the converter appropriately.
 *
 * Follow the fprintf conversion format:
 * `%[flags][width][.precision][length modifier]conversion`
 *
 * with the following precisions:
 * - flags: one of `+#0- `
 * - width integer between 0 and INT_MAX
 * - precision (samme form as width, preceeded by a dot)
 * - length modifier from the table below.
 *
 * Conversion is treated separately.
 **/

static
const len_mod_comp_t LENGTH_MODIFIERS[] = {
    { "hh", CONV_CHAR },
    { "h", CONV_SHORT },
    { "ll", CONV_LONG_LONG },
    { "l", CONV_LONG },
    { "j", CONV_INTMAX_T },
    { "z", CONV_SIZE_T },
    { "L", CONV_DOUBLE },
    { "t", CONV_PTDRDIFF_T }
};

static
const char *parse_flag(conv_info_t *cinfo, const char *fmt)
{
    cinfo->flag = 0;
    for (int idx; *fmt != '\0'; fmt++) {
        idx = my_stridx("-0#+ ", *fmt);
        if (idx == -1)
            return fmt;
        cinfo->flag |= 1 << idx;
        if (cinfo->flag & F_PAD_LEFT)
            cinfo->flag &= ~F_PAD_ZERO;
        if (cinfo->flag & F_PUT_SIGN)
            cinfo->flag &= ~F_SET_SPACE;
    }
    return NULL;
}

static
const char *parse_width(conv_info_t *cinfo, const char *fmt)
{
    cinfo->width = 0;
    for (; IS_DIGIT(*fmt); fmt++) {
        if (cinfo->width > (INT_MAX / 10))
            return NULL;
        cinfo->width *= 10;
        if (cinfo->width > INT_MAX - TO_DIGIT(*fmt))
            return NULL;
        cinfo->width += TO_DIGIT(*fmt);
    }
    return (*fmt == '\0') ? NULL : fmt;
}

static
const char *parse_prec(
    print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    if (*fmt != '.') {
        cinfo->prec = INT_MAX;
        return fmt;
    }
    for (fmt++; *fmt == '*';) {
        cinfo->prec = (int)va_arg(pinfo->ap, int);
        if (cinfo->prec < 0)
            cinfo->prec = INT_MAX;
        return fmt + 1;
    }
    cinfo->prec = 0;
    for (; IS_DIGIT(*fmt); fmt++) {
        if (cinfo->prec > (INT_MAX / 10))
            return NULL;
        cinfo->prec *= 10;
        if (cinfo->prec > INT_MAX - TO_DIGIT(*fmt))
            return NULL;
        cinfo->prec += TO_DIGIT(*fmt);
    }
    return (*fmt == '\0') ? NULL : fmt;
}

static
const char *parse_len_mod(conv_info_t *cinfo, const char *fmt)
{
    char cmp_len;

    cinfo->len_mod = CONV_NO;
    for (size_t i = 0; i < LENGTH_OF(LENGTH_MODIFIERS); i++) {
        cmp_len = 1 + (LENGTH_MODIFIERS[i].cmp[1] != '\0');
        if (!my_strncmp(fmt, LENGTH_MODIFIERS[i].cmp, cmp_len)) {
            cinfo->len_mod = LENGTH_MODIFIERS[i].mod;
            fmt += cmp_len;
            return fmt;
        }
    }
    return fmt;
}

const char *parse_specifier(
    print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    fmt = parse_flag(cinfo, fmt);
    if (fmt == NULL)
        return NULL;
    fmt = parse_width(cinfo, fmt);
    if (fmt == NULL)
        return NULL;
    fmt = parse_prec(pinfo, cinfo, fmt);
    if (fmt == NULL)
        return NULL;
    return parse_len_mod(cinfo, fmt);
}
