/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_handler_string.c
*/

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "test_conv_func.h"

Test(conv_str, precision_set_to_zero, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 0,
        .prec = 0,
    };

    test_conv_func(&cinfo, &conv_str, "", "abc");
}

Test(conv_str, precision_set_to_zero_with_pad, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 5,
        .prec = 0,
    };

    test_conv_func(&cinfo, &conv_str, "     ", "abc");
}

Test(conv_str, null_string, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 3,
        .prec = 0,
    };

    test_conv_func(&cinfo, &conv_str, "(null)", NULL);
}

Test(conv_str, null_string_with_pad, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 10,
        .prec = 0,
    };

    test_conv_func(&cinfo, &conv_str, "(null)    ", NULL);
}
