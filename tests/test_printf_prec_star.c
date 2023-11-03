/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include "my.h"
#include "test_internal.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/parameterized.h>

#include <stdio.h>

Test(my_printf, passing_width_as_extra_argument, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%.*s", 10, "hello world"), 10);
    cr_assert_stdout_eq_str("hello worl");
}

Test(my_printf, negative_width_star_argument, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%.*s", -1, "hello world"), 11);
    cr_assert_stdout_eq_str("hello world");
}
