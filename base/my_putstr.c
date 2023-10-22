/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_putstr.c
*/

#include "my.h"

int my_putstr(char const *str)
{
    while (*str != '\0')
        my_putchar(*str++);
    return 0;
}
