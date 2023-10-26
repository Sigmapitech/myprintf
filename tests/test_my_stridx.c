/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_stridx, test_indexing)
{
    cr_assert_eq(my_stridx("Hello", 'H'), 0);
    cr_assert_eq(my_stridx("hello world", 'w'), 6);
    cr_assert_eq(my_stridx("hello world", 'l'), 2);
    cr_assert_eq(my_stridx("abcdefghijklmnopqrstuvxwyz", 'z'), 25);
}

Test(my_stridx, not_found)
{
    cr_assert_eq(my_stridx("hello", 'Q'), -1);
}
