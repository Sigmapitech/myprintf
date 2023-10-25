/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_handler_base.c
*/

#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "test_conv_func.h"

Test(conv_str, left_padded_string, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_PAD_LEFT,
        .width = 5
    };

    test_conv_func(&cinfo, &conv_str, "  abc", "abc");
}

Test(conv_str, right_padded_string, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 5
    };

    test_conv_func(&cinfo, &conv_str, "abc  ", "abc");
}
