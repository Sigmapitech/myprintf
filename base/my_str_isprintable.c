/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_str_isprintable.c
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    for (; *str != '\0'; str++)
        if (!IS_PRINT(*str))
            return 0;
    return 1;
}
