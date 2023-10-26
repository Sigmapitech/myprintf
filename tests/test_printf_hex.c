/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_printf_hex.c
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "my.h"

Test(test_printf, low_hex_pad, .init = cr_redirect_stdout)
{
    my_printf("<%-05x>\n", 3301);
    cr_assert_stdout_eq_str("<00ce5>\n");
}

Test(test_printf, up_hex_pad, .init = cr_redirect_stdout)
{
    my_printf("[%4X]\n", 3301);
    cr_assert_stdout_eq_str("[CE5 ]\n");
}
