/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** split_parts.c
*/

#include "float.h"

void init_dpart(double d, dpart_t *dpart)
{
    union {
        double d;
        unsigned long long ull;
    } fh = { .d = d };

    dpart->sign = (fh.ull >> 63) & 1;
    dpart->exponant = (fh.ull >> 52) & 0x7ff;
    dpart->mentissa = fh.ull & 0x000fffffffffffffL;
}
