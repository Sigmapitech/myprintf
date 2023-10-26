/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** test_my_putnbr_base.c
*/

#include <limits.h>
#include <string.h>

#include <criterion/criterion.h>
#include "my.h"

Test(my_revstr, _1_base_10)
{
    char buf[64];

    memset(buf, '\0', 64);
    my_putnbr_base(buf, "0123456789", 1);
    cr_assert_str_eq(buf, "1");
}

Test(my_revstr, _int_max_base_10)
{
    char buf[64];

    memset(buf, '\0', 64);
    my_putnbr_base(buf, "0123456789", 2147483647);
    cr_assert_str_eq(buf, "2147483647");
}

Test(my_revstr, _int_min_base_10)
{
    char buf[64];

    memset(buf, '\0', 64);
    my_putnbr_base(buf, "0123456789", -2147483648);
    cr_assert_str_eq(buf, "-2147483648");
}
