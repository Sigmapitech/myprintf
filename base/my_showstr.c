/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_showstr.c
*/

#include "my.h"

void my_puthex(int line, int pad)
{
    int len = 0;

    for (int copy = line; copy; copy /= 16)
        len++;
    for (int n = pad - len; n; --n)
        my_putchar('0');
    if (line)
        my_putnbr_base(line, "0123456789abcdef");
}

int my_showstr(char const *str)
{
    for (; *str != '\0'; str++) {
        if (IS_PRINT(*str))
            my_putchar(*str);
        else {
            my_putchar('\\');
            my_puthex((int)(*str), 2);
        }
    }
    return 0;
}
