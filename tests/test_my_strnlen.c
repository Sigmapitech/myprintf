/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strnlen, limit_to_n)
{
    cr_assert_eq(my_strnlen("hello world!", 5), 5);
}

Test(my_strnlen, return_the_correct_length)
{
    cr_assert_eq(my_strnlen("hello!", 23), 6);
}
