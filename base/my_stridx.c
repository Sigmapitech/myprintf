/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_stridx.c
*/
int my_stridx(const char *str, char c)
{
    for (const char *p = str; *p != '\0'; p++)
        if (*p == c)
            return p - str;
    return -1;
}
