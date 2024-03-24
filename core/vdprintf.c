#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "handlers/converters.h"
#include "internal.h"
#include "my.h"

/**
 * Converstion function pointer table, compacted by substracting the
 * index of the A ascii character to make it more space efficient.
 **/
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

/**
 * Retrieve the index of the next convertion character
 * to printf the format litteral in a single write call.
 **/
const char *print_literal(print_info_t *pinfo, const char *fmt)
{
    const char *s = fmt;

    for (; *fmt != '\0' && *fmt != '%'; fmt++);
    pinfo->written += write(pinfo->fd, s, fmt - s);
    return fmt;
}

/**
 * Tries to print the format in case it is invalid,
 * to minimize side-effects from the undefined behavior.
 **/
static
int print_invalid_format(
    print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    int conv_len = 1;
    const char *p = fmt;

    cinfo->width = 0;
    for (; *p != '%'; --p)
        conv_len++;
    pinfo->buf.written = conv_len;
    for (char *s = pinfo->buf.s; conv_len--; ++p)
        for (*s = *p; !s++;);
    return pinfo->buf.written;
}

/**
 * Setup the conversion and prefix buffer and run the converter to store
 * the translated string.
 *
 * Note: most printf operations appears to output less than about 64 chars,
 * thus we provide a tiny buffer for this use-case.
 * For string that can be arbitrary size, we swap the buffer pointer
 * and set the size accordingly. This require the reset the buffer before
 * running the converter.
 *
 * This implementation allows for a malloc free printf the use a very low
 * amount of bytes within the stack (compared to a 4k buffer), and calls
 * write a reasonable amount of times (the mmore complex a specifier gets, the
 * more write it will use, but the less common it will be anyway).
 **/
static
int run_converter(print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    int jmp = CONV_IDX(*fmt);
    static char buf[64];
    static char prefix[4];
    conv_func_t handler;

    cinfo->conv = *fmt;
    pinfo->buf = (small_buf_t){ buf, 0 };
    cinfo->prefix = (small_buf_t){ prefix, 0 };
    if (*fmt == '%') {
        conv_per(pinfo, cinfo);
        return pinfo->buf.written;
    }
    if (!BOUNDS(*fmt, 'A', 'z'))
        return print_invalid_format(pinfo, cinfo, fmt);
    handler = CONVERSION_FUNCS[jmp];
    if (handler == NULL)
        return print_invalid_format(pinfo, cinfo, fmt);
    handler(pinfo, cinfo);
    return pinfo->buf.written;
}

/**
 * Runs the apprioriate converter to retrieve its buffer,
 * then prints in this order the buffer meating specifier criterias:
 * - left padding (space)
 * - prefix (store sign or base)
 * - zero padding (separated due to case like +01 or 0b001)
 * - conversion (or string pointer accordingly)
 * - right padding
 *
 * Return the amount of character written.
 **/
int print_format(print_info_t *pinfo, conv_info_t *cinfo, const char *fmt)
{
    int written = run_converter(pinfo, cinfo, fmt) + cinfo->prefix.written;
    int pad = cinfo->width - written;

    if (pad > 0 && ~cinfo->flag & F_PAD_LEFT && ~cinfo->flag & F_PAD_ZERO)
        written += putnchar(pinfo->fd, ' ', pad);
    write(pinfo->fd, cinfo->prefix.s, cinfo->prefix.written);
    if (pad > 0 && cinfo->flag & F_PAD_ZERO)
        written += putnchar(pinfo->fd, '0', pad);
    write(pinfo->fd, pinfo->buf.s, pinfo->buf.written);
    if (pad > 0 && cinfo->flag & F_PAD_LEFT)
        written += putnchar(pinfo->fd, ' ', pad);
    return written;
}

/**
 * Convert and prints to file descriptor va_list element
 * according to the format string.
 *
 * For this implementation we used vdprintf as we were not use
 * if we could use FILE * structure to implement fprintf
 * for the core (like the standard showcase).
 **/
int my_vdprintf(int fd, const char *fmt, va_list ap)
{
    print_info_t pinfo = { .written = 0, .fd = fd };
    conv_info_t cinfo = { 0 };

    va_copy(pinfo.ap, ap);
    while (*fmt != '\0') {
        if (*fmt != '%') {
            fmt = print_literal(&pinfo, fmt);
            continue;
        }
        fmt++;
        fmt = parse_specifier(&pinfo, &cinfo, fmt);
        if (fmt == NULL)
            return -1;
        pinfo.written += print_format(&pinfo, &cinfo, fmt);
        fmt++;
    }
    return pinfo.written;
}
