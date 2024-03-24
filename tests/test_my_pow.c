#include <criterion/criterion.h>

#include "my.h"

Test(my_pow, test_zero)
{
    cr_assert_eq(my_pow(0, 0), 1);
    cr_assert_eq(my_pow(1, 0), 1);
    cr_assert_eq(my_pow(0, 1), 0);
}

Test(my_pow, simple_numbers)
{
    cr_assert_eq(my_pow(3, 3), 27);
    cr_assert_eq(my_pow(3, 6), 729);
    cr_assert_eq(my_pow(2, 18), 262144);
    cr_assert_eq(my_pow(58, 4), 11316496);
    cr_assert_eq(my_pow(21, 7), 1801088541);
}

Test(my_pow, negative)
{
    cr_assert_eq(my_pow(0, -1), 0);
}
