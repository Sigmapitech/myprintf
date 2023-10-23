/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int length = my_strlen(dest);
    int idx = 0;

    for (; *src != '\0'; idx++)
        dest[idx + length] = *src++;
    return dest;
}
