/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strcapitalize.c
*/

#include <stdbool.h>
#include <stdio.h>

#include "my.h"

char *my_strcapitalize(char *str)
{
    char *p = str;

    for (bool k = true; *p != '\0'; k = ++p && !IS_ALNUM(*(p - 1)))
        if (IS_ALNUM(*p))
            *p = (k && !IS_DIGIT(*p))
                ? (*p & ~(1 << 5))
                : (*p | 1 << 5);
    return str;
}
