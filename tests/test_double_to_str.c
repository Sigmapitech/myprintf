#include <criterion/criterion.h>

#include <stdio.h>

#include "core/internal.h"

Test(double_to_str, test_nice)
{
    double d = 420.69;
    char str[64] = { 0 };

    double_to_str(str, d, 2);
    cr_assert_str_eq(str, "420.69");
}

Test(double_to_str, test_zero)
{
    double d = 0;
    char str[64] = { 0 };

    double_to_str(str, d, 0);
    cr_assert_str_eq(str, "0");
}

Test(double_to_str, test_big)
{
    double d = 1234567.891011;
    char str[64] = { 0 };

    double_to_str(str, d, 6);
    cr_assert_str_eq(str, "1234567.891011");
}

Test(double_to_str, test_big2)
{
    double d = 1234567.891019;
    char str[64] = { 0 };

    double_to_str(str, d, 6);
    cr_assert_str_eq(str, "1234567.891019");
}
