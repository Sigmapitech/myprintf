/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** utils.c
*/

#include "my.h"
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

void int_to_hex(char *buff, unsigned int input)
{
    for (int i = sizeof(int) * 2 -1; 0 <= i; i--) {
        buff[i] = (input & 15);
        buff[i] += buff[i] <= 9 ? '0' : 'a';
        input >>= 4;
    }
}
