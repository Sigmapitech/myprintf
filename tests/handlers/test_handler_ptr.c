/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_handler_ptr.c
*/

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "internal.h"
#include "test_conv_func.h"

Test(conv_ptr, pointer)
{
    void *p = (void *)0x4815162342f;
    conv_info_t cinfo = {
        .width = 1,
        .prec = INT_MAX,
    };

    test_conv_func(&cinfo, &conv_ptr, "0x4815162342f", p);
}
