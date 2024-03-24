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
#endif
