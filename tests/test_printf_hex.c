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

Test(test_printf, hex_pad_values, .init = cr_redirect_stdout)
{
    my_printf("[%-4x]", 3301);
    my_printf("[%4X]\n", 3301);
    cr_assert_stdout_eq_str("[ ce5][CE5 ]\n");
}

Test(test_printf, hex_alt, .init = cr_redirect_stdout)
{
    my_printf("[%#X]", 3301);
    my_printf("[%#x]", 3301);
    my_printf("[%#x]", 0);
    my_printf("[%#X]\n", 0);
    cr_assert_stdout_eq_str("[0XCE5][0xce5][0][0]\n");
}

Test(test_printf, hex_dash_zero_exclusion, .init = cr_redirect_stdout)
{
    my_printf("[%0-4x]", 3301);
    my_printf("[%-04X]\n", 3301);
    cr_assert_stdout_eq_str("[ce5 ][CE5 ]\n");
}
