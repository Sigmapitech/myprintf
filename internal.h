/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** internal.h
*/
#ifndef NO_USE_INTERNAL
    #define NO_USE_INTERNAL

    #define MAX_SPEC_LEN 2
    #define CONV_IDX(c) (c - 'A')

    #include <stdarg.h>
    #include <stddef.h>

typedef conv_func_t int (*handle)(int fd)

static
const conv_func_t CONVERSION_FUNCS[ CONV_IDX('z') ] = {
    [ CONV_IDX('c') ] = &print_char,


}

typedef struct {
    int fd;
    size_t written;
    va_list ap;
} print_info_t;

typedef struct {
    size_t width;
    char flag;
    char *len_mod;
    int prec;
} conv_info_t;

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


int conv_char(print_info_t pinfo, conv_info cinfo);
int conv_int(print_info_t pinfo, conv_info cinfo);
int conv_str(print_info_t pinfo, conv_info cinfo);
int conv_ptr(print_info_t pinfo, conv_info cinfo);
int conv_per(print_info_t pinfo, conv_info cinfo);

int conv_oct(print_info_t pinfo, conv_info cinfo);
int conv_hex(print_info_t pinfo, conv_info cinfo);
int conv_uint(print_info_t pinfo, conv_info cinfo);

int conv_nota_sci(print_info_t pinfo, conv_info cinfo);
int conv_nota_dec(print_info_t pinfo, conv_info cinfo);
int conv_nota_var(print_info_t pinfo, conv_info cinfo);
int conv_nota_hex(print_info_t pinfo, conv_info cinfo);

int conv_num(print_info_t pinfo, conv_info cinfo);

#endif
