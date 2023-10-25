/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strlen.c
*/

#include <stddef.h>
#include "my.h"

int my_strlen(char const *str)
{
    char const *p = str;

    if (str == NULL)
        return -1;
    for (; *p != '\0'; ++p)
        ;
    return p - str;
}

int my_strnlen(char const *str, int n)
{
    char const *p = str;

    if (str == NULL)
        return -1;
    for (; n-- && *p != '\0'; ++p)
        ;
    return p - str;
}
