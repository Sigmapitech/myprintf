/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_str_islower.c
*/

#include "my.h"

int my_str_islower(char const *str)
{
    for (; *str != '\0'; str++)
        if (!IS_LOWER(*str))
            return 0;
    return 1;
}
