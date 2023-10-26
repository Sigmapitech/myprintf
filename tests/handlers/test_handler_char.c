/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "test_conv_func.h"

Test(conv_char, simple_char, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 1,
        .prec = INT_MAX,
    };

    test_conv_func(&cinfo, &conv_char, "c", 'c');
}

Test(conv_char, left_padded_char, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_PAD_LEFT,
        .width = 3,
        .prec = INT_MAX
    };

    test_conv_func(&cinfo, &conv_char, "  c", 'c');
}

Test(conv_char, right_padded_char, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 4,
        .prec = INT_MAX
    };

    test_conv_func(&cinfo, &conv_char, "c   ", 'c');
}
