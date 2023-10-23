/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strncpy.c
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (; n > 0 && *src != '\0'; --n)
        *dest++ = *src++;
    if (n)
        *dest = '\0';
    return dest;
}
