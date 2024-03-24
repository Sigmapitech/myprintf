#include <criterion/criterion.h>

#include "my.h"

Test(my_strnlen, limit_to_n)
{
    cr_assert_eq(my_strnlen("hello world!", 5), 5);
    cr_assert_eq(my_strnlen("test", 1), 1);
}

Test(my_strnlen, return_the_correct_length)
{
    cr_assert_eq(my_strnlen("hello!", 23), 6);
    cr_assert_eq(my_strnlen("bonjour", 7), 7);
}

Test(my_strnlen, string_is_null)
{
    cr_assert_eq(my_strnlen(NULL, 0), -1);
    cr_assert_eq(my_strnlen(NULL, 2), -1);
}
