/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_putnbr.c
*/

#include <unistd.h>
#include "my.h"

static
void cycle_print(int fd, int n)
{
    char c;

    if (n < -9)
        cycle_print(fd, n / 10);
    c = '0' - (n % 10);
    write(fd, &c, sizeof(char));
}

int my_putnbr(int fd, int n)
{
    if (n >= 0)
        n = -n;
    else
        write(fd, "-", sizeof(char));
    cycle_print(fd, n);
    return 0;
}
