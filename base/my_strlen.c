/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_strlen.c
*/
#include "my.h"

int my_strlen(char const *str)
{
    char const *p = str;

    for (; *p != '\0'; ++p)
        ;
    return p - str;
}
