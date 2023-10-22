/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_strstr.c
*/

#include <stddef.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int needle_size = my_strlen(to_find);

    if (*to_find == '\0')
        return str;
    for (; *str != '\0'; str++)
        if (!my_strncmp(str, to_find, needle_size))
            return str;
    return NULL;
}
