/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_printf_oct.c
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "my.h"

Test(test_printf, octal_flag, .init = cr_redirect_stdout)
{
    my_printf("%o\n", 3301);
    cr_assert_stdout_eq_str("6345\n");
}

Test(test_printf, octal_alt, .init = cr_redirect_stdout)
{
    my_printf("[%#o][%#o]\n", 0, 3301);
    cr_assert_stdout_eq_str("[0][06345]\n");
}
