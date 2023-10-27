/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_printf_int.c
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

Test(test_printf, bounds, .init = cr_redirect_stdout)
{
    my_printf("[%d]", -2147483648);
    my_printf("[%d]\n", 2147483647);
    cr_assert_stdout_eq_str("[-2147483648][2147483647]\n");
}

Test(test_printf, simple_padding, .init = cr_redirect_stdout)
{
    my_printf("[%-4d]", 123);
    my_printf("[%4d]\n", 123);
    cr_assert_stdout_eq_str("[ 123][123 ]\n");
}

Test(test_printf, zero_padding, .init = cr_redirect_stdout)
{
    my_printf("[%05d]\n", 789);
    cr_assert_stdout_eq_str("[00789]\n");
}
