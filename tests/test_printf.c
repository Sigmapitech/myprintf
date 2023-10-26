/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_setup.c
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

Test(test_vdprintf, test_basic, .init = cr_redirect_stdout)
{
    my_printf("hello world!");
    cr_assert_stdout_eq_str("hello world!");
}

Test(test_vdprintf, test_basic, .init = cr_redirect_stdout)
{
    my_printf("hello %s", "world!");
    cr_assert_stdout_eq_str("hello world!");
}
