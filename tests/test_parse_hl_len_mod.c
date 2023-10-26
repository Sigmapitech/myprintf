/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_parse_handle_lookahead_width.c
*/

#include <limits.h>
#include <criterion/criterion.h>
#include <stdio.h>

#include "my.h"
#include "internal.h"

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

Test(parse_len_mod, len_mod_single)
{
    conv_info_t expected = {
        .flag = 0, .width = 0, .prec = INT_MAX, .len_mod = CONV_SHORT
    };

    test_handle(&expected, "hi!!!!!\n");
}

Test(parse_len_mod, len_mod_double)
{
    conv_info_t expected = {
        .flag = 0, .width = 0, .prec = INT_MAX, .len_mod = CONV_CHAR
    };

    test_handle(&expected, "hhi!!!!!\n");
}

Test(parse_len_mod, len_mod_null)
{
    conv_info_t expected = {
        .flag = 0, .width = 0, .prec = INT_MAX, .len_mod = CONV_NO
    };

    test_handle(&expected, "i!!!!!\n");
}

Test(parse_len_mod, len_mod_end_of_str)
{
    conv_info_t expected = {
        .flag = 0, .width = 0, .prec = 0, .len_mod = CONV_NO
    };

    test_handle(&expected, "");
}
