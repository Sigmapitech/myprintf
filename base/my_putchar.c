/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_putchar.c
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    (void)write(STDOUT_FILENO, &c, sizeof(char));
}
