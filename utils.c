/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** utils.c
*/

#include <unistd.h>

int put_nbr(int fd, int nb)
{
    int out = nb / 10;
    char c;

    if (nb == 0)
        return write(fd, "0", 1);
    if (nb < 0) {
        c = '-';
        write(fd, &c, 1);
        out = out != 0 ? put_nbr(fd, ~out + 1) : 0;
        out++;
        c = ~(nb % 10) + 1 + '0';
        write(fd, &c, 1);
    } else {
        out = out != 0 ? put_nbr(fd, out) : 0;
        c = nb % 10 + '0';
        write(fd, &c, 1);
    }
    return out + 1;
}
