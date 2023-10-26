/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** utils.c
*/

#include <unistd.h>

int putnchar(int fd, char c, int nb)
{
    int written;

    for (int n = nb; n--;) {
        written = write(fd, &c, sizeof(char));
        if (written == -1)
            return nb - n;
    }
    return nb;
}
