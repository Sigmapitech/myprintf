/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_setup.c
*/

#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "internal.h"
#include "my.h"

static
void test_conv_func(conv_func_t convf, char *exp, ...)
{
    print_info_t pinfo = { .fd = STDOUT_FILENO };
    conv_info_t cinfo = {
        .flag = F_PAD_LEFT,
        .width = 5
    };

    va_start(pinfo.ap, exp);
    convf(&pinfo, &cinfo);
    va_end(pinfo.ap);
    cr_assert_stdout_eq_str(exp);
}

Test(conv_str, left_padded_string, .init = cr_redirect_stdout)
{
    test_conv_func(&conv_str, "  abc", "abc");
}
