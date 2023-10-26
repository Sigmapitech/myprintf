/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <stdio.h>
#include "my.h"

int my_intlen(int i)
{
    int n = 0;

    if (i == 0)
        return 1;
    for (; i != 0; i /= 10)
        n++;
    return n;
}
