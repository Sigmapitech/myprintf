/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** test_my_putnbr_base_16.c
*/

#include <limits.h>
#include <string.h>

#include <criterion/criterion.h>
#include "my.h"

Test(my_revstr, _1_base_16)
{
    char buf[64];

    memset(buf, '\0', 64);
    my_putnbr_base(buf, "0123456789abcdef", 1);
    cr_assert_str_eq(buf, "1");
}

Test(my_revstr, _int_max_base_16)
{
    char buf[64];

    memset(buf, '\0', 64);
    my_putnbr_base(buf, "0123456789abcdef", 2147483647);
    cr_assert_str_eq(buf, "7fffffff");
}
