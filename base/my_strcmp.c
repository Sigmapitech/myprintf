/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (; *s1 && *s1 == *s2; s1++)
        s2++;
    return *s1 - *s2;
}
