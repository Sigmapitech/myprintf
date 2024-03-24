#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#include "internal.h"

intmax_t pop_length_modifier(va_list *ap, len_mod_t lm)
{
    switch (lm) {
        case CONV_LONG:
            return va_arg(*ap, long);
        case CONV_LONG_LONG:
            return va_arg(*ap, long long);
        case CONV_SHORT:
            return (short)va_arg(*ap, int);
        case CONV_CHAR:
            return (char)va_arg(*ap, int);
        case CONV_INTMAX_T:
            return va_arg(*ap, intmax_t);
        case CONV_SIZE_T:
            return va_arg(*ap, size_t);
        case CONV_PTDRDIFF_T:
            return va_arg(*ap, ptrdiff_t);
        default:
            return va_arg(*ap, int);
    }
}

uintmax_t pop_length_modifier_u(va_list *ap, len_mod_t lm)
{
    switch (lm) {
        case CONV_LONG:
            return va_arg(*ap, unsigned long);
        case CONV_LONG_LONG:
            return va_arg(*ap, unsigned long long);
        case CONV_SHORT:
            return (unsigned short)va_arg(*ap, unsigned int);
        case CONV_CHAR:
            return (unsigned char)va_arg(*ap, unsigned int);
        case CONV_INTMAX_T:
            return va_arg(*ap, uintmax_t);
        case CONV_SIZE_T:
            return va_arg(*ap, size_t);
        case CONV_PTDRDIFF_T:
            return va_arg(*ap, ptrdiff_t);
        default:
            return va_arg(*ap, unsigned int);
    }
}
