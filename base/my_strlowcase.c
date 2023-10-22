/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_strlowcase.c
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    char *p = str;

    for (; *p != '\0'; p++)
        if (IS_UPPER(*p))
            *p |= (1 << 5);
    return str;
}
