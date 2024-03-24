#ifndef CONVERTERS_H
    #define CONVERTERS_H

    #include "core/internal.h"

typedef void (*conv_func_t)(print_info_t *, conv_info_t *);

void conv_char(print_info_t *pinfo, conv_info_t *cinfo);
void conv_int(print_info_t *pinfo, conv_info_t *cinfo);
void conv_str(print_info_t *pinfo, conv_info_t *cinfo);
void conv_ptr(print_info_t *pinfo, conv_info_t *cinfo);
void conv_per(print_info_t *pinfo, conv_info_t *cinfo);

void conv_oct(print_info_t *pinfo, conv_info_t *cinfo);
void conv_hex(print_info_t *pinfo, conv_info_t *cinfo);
void conv_uint(print_info_t *pinfo, conv_info_t *cinfo);

void conv_nota_sci(print_info_t *pinfo, conv_info_t *cinfo);
void conv_nota_dec(print_info_t *pinfo, conv_info_t *cinfo);
void conv_nota_var(print_info_t *pinfo, conv_info_t *cinfo);
void conv_nota_hex(print_info_t *pinfo, conv_info_t *cinfo);

void conv_num(print_info_t *pinfo, conv_info_t *cinfo);
void conv_bin(print_info_t *pinfo, conv_info_t *cinfo);

static
const conv_func_t CONVERSION_FUNCS[CONV_IDX('z')] = {
    [CONV_IDX('c')] = &conv_char,
    [CONV_IDX('d')] = &conv_int,
    [CONV_IDX('i')] = &conv_int,
    [CONV_IDX('s')] = &conv_str,
    [CONV_IDX('p')] = &conv_ptr,
    [CONV_IDX('o')] = &conv_oct,
    [CONV_IDX('u')] = &conv_uint,
    [CONV_IDX('x')] = &conv_hex,
    [CONV_IDX('X')] = &conv_hex,
    [CONV_IDX('e')] = &conv_nota_sci,
    [CONV_IDX('E')] = &conv_nota_sci,
    [CONV_IDX('f')] = &conv_nota_dec,
    [CONV_IDX('F')] = &conv_nota_dec,
    [CONV_IDX('g')] = &conv_nota_var,
    [CONV_IDX('G')] = &conv_nota_var,
    [CONV_IDX('A')] = &conv_nota_hex,
    [CONV_IDX('a')] = &conv_nota_hex,
    [CONV_IDX('B')] = &conv_bin,
    [CONV_IDX('b')] = &conv_bin,
    [CONV_IDX('n')] = &conv_num
};

#endif
