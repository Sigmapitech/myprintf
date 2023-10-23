/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_str_isupper.c
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    for (; *str != '\0'; str++)
        if (!IS_UPPER(*str))
            return 0;
    return 1;
}
