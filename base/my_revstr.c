/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_revstr.c
*/

#include "my.h"

char *my_revstr(char *str)
{
    unsigned int len = my_strlen(str);
    unsigned int half = len >> 1;
    char swap;

    for (unsigned int i = 0; i < half; i++) {
        swap = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = swap;
    }
    return str;
}
