/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_printf_num_prec_zero.c
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"


/* "When 0 is printed with an explicit precision 0, the output is empty." */

Test(test_printf, d_zero_prec_zero, .init = cr_redirect_stdout)
{
    my_printf("[%.0d]\n", 0);
    cr_assert_stdout_eq_str("[]\n");
}

Test(test_printf, u_zero_prec_zero, .init = cr_redirect_stdout)
{
    my_printf("[%.0u]\n", 0);
    cr_assert_stdout_eq_str("[]\n");
}

Test(test_printf, o_zero_prec_zero, .init = cr_redirect_stdout)
{
    my_printf("[%.0o]\n", 0);
    cr_assert_stdout_eq_str("[]\n");
}

Test(test_printf, x_zero_prec_zero, .init = cr_redirect_stdout)
{
    my_printf("[%.0x][%.0X]\n", 0, 0);
    cr_assert_stdout_eq_str("[][]\n");
}
