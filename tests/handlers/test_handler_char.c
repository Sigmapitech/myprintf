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

#include "test_conv_func.h"

Test(conv_char, simple_char)
{
    conv_info_t cinfo = {
        .width = 1,
        .prec = INT_MAX,
    };

    test_conv_func(&cinfo, &conv_char, "c", 'c');
}
