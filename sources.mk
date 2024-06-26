VPATH += core
SRC += vdprintf.c
SRC += parse_specifier.c
SRC += pop_length_mod.c
SRC += printf.c
SRC += utils.c

VPATH += base
SRC += my_intlen.c
SRC += my_putnbr.c
SRC += my_putnbr_base.c
SRC += my_stridx.c
SRC += my_strncmp.c
SRC += my_strnlen.c
SRC += my_pow.c

VPATH += handlers
SRC += conversion_base.c
SRC += conversion_extra.c
SRC += conversion_float.c
SRC += conversion_numerical.c

VPATH += float
SRC += double_to_str.c
SRC += stringify_helpers.c
SRC += split_parts.c

VPATH += tests
TSRC += test_double_to_str.c
TSRC += test_double_to_str_sci.c
TSRC += test_my_intlen.c
TSRC += test_my_pow.c
TSRC += test_my_putnbr.c
TSRC += test_my_putnbr_base.c
TSRC += test_my_putnbr_base_16.c
TSRC += test_my_stridx.c
TSRC += test_my_strncmp.c
TSRC += test_my_strnlen.c
TSRC += test_printf.c
TSRC += test_printf_prec_star.c
TSRC += test_setup.c
