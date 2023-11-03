/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** stringify_helpers.c
*/

#include "float.h"

int handle_non_numbers(char *out, dpart_t dpart)
{
    if (dpart.mentissa != 0)
        return put_in_str(out, "nan");
    return put_in_str(out, dpart.sign ? "-inf" : "inf");
}

void round_up(char *out, int len)
{
    --len;
    for (; out[len] == '9'; len--)
        out[len] = '0';
    out[len]++;
}

int put_in_str(char *out, const char *in)
{
    int i;

    for (i = 0; in[i] != '\0'; i++)
        out[i] = in[i];
    out[i] = in[i];
    return i;
}
