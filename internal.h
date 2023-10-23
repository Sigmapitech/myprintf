/*
** EPITECH PROJECT, 2023
** Day07-Libmy, arguments
** File description:
** Task02 - concatenate two strings
** non-printable characters are printed hexadecimally
*/
#ifndef NO_USE_INTERNAL
    #define NO_USE_INTERNAL

    #define MAX_SPEC_LEN 2
    #include <stdarg.h>

typedef struct {
    size_t written;
    size_t width;
    size_t prec;
} print_info_t;

typedef struct {
    void (*handle)(print_info_t *info);
    char name[MAX_SPEC_LEN];
    type_t type;
} spec_t;

int vdprintf(int fd, const char *restrict format, va_list ap);

#endif
