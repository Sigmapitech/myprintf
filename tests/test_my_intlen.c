/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** test_my_stridx.c
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_intlen, test_zero)
{
    cr_assert_eq(my_intlen(0), 1);
}

Test(my_intlen, simple_numbers)
{
    cr_assert_eq(my_intlen(8), 1);
    cr_assert_eq(my_intlen(3301), 4);
}
