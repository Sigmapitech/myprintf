/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_printf.c
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "my.h"

Test(test_vdprintf, test_basic, .init = cr_redirect_stdout)
{
    my_printf("hello world!\n");
    cr_assert_stdout_eq_str("hello world!\n");
}

Test(test_vdprintf, test_str, .init = cr_redirect_stdout)
{
    my_printf("hello %s\n", "world!");
    cr_assert_stdout_eq_str("hello world!\n");
}

Test(test_vdprintf, test_string_hard, .init = cr_redirect_stdout)
{
    my_printf("%-5.4s%# c%.1s%5.4s\n", "this!", 'i', "s", "hello world");
    cr_assert_stdout_eq_str("this is hell\n");
}
