/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_setup.c
*/
#include <criterion/criterion.h>
#include "my.h"
#include "internal.h"

static
void test_fag(char expected, char *input)
{
    cr_assert_eq(parse_flag(&input), expected);
}

Test(parse_flag, noflag)
{
    test_fag(0, "i");
    test_fag(0, "12.4hhi");
    test_fag(0, "%");
    test_fag(0, "=");
    test_fag(0, "s");
    test_fag(0, "c");
}

Test(parse_flag, empty_str)
{
    test_fag(-1, "");
}
