/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_intlen.c
*/

#include <stdio.h>
#include "my.h"

int my_intlen(int i)
{
    int n = 1;

    for (i /= 10; i != 0; i /= 10)
        n++;
    return n;
}
