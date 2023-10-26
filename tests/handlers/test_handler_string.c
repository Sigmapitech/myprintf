/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_handler_string_edge_cases.c
*/

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "test_conv_func.h"

Test(conv_str, null_string)
{
    conv_info_t cinfo = {
        .flag = F_NO_FLAG,
        .width = 3,
        .prec = 0,
    };

    test_conv_func(&cinfo, &conv_str, "(null)", NULL);
}
