/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** internal.h
*/
#ifndef NO_USE_INTERNAL
    #define NO_USE_INTERNAL

    #include <stdarg.h>
    #include <stdint.h>
    #include <stddef.h>

    #define MAX_SPEC_LEN 2
    #define CONV_IDX(c) (c - 'A')

typedef struct {
    int sign;
    unsigned long long exponant;
    unsigned long long mentissa;
} dpart_t;

typedef enum {
    F_NO_FLAG = 0,
    F_PAD_LEFT = 1 << 0,
    F_PAD_ZERO = 1 << 1,
    F_ALT_FORM = 1 << 2,
    F_PUT_SIGN = 1 << 3,
    F_SET_SPACE = 1 << 4,
} flag_t;

typedef enum {
    CONV_NO = 0,
    CONV_CHAR = 1,
    CONV_SHORT = 2,
    CONV_LONG_LONG = 3,
    CONV_LONG = 4,
    CONV_INTMAX_T = 5,
    CONV_SIZE_T = 6,
    CONV_DOUBLE = 7,
    CONV_PTDRDIFF_T = 8
} len_mod_t;

typedef struct {
    char cmp[2];
    len_mod_t mod;
} len_mod_comp_t;

typedef struct {
    char *s;
    int written;
} small_buf_t;

typedef struct {
    size_t written;
    va_list ap;
    int fd;
    small_buf_t buf;
} print_info_t;

typedef struct {
    small_buf_t prefix;
    int width;
    int prec;
    char flag;
    char conv;
    len_mod_t len_mod;
} conv_info_t;

typedef int (*conv_func_t)(print_info_t *, conv_info_t *);

int double_to_str(char *out, double d, unsigned int prec);
int putnchar(int fd, char c, int nb);
const char *parse_specifier(conv_info_t *cinfo, const char *fmt);
const char *print_literal(print_info_t *pinfo, const char *fmt);
int print_format(print_info_t *pinfo, conv_info_t *cinfo, const char *fmt);

int put_nbr(int fd, int nb);

intmax_t pop_length_modifier(va_list *ap, len_mod_t lm);
uintmax_t pop_length_modifier_u(va_list *ap, len_mod_t lm);

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
    [ CONV_IDX('u') ] = &conv_uint,
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

static
const len_mod_comp_t LENGTH_MODIFIERS[8] = {
    { "hh", CONV_CHAR },
    { "h", CONV_SHORT },
    { "ll", CONV_LONG_LONG },
    { "l", CONV_LONG },
    { "j", CONV_INTMAX_T },
    { "z", CONV_SIZE_T },
    { "L", CONV_DOUBLE },
    { "t", CONV_PTDRDIFF_T }
};

#endif
