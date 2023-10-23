/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** convertion_base.c
*/
#include "internal.h"

int print_char(int fd, print_info_t pinfo)
{
    pinfo->arg.c = (char)va_arg(pinfo->ap, int);
    return write(fd, *pinfo->arg.c, 1);
}

int print_int(int fd, print_info_t pinfo)
{
    pinfo->arg.i = va_arg(pinfo->ap, int);
    return put_nbr(fd, *pinfo->arg.i);
}

int print_str(int fd, print_info_t pinfo)
{
    pinfo->arg.p = va_arg(*pinfo->ap, char *);
    return write(fd, *pinfo->arg.p, my_strlen(pinfo->arg.p));
}

int print_percent(int fd, print_info_t pinfo)
{
    return write(fd, "%", 1);
}
