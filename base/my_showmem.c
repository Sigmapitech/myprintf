/*
** EPITECH PROJECT, 2023
** C Workshop Lib
** File description:
** my_showmem.c
*/

#include "my.h"

static
void my_show_memblock(char const *mem, int n)
{
    int leftover = 16 - n;
    int group = 16;

    my_putstr(": ");
    while (n--) {
        my_puthex((int)(unsigned char)*mem++, 2);
        if (group-- & 1)
            my_putchar(' ');
    }
    while (leftover--) {
        my_putstr("  ");
        if (group-- & 1)
            my_putchar(' ');
    }
}

static
void my_show_ascii(char const *mem, int n)
{
    for (; n--; mem++)
        my_putchar(IS_PRINT(*mem) ? *mem : '.');
}

int my_showmem(char const *str, int size)
{
    char const *p = str;

    for (; size > 0; p += 16) {
        my_puthex(p - str, 8);
        my_show_memblock(p, MIN(16, size));
        my_show_ascii(p, MIN(16, size));
        my_putchar('\n');
        size -= 16;
    }
    return 0;
}
