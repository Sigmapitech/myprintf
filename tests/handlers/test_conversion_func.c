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
void log_to_stderr(conv_info_t *cinfo, conv_func_t convf, va_list ap)
{
    print_info_t pinfo = { .fd = STDERR_FILENO };

    setbuf(stderr, NULL);
    fprintf(stderr, "[");
    va_copy(pinfo.ap, ap);
    convf(&pinfo, cinfo);
    va_end(pinfo.ap);
    fprintf(stderr, "]\n");
}

void test_conv_func(
    conv_info_t *cinfo,
    conv_func_t convf,
    char const *exp,
    ...)
{
    print_info_t pinfo = { .fd = STDOUT_FILENO };

    va_start(pinfo.ap, exp);
    log_to_stderr(cinfo, convf, pinfo.ap);
    convf(&pinfo, cinfo);
    va_end(pinfo.ap);
    cr_assert_stdout_eq_str(exp);
}
