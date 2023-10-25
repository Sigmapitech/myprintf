/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_parse_handle_lookahead.c
*/

#include <limits.h>
#include <criterion/criterion.h>
#include <stdio.h>

#include "my.h"
#include "internal.h"

static
void test_handle_out(char *expected, const char *input)
{
    conv_info_t cinfo = { 0 };

    cr_assert_eq(expected, handle_lookahead(&cinfo, input));
}

static
void test_handle(conv_info_t *exp, const char *input)
{
    conv_info_t got = {
        0, .len_mod = CONV_NO
    };

    handle_lookahead(&got, input);
    fprintf(
        stderr, "got = (flag=%hhd, with=%zu, prec=%d, lenmod=%d)\n",
        got.flag, got.width, got.prec, got.len_mod);
    fprintf(
        stderr, "exp = (flag=%hhd, with=%zu, prec=%d, lenmod=%d)\n",
        exp->flag, exp->width, exp->prec, exp->len_mod);
    cr_assert_eq(exp->flag, got.flag);
    cr_assert_eq(exp->width, got.width);
    cr_assert_eq(exp->prec, got.prec);
    cr_assert_eq(exp->len_mod, got.len_mod);
}

Test(parse, empty_str)
{
    test_handle_out(NULL, "\0");
}

Test(parse, all_flags_enabled)
{
    conv_info_t expected = {
        .flag = 31, .width = 0, .prec = INT_MAX, .len_mod = CONV_NO
    };

    test_handle(&expected, "+#0- i!!!!!/n");
}
