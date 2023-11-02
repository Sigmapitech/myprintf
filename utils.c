/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** utils.c
*/
#include <unistd.h>


int putnchar(int fd, char c, int nb)
{
    for (int n = nb; n--;)
        write(fd, &c, sizeof(char));
    return nb;
}
