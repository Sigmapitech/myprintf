/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strnlen.c
*/

#include <stddef.h>
#include "my.h"

int my_strnlen(const char *str, int n)
{
    char const *p = str;

    if (str == NULL)
        return -1;
    for (; n-- && *p != '\0'; ++p)
        ;
    return p - str;
}
