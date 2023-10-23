/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strncat.c
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int length = my_strlen(dest);
    int idx = 0;

    for (; nb-- && *src != '\0'; idx++)
        dest[idx + length] = *src++;
    dest[idx + length] = '\0';
    return dest;
}
