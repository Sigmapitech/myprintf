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

typedef enum {
    F_NO_FLAG = 0,
    F_PAD_LEFT = 1 << 0,
    F_PAD_ZERO = 1 << 1,
    F_ALT_FORM = 1 << 2,
    F_PUT_SIGN = 1 << 3,
    F_SET_SPACE = 1 << 4,
} flag_t;

typedef enum {
    CONV_NO,        // default
    CONV_CHAR,      // hh
    CONV_SHORT,     // h
    CONV_LONG,      // l
    CONV_LONG_LONG, // ll & q
    CONV_DOUBLE,    // L
    CONV_INTMAX_T,  // j
    CONV_SIZE_T,    // z & z
    CONV_PTDRDIFF_T // t
} len_mod_t;

typedef struct {
    size_t written;
    va_list ap;
    int fd;
} print_info_t;

typedef struct {
    size_t width;
    len_mod_t len_mod;
    char flag;
    int prec;
} conv_info_t;

typedef int (*conv_func_t)(print_info_t *, conv_info_t *);

int putnchar(int fd, char c, int nb);
const char *handle_lookahead(conv_info_t *cinfo, const char *fmt);

int put_nbr(int fd, int nb);

int conv_char(print_info_t *pinfo, conv_info_t *cinfo);
int conv_int(print_info_t *pinfo, conv_info_t *cinfo);
int conv_str(print_info_t *pinfo, conv_info_t *cinfo);
int conv_ptr(print_info_t *pinfo, conv_info_t *cinfo);
int conv_per(print_info_t *pinfo, conv_info_t *cinfo);

int conv_oct(print_info_t *pinfo, conv_info_t *cinfo);
int conv_hex(print_info_t *pinfo, conv_info_t *cinfo);
int conv_uint(print_info_t *pinfo, conv_info_t *cinfo);

int conv_nota_sci(print_info_t *pinfo, conv_info_t *cinfo);
int conv_nota_dec(print_info_t *pinfo, conv_info_t *cinfo);
int conv_nota_var(print_info_t *pinfo, conv_info_t *cinfo);
int conv_nota_hex(print_info_t *pinfo, conv_info_t *cinfo);

int conv_num(print_info_t *pinfo, conv_info_t *cinfo);

static
const conv_func_t CONVERSION_FUNCS[ CONV_IDX('z') ] = {
    [ CONV_IDX('c') ] = &conv_char,
    [ CONV_IDX('d') ] = &conv_int,
    [ CONV_IDX('i') ] = &conv_int,
    [ CONV_IDX('s') ] = &conv_str,
    [ CONV_IDX('p') ] = &conv_ptr,
    [ CONV_IDX('o') ] = &conv_oct,
    [ CONV_IDX('x') ] = &conv_hex,
    [ CONV_IDX('X') ] = &conv_hex,
    [ CONV_IDX('e') ] = &conv_nota_sci,
    [ CONV_IDX('E') ] = &conv_nota_sci,
    [ CONV_IDX('f') ] = &conv_nota_dec,
    [ CONV_IDX('F') ] = &conv_nota_dec,
    [ CONV_IDX('g') ] = &conv_nota_var,
    [ CONV_IDX('G') ] = &conv_nota_var,
    [ CONV_IDX('A') ] = &conv_nota_hex,
    [ CONV_IDX('a') ] = &conv_nota_hex,
    [ CONV_IDX('n') ] = &conv_num
};

#endif
