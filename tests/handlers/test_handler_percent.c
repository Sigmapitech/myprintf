/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_handler_char.c
*/

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "internal.h"
#include "test_conv_func.h"

Test(conv_per, precent, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 1,
        .prec = INT_MAX,
    };

    test_conv_func(&cinfo, &conv_per, "%");
}

Test(conv_per, precent_is_always_percent, .init = cr_redirect_stdout)
{
    conv_info_t cinfo = {
        .width = 5,
        .prec = 0,
        .flag = F_PAD_LEFT | F_PAD_ZERO | F_ALT_FORM,
        .len_mod = CONV_PTDRDIFF_T
    };

    test_conv_func(&cinfo, &conv_per, "%");
}
