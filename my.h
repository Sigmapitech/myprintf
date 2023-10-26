/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my.h
*/

#ifndef LIB_MY_H
    #define LIB_MY_H

    #define ABS(x) (((x) > 0) ? (-x) : (x))
    #define MIN(x, y) ((x > y) ? (y) : (x))

    #define C_UP(c) ((c) | ' ')
    #define BOUNDS(c, lo, hi) (((c) >= (lo)) && ((c) <= (hi)))

    #define IS_LOWER(c) (BOUNDS(c, 'a', 'z'))
    #define IS_UPPER(c) (BOUNDS(c, 'A', 'Z'))
    #define IS_DIGIT(c) (BOUNDS(c, '0', '9'))
    #define IS_PRINT(c) (BOUNDS(c, ' ', '~'))

    #define IS_ALPHA(c) (IS_LOWER(C_UP(c)))
    #define IS_ALNUM(c) (IS_ALPHA(c) || IS_DIGIT(c))

    #define ATTR(key) __attribute__((key))
    #define UNUSED ATTR(unused)

    // Static len have the size of the number of characters their are
    // composed of, including the '\0'
    #define SSTR_LEN(s) (sizeof(s) - 1)

    #include <stdarg.h>

int my_intlen(int i);
int my_stridx(const char *str, char c);
int my_strnlen(char const *str, int n);
int my_strncmp(char const *s1, char const *s2, int n);
int my_putnbr(char *s, int nb);

// Delivery
int my_printf(const char *format, ...);
int my_vdprintf(int fd, const char *format, va_list ap);

#endif
