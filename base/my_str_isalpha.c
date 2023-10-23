/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_str_isalpha.c
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (; *str != '\0'; str++)
        if (!IS_ALPHA(*str))
            return 0;
    return 1;
}
