#include <stdio.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"


Test(my_putchar, simple_numbers)
{
    char buf[64];

    memset(buf, '\0', 63);
    my_putnbr(buf, 0);
    cr_assert_str_eq(buf, "0");
    my_putnbr(buf, 4);
    cr_assert_str_eq(buf, "4");
    my_putnbr(buf, 789);
    cr_assert_str_eq(buf, "789");
    my_putnbr(buf, 3301);
    cr_assert_str_eq(buf, "3301");
}

Test(my_putchar, bounds)
{
    char buf[64];

    memset(buf, '\0', 63);
    my_putnbr(buf, 2147483647);
    cr_assert_str_eq(buf, "2147483647");
    my_putnbr(buf, -2147483648);
    cr_assert_str_eq(buf, "2147483648");
}
