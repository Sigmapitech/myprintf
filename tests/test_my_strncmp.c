/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** test_my_strncmp.c
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include "my.h"

static
void test_strncmp(char const *s, char const *f, int n)
{
    int out = my_strncmp(s, f, n);
    int exp = strncmp(s, f, n);

    out = (out > 0) - (out < 0);
    exp = (exp > 0) - (exp < 0);
    cr_assert_eq(out, exp);
}

Test(my_strncmp, basic_substring)
{
    test_strncmp("hey", "hello", 2);
    test_strncmp("hello", "hey", 2);
}

Test(my_strncmp, different_ns)
{
    for (int n = 1; n < 5; n++) {
        test_strncmp("hey", "hello", n);
        test_strncmp("hello", "hey", n);
        test_strncmp("test!", "test!", n);
        test_strncmp("marvin", "marvin", n);
    }
}

Test(my_strncmp, n_futher)
{
    for (int n = 8; n < 12; n++) {
        test_strncmp("hey", "hello", n);
        test_strncmp("hello", "hey", n);
        test_strncmp("test!", "test!", n);
        test_strncmp("marvin", "marvin", n);
    }
}

Test(marvin, marvin)
{
    test_strncmp("marvin", "marvin", 10);
    test_strncmp("tests", "tests", 10);
}

Test(my_strncmp, marvin_n_eq_zero)
{
    test_strncmp("imagine all the people", "all", 0);
}
