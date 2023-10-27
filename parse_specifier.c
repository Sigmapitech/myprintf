/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** parse_specifier.c
*/

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

static
const char *parse_flag(conv_info_t *cinfo, const char *fmt)
{
    cinfo->flag = 0;
    for (int idx; *fmt != '\0'; fmt++) {
        idx = my_stridx("-0#+ ", *fmt);
        if (idx == -1)
            return fmt;
        cinfo->flag |= 1 << idx;
        if ((cinfo->flag & F_PAD_ZERO) && (cinfo->flag & F_PAD_LEFT))
            cinfo->flag &= ~(F_PAD_ZERO | F_PAD_LEFT);
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
        if (cinfo->width > INT_MAX - (*fmt - '0'))
            return NULL;
        cinfo->width += *fmt - '0';
    }
    return (*fmt == '\0') ? NULL : fmt;
}

static
const char *parse_prec(conv_info_t *cinfo, const char *fmt)
{
    if (*fmt != '.') {
        cinfo->prec = INT_MAX;
        return fmt;
    }
    fmt++;
    cinfo->prec = 0;
    for (; IS_DIGIT(*fmt); fmt++) {
        if (cinfo->prec > (INT_MAX / 10))
            return NULL;
        cinfo->prec *= 10;
        if (cinfo->width > INT_MAX - (*fmt - '0'))
            return NULL;
        cinfo->prec += *fmt - '0';
    }
    return (*fmt == '\0') ? NULL : fmt;
}

static
const char *parse_len_mod(conv_info_t *cinfo, const char *fmt)
{
    cinfo->len_mod = CONV_NO;
    if (*fmt == '\0')
        return NULL;
    for (int i = 0; i < 10; i++) {
        if (!my_strncmp(fmt, cmp[i].cmp, my_strnlen(cmp[i].cmp, 2))) {
            cinfo->len_mod = cmp[i].mod;
            return fmt += my_strnlen(cmp[i].cmp, 2);
        }
    }
    return fmt;
}

__attribute__((optimize("unroll-loops")))
const char *parse_specifier(conv_info_t *cinfo, const char *fmt)
{
    const char *(*parse_funcs[4])(conv_info_t *, const char *) = {
        &parse_flag, &parse_width, &parse_prec, &parse_len_mod
    };

    for (int i = 0; i < 4; i++) {
        fmt = parse_funcs[i](cinfo, fmt);
        if (fmt == NULL)
            return NULL;
    }
    return fmt;
}
