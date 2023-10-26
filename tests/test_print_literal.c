/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_print_literal.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "internal.h"
#include "unistd.h"

Test(print_literal, string_end, .init = cr_redirect_stdout)
{
    print_info_t pinfo = { .fd = STDOUT_FILENO };

    print_literal(&pinfo, "hello\n");
    cr_assert_stdout_eq_str("hello\n");
}

Test(print_literal, middle_string, .init = cr_redirect_stdout)
{
    print_info_t pinfo = { .fd = STDOUT_FILENO };

    print_literal(&pinfo, "hello%");
    cr_assert_stdout_eq_str("hello");
}
