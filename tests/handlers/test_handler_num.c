/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_handler_num.c
*/

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "internal.h"
#include "test_conv_func.h"

Test(conv_int, simple_zero, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 1,
        .prec = INT_MAX,
    };

    test_conv_func(&cinfo, &conv_int, "0", 0);
}

Test(conv_int, int_min, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 1,
        .prec = INT_MAX,
    };

    test_conv_func(&cinfo, &conv_int, "-2147483648", -2147483648);
}

Test(conv_int, int_max, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 1,
        .prec = INT_MAX,
    };

    test_conv_func(&cinfo, &conv_int, "2147483647", 2147483647);
}

Test(conv_int, int_padded, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 7,
        .prec = INT_MAX,
    };

    test_conv_func(&cinfo, &conv_int, "3301   ", 3301);
}
