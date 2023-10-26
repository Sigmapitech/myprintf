/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_my_putnbr.c
*/

#include <stdio.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"


Test(my_putchar, simple_numbers, .init = cr_redirect_stdout)
{
    my_putnbr(STDOUT_FILENO, 0);
    my_putnbr(STDOUT_FILENO, 4);
    my_putnbr(STDOUT_FILENO, 789);
    my_putnbr(STDOUT_FILENO, 3301);
    cr_assert_stdout_eq_str("047893301");
}

Test(my_putchar, negatives, .init = cr_redirect_stdout)
{
    my_putnbr(STDOUT_FILENO, -6);
    my_putnbr(STDOUT_FILENO, -123);
    my_putnbr(STDOUT_FILENO, -4269);
    cr_assert_stdout_eq_str("-6-123-4269");
}

Test(my_putchar, bounds, .init = cr_redirect_stdout)
{
    my_putnbr(STDOUT_FILENO, 2147483647);
    my_putnbr(STDOUT_FILENO, -2147483648);
    cr_assert_stdout_eq_str("2147483647-2147483648");
}
