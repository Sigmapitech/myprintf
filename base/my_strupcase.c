/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strupcase.c
*/

#include <stddef.h>
#include "my.h"

char *my_strupcase(char *str)
{
    const char up_mask = ~(1 << 5);
    char *p = str;

    for (; *p != '\0'; p++)
        if (IS_LOWER(*p))
            *p &= up_mask;
    return str;
}
