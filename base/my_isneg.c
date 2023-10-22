/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_isneg.c
*/

#include "my.h"

int my_isneg(int n)
{
    my_putchar('N' + ((n >= 0) << 1));
    return 0;
}
