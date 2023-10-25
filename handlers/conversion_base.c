/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** convertion_base.c
*/

#include <stdio.h>
#include <unistd.h>

#include "internal.h"
#include "my.h"

int conv_char(print_info_t *pinfo, conv_info_t *cinfo)
{
    return 0;
}

int conv_int(print_info_t *pinfo, conv_info_t *cinfo)
{
    return 0;
}

int conv_str(print_info_t *pinfo, conv_info_t *cinfo)
{
    char *s = va_arg(pinfo->ap, char *);
    int len = my_strnlen(s, cinfo->width);
    int pad = cinfo->width - len;

    if (pad > 0 && cinfo->flag & F_LEFTPAD) {
        fprintf(stderr, "kek!\n");
        putnchar(pinfo->fd, ' ', pad);
    }
    write(pinfo->fd, s, len);
    if (pad > 0 && cinfo->flag & ~F_LEFTPAD)
        putnchar(pinfo->fd, pad, ' ');
    return 0;
}

int conv_ptr(print_info_t *pinfo, conv_info_t *cinfo)
{
    return 0;
}

// percent
int conv_per(print_info_t *pinfo, conv_info_t *cinfo)
{
    return 0;
}
