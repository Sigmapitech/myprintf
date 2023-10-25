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

Test(conv_str, left_padded_string, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_PAD_LEFT,
        .width = 5,
        .prec = INT_MAX
    };

    test_conv_func(&cinfo, &conv_str, "  abc", "abc");
}

Test(conv_str, right_padded_string, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 5,
        .prec = INT_MAX
    };

    test_conv_func(&cinfo, &conv_str, "abc  ", "abc");
}

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

Test(conv_str, precision_and_pad, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 3,
        .prec = 2,
    };

    test_conv_func(&cinfo, &conv_str, "ab ", "abc");
}
