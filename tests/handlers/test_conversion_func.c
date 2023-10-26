/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_conversion_func.c
*/

#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "internal.h"
#include "test_conv_func.h"

static
void log_to_stderr(
    const char *exp,
    conv_info_t *cinfo,
    conv_func_t convf,
    va_list *ap)
{
    char buf[64];
    print_info_t pinfo = { .fd = STDERR_FILENO };

    pinfo.buf.s = buf;
    setbuf(stderr, NULL);
    fprintf(
        stderr,
        "(flagv=%d, prec=%d, width=%d) : [",
        cinfo->flag, cinfo->prec, cinfo->width);
    va_copy(pinfo.ap, *ap);
    convf(&pinfo, cinfo);
    va_end(pinfo.ap);
    fprintf(stderr, "] <=> [%s]\n", exp);
}

void test_conv_func(
    conv_info_t *cinfo,
    conv_func_t convf,
    char const *exp,
    ...)
{
    char buf[64];
    print_info_t pinfo = { .fd = STDOUT_FILENO };

    pinfo.buf.s = buf;
    pinfo.buf.written = 0;
    memset(pinfo.buf.s, '\0', 64);
    va_start(pinfo.ap, exp);
    log_to_stderr(exp, cinfo, convf, &pinfo.ap);
    convf(&pinfo, cinfo);
    va_end(pinfo.ap);
    cr_assert_str_eq(pinfo.buf.s, exp);
}
