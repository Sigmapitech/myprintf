##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## sources.mk
##
VPATH += .
SRC += vdprintf.c
SRC += printf.c
SRC += utils.c

VPATH += base
SRC += my_intlen.c
SRC += my_putnbr.c
SRC += my_strnlen.c
SRC += my_strncmp.c
SRC += my_stridx.c

VPATH += handlers
SRC += conversion_base.c
SRC += conversion_extra.c
SRC += conversion_float.c
SRC += conversion_numerical.c

VPATH += tests
TSRC += test_setup.c
TSRC += test_conversion_func.c
TSRC += test_parse_hl.c
TSRC += test_parse_hl_width.c
TSRC += test_parse_hl_len_mod.c
TSRC += test_print_literal.c
TSRC += test_my_putnbr.c
TSRC += test_my_strnlen.c
TSRC += test_my_intlen.c
TSRC += test_my_stridx.c
TSRC += test_print_format.c

VPATH += tests/handlers
TSRC += test_handler_char.c
TSRC += test_handler_num.c
TSRC += test_handler_string.c
TSRC += test_handler_percent.c
