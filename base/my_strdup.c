/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_strdup.c
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"

char *my_strdup(char const *src)
{
    char *out = malloc((my_strlen(src) + 1) * sizeof(char));

    if (out == NULL)
        return NULL;
    my_strcpy(out, src);
    return out;
}
