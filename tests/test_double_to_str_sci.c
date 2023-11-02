/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_double_to_str.c
*/

#include <criterion/criterion.h>
#include <stdio.h>

#include "internal.h"

Test(double_to_str_sci, test_nice)
{
    double d = 420.69;
    char str[64] = { 0 };

    double_to_str_sci(str, d, 2);
    cr_assert_str_eq(str, "4.21e+02");
}

Test(double_to_str_sci, test_zero)
{
    double d = 0;
    char str[64] = { 0 };

    double_to_str_sci(str, d, 0);
    cr_assert_str_eq(str, "0e+00");
}

Test(double_to_str_sci, test_big)
{
    double d = 1234567.891011;
    char str[64] = { 0 };

    double_to_str_sci(str, d, 6);
    cr_assert_str_eq(str, "1.234568e+06");
}

Test(double_to_str_sci, test_big2)
{
    double d = 1234567.891019;
    char str[64] = { 0 };

    double_to_str_sci(str, d, 6);
    cr_assert_str_eq(str, "1.234568e+06");
}

/*
int main(void)
{
    double d = 420.69;
    char str[64] = { '$' };

    fprintf(stderr, "-- in main --\n");
    double_to_str_sci(str, d, 2);
    fprintf(stderr, "-- str [420.69] -> [4.21e+02] => [%s] --\n", str);
    fprintf(stderr, "-- out main --\n");
    return 0;
}
*/
