/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_print_literal.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "internal.h"
#include "unistd.h"

static
void log_to_stderr(
    const char *exp,
    conv_info_t *cinfo,
    char const *fmt,
    va_list *ap)
{
    char buf[64];
    print_info_t pinfo = { .fd = STDERR_FILENO };

    pinfo.buf.s = buf;
    pinfo.buf.written = 0;
    setbuf(stderr, NULL);
    fprintf(
        stderr,
        "(flagv=%d, prec=%d, width=%d) : [",
        cinfo->flag, cinfo->prec, cinfo->width);
    va_copy(pinfo.ap, *ap);
    print_format(&pinfo, cinfo, fmt);
    va_end(pinfo.ap);
    fprintf(stderr, "] <=> [%s]\n", exp);
}

static
void test_format(conv_info_t *cinfo, char const *exp, char const *fmt, ...)
{
    char buf[64];
    print_info_t pinfo = { .fd = STDOUT_FILENO };

    va_start(pinfo.ap, fmt);
    log_to_stderr(exp, cinfo, fmt, &pinfo.ap);
    pinfo.buf.s = buf;
    pinfo.buf.written = 0;
    print_format(&pinfo, cinfo, fmt);
    cr_assert_stdout_eq_str(exp);
}

Test(print_format, right_padded_str, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 7,
        .prec = 5,
        .flag = F_NO_FLAG,
        .len_mod = CONV_NO
    };

    test_format(&cinfo, "hello  ", "s", "hello!");
}

Test(print_format, left_padded_str, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 8,
        .prec = 12,
        .flag = F_PAD_LEFT,
        .len_mod = CONV_NO
    };

    test_format(&cinfo, "   hello", "s", "hello");
}
