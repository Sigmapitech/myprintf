/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strcpy.c
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
    return dest;
}
