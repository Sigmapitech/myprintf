/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** internal.h
*/
#ifndef NO_USE_INTERNAL
    #define NO_USE_INTERNAL

    #define MAX_SPEC_LEN 2

    #include <stdarg.h>
    #include <stddef.h>

union arg_type {
    char c;
    int i;
    void *p;
};

typedef struct {
    size_t written;
    size_t width;
    size_t prec;
    va_list ap;
    union arg_type arg;
} print_info_t;

typedef enum {
    FLAG,
    CONVERSION,
    LENGTH_MODIFIER,
} type_t;

typedef struct {
    void (*handle)(int fd, print_info_t *info);
    char name[MAX_SPEC_LEN];
    type_t type;
} spec_t;
int put_nbr(int fd, int nb);

int vdprintf(int fd, const char *restrict format, va_list ap);

#endif
