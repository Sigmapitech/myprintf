/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_compute_square_root.c
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 0;

    for (; i * i < nb; i++);
    return (i * i == nb) ? i : 0;
}
