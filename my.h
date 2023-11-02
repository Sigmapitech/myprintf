/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my.h
*/

#ifndef LIB_MY_H
    #define LIB_MY_H

    #include <stdarg.h>
    #include <stddef.h>
    #include <stdint.h>

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

ATTR(used) static
const char *BASE_CHARSET = "0123456789abcdef";

int my_base_len(int base, size_t n);
int my_intlen(intmax_t i);
int my_pow(int nb, int p);
int my_putnbr(char *s, intmax_t nb);
int my_putnbr_base(char *s, size_t base, size_t n);
int my_stridx(const char *str, char c);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strnlen(char const *str, int n);

// Delivery
int my_printf(const char *format, ...);
int my_vdprintf(int fd, const char *format, va_list ap);
void my_int_to_hex(char *buff, int input);

#endif
